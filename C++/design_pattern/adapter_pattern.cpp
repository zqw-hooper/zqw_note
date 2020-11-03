#include <cstdio>
class VoltageAdapter;

class Phone
{
public:
    Phone() = default;
    virtual ~Phone() = default;

    VoltageAdapter *adapter;

    void charge();

    void setAdapter(VoltageAdapter* adapter)
    {
        this->adapter = adapter;
    }
    
    static const int V{220};
};

class VoltageAdapter
{
    // 改变电压的功能
public:
    int a;
    void changeVoltage()
    {
        printf("正在充电...\n");
        printf("原始电压： %d\n", Phone::V);
        printf("经过变压器转换之后的电压: %d\n", (Phone::V - 200));
    }
};

void Phone::charge()
{
    this->adapter->changeVoltage();
}

int main(int argc, const char *argv[])
{
    Phone *phone = new Phone();
    VoltageAdapter *adapter = new VoltageAdapter();
    phone->setAdapter(adapter);
    phone->charge();
}