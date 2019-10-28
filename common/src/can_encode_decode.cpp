#include "can_encode_decode.h"

Can_Encode_Decode::Can_Encode_Decode()
{
}
Can_Encode_Decode::~Can_Encode_Decode()
{
}

// can encode
void Can_Encode_Decode::encode(uint8_t* frame,
                               const float value,
                               const uint16_t startbit,
                               const uint16_t length,
                               bool is_big_endian,
                               bool is_signed,
                               float factor,
                               float offset)
{
    storeSignal(frame, fromPhysicalValue(value, factor, offset, is_signed), startbit, length, is_big_endian);
}

void Can_Encode_Decode::storeSignal(uint8_t* frame,
                                    uint64_t value,
                                    const uint8_t startbit,
                                    const uint8_t length,
                                    bool is_big_endian)
{
    uint8_t start_byte = startbit / 8;
    uint8_t startbit_in_byte = startbit % 8;
    uint8_t end_byte = 0;
    int8_t count = 0;
    uint8_t current_target_length = (8 - startbit_in_byte);
    uint8_t bits_to_clear = length;

    // Mask the value
    value &= ((0xffffffffffffffff) >> (64 - length));

    // Write bits of startbyte
    clearBits(&frame[start_byte],
              &bits_to_clear,
              startbit_in_byte,
              current_target_length > length ? length : current_target_length);
    frame[start_byte] |= value << startbit_in_byte;
    // printf("start_byte and frame[start_byte] are : %d  %d \n", start_byte, frame[start_byte]);

    // Write residual bytes
    if (is_big_endian)  // Motorola (big endian)
    {
        end_byte = (start_byte * 8 + 8 - startbit_in_byte - length) / 8;

        for (count = start_byte - 1; count >= end_byte; count--)
        {
            clearBits(&frame[count], &bits_to_clear, 0, bits_to_clear >= 8 ? 8 : bits_to_clear);
            frame[count] |= value >> current_target_length;
            current_target_length += 8;
        }
    }
    else  // Intel (little endian)
    {
        end_byte = (startbit + length - 1) / 8;

        for (count = start_byte + 1; count <= end_byte; count++)
        {
            clearBits(&frame[count], &bits_to_clear, 0, bits_to_clear >= 8 ? 8 : bits_to_clear);
            frame[count] |= value >> current_target_length;
            // printf("count and frame[count] are : %d %d \n",count,frame[count]);
            current_target_length += 8;
        }
    }
}

uint64_t Can_Encode_Decode::fromPhysicalValue(float physical_value, float factor, float offset, bool is_signed)
{
    if (is_signed)
    {
        return (int64_t)((physical_value - offset) / factor);
    }
    else
    {
        return (physical_value - offset) / factor;
    }
}

void Can_Encode_Decode::clearBits(uint8_t* target_byte,
                                  uint8_t* bits_to_clear,
                                  const uint8_t startbit,
                                  const uint8_t length)
{
    for (uint8_t i = startbit; i < length + startbit; ++i)
    {
        *target_byte &= ~(1UL << i);
        *bits_to_clear -= 1;
    }
}
// --------------------------------------------------------------------------------------------------
// can decode
std::vector< std::string > Can_Encode_Decode::splitString(const std::string& s)
{
    std::stringstream ss(s.c_str());
    std::string each_s;
    std::vector< std::string > result;
    while (getline(ss, each_s, ' '))
    {
        result.emplace_back(each_s);
    }
    result.erase(std::remove_if(result.begin(), result.end(), [](const std::string& s) { return s.empty(); }),
                 result.end());
    return result;
}

double Can_Encode_Decode::Raw2Physical(std::string filtered_data,
                                       int startbit,
                                       int length,
                                       bool is_big_endian,
                                       bool is_signed,
                                       float factor,
                                       float offset)
{
    std::vector< std::string > data;
    unsigned char buf_data[8];
    if (filtered_data.size() > 0)
    {
        std::vector< std::string > filtered_split_data = splitString(filtered_data);
        for (uint64_t j = 0; j < filtered_split_data.size(); j++)
        {
            data.push_back(filtered_split_data[j]);
        }
        data.erase(data.begin(), data.begin() + 3);
        for (uint64_t i = 0; i < data.size(); i++)
        {
            buf_data[i] = std::stoi(data[i], nullptr, 16);
            // printf("buf_data[i] in : %x \n", buf_data[i]);
        }
    }
    return toPhysicalValue(
        extractSignal(buf_data, startbit, length, is_big_endian, is_signed), factor, offset, is_signed);
}

uint64_t Can_Encode_Decode::extractSignal(const uint8_t* frame,
                                          const uint8_t startbit,
                                          const uint8_t length,
                                          bool is_big_endian,
                                          bool is_signed)
{
    uint8_t start_byte = startbit / 8;
    uint8_t startbit_in_byte = startbit % 8;
    uint8_t current_target_length = (8 - startbit_in_byte);
    uint8_t end_byte = 0;
    int8_t count = 0;

    // Write first bits to target
    uint64_t target = frame[start_byte] >> startbit_in_byte;

    // Write residual bytes
    if (is_big_endian)  // Motorola (big endian)
    {
        end_byte = (start_byte * 8 + 8 - startbit_in_byte - length) / 8;

        for (count = start_byte - 1; count >= end_byte; count--)
        {
            target |= frame[count] << current_target_length;
            current_target_length += 8;
        }
    }
    else  // Intel (little endian)
    {
        end_byte = (startbit + length - 1) / 8;

        for (count = start_byte + 1; count <= end_byte; count++)
        {
            target |= frame[count] << current_target_length;
            current_target_length += 8;
        }
    }

    // Mask value
    target &= ((0xffffffffffffffff) >> (64 - length));

    // perform sign extension
    if (is_signed)
    {
        int64_t msb_sign_mask = 1 << (length - 1);
        target = ((int64_t)target ^ msb_sign_mask) - msb_sign_mask;
    }
    // std::cout << "return target is : " << target << std::endl;
    return target;
}

float Can_Encode_Decode::toPhysicalValue(uint64_t target, float factor, float offset, bool is_signed)
{
    if (is_signed)
    {
        return ((int64_t)target) * factor + offset;
    }
    else
    {
        return target * factor + offset;
    }
}