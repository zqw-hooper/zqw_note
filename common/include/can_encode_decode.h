/**
 * @file common_can_encode_decode.h
 * @brief common_can_encode_decode 头文件
 * @details realize can frame encode and raw data to physical data
 * @mainpage common_can_encode_decode lib
 * @author zhouqingwen
 * @version 1.0.0
 * @date 2019-10-27
 */
#pragma once

#include <assert.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <net/if.h>
#include <unistd.h>
/**
 * @brief common_can_encode_decode function class
 * 解析原始can数据、物理信号封装成can数据
 */
class Can_Encode_Decode
{
  public:
    Can_Encode_Decode();
    ~Can_Encode_Decode();
    /**
     * @brief
     * can封包函数
     * @param frame 目标can帧data域
     * @param value 封包信号
     * @param startbit 信号起始位
     * @param length 信号所占长度
     * @param is_big_endian 信号是否大端，little-intel
     * @param is_signed 信号是否有符号类型
     * @param factor 信号精度
     * @param offset 信号偏移量
     * @return 无
     * @attention 该函数形参一定要与dbc文件信号协议一致
     */
    void encode(uint8_t* frame,
                const float value,
                const uint16_t startbit,
                const uint16_t length,
                bool is_big_endian,
                bool is_signed,
                float factor,
                float offset);
    /**
     * @brief
     * can解包并解析can信号
     * @param filtered_data 过滤的目标can帧
     * @param startbit 信号起始位
     * @param length 信号所占长度
     * @param is_big_endian 信号是否大端，little-intel
     * @param is_signed 信号是否有符号类型
     * @param factor 信号精度
     * @param offset 信号偏移量
     * @return 解析后的真实信号值
     * @attention 该函数形参一定要与dbc文件信号协议一致
     */
    double Raw2Physical(std::string filtered_data,
                        int startbit,
                        int length,
                        bool is_big_endian,
                        bool is_signed,
                        float factor,
                        float offset);

  private:
    /**
     * @brief
     * 根据给定参数将数据依次存入can帧数据域
     * @param frame 目标写入can帧
     * @param value 真实信号值
     * @param startbit 信号起始位
     * @param length 信号所占长度
     * @param is_big_endian 信号是否大端，little-intel
     * @return 无
     * @attention 该函数形参一定要与dbc文件信号协议一致
     */
    void storeSignal(uint8_t* frame, uint64_t value, const uint8_t startbit, const uint8_t length, bool is_big_endian);
    /**
     * @brief
     * 将信号值转换为二进制值
     * @param physical_value 真实信号值
     * @param factor 信号精度
     * @param offset 信号偏移量
     * @param is_signed 信号是否有符号类型
     * @return 无
     * @attention 该函数形参一定要与dbc文件信号协议一致
     */
    uint64_t fromPhysicalValue(float physical_value, float factor, float offset, bool is_signed);
    /**
     * @brief
     * 清空相应位域
     * @param target_byte 目标字节
     * @param bits_to_clear 清空的位域
     * @param startbit 信号起始位
     * @param length 信号长度
     * @return 原始数据
     * @attention 该函数形参一定要与dbc文件信号协议一致
     */
    void clearBits(uint8_t* target_byte, uint8_t* bits_to_clear, const uint8_t startbit, const uint8_t length);
    /**
     * @brief
     * 将原始can帧数据域按字节分解填入列表
     * @param s 从candump获取的can帧
     * @return 无
     * @attention 该函数形参一定要与dbc文件信号协议一致
     */
    std::vector< std::string > splitString(const std::string& s);
    /**
     * @brief
     * 将原始can帧数据解析成真实数据
     * @param target 原始数据
     * @param factor 信号精度
     * @param offset 信号偏移量
     * @param is_signed 信号是否为有符号值
     * @return 解析后真实信号值
     * @attention 该函数形参一定要与dbc文件信号协议一致
     */
    float toPhysicalValue(uint64_t target, float factor, float offset, bool is_signed);
    /**
     * @brief
     * 获取相应位域的原始数据
     * @param frame 原始can帧数据
     * @param startbit 信号起始位
     * @param length 信号长度
     * @param is_big_endian 信号是否为大端
     * @param is_signed 信号是否为有符号
     * @return 解析后真实信号值
     * @attention 该函数形参一定要与dbc文件信号协议一致
     */
    uint64_t extractSignal(const uint8_t* frame,
                           const uint8_t startbit,
                           const uint8_t length,
                           bool is_big_endian,
                           bool is_signed);
};
