#include <iostream>
using namespace std;
#if 0
enum ControlMethod
{
    kLQR = 0,
    kMPC = 1
};

class ControlBase
{
public:
    ControlBase() {}
    ~ControlBase() {}

    virtual void run() = 0;
};

class LQR : public ControlBase
{
public:
    LQR(){}
    ~LQR(){}

    void run() override
    {
        cout << "in LQR run" << endl;
    }
};

class MPC : public ControlBase
{
public:
    MPC(){}
    ~MPC(){}

    void run() override
    {
        cout << "in MPC run" << endl;
    }
};

class ControlAgent
{
public:
    ControlAgent(ControlMethod method) :method_(method){}
    ~ControlAgent() {}

    ControlBase* create()
    {
        switch (method_)
        {
        case ControlMethod::kLQR:
            return new LQR();
            break;
        case ControlMethod::kMPC:
            return new MPC();
            break;
        default:
            break;
        }
    }

private:
    ControlBase* control;
    ControlMethod method_;
};

int main()
{
    ControlAgent ca(ControlMethod::kMPC);
    ControlBase* control = ca.create();
    control->run();
    return 0;
}
#elif 1

#include <mutex>
mutex mu;

class Singlton
{
public:
    ~Singlton() {}
    static Singlton *getSinglton()
    {
        if (instance == nullptr)
        {
            unique_lock<mutex> lck(mu);
            if (instance == nullptr)
            {
                instance = new Singlton();
            }
        }
        return instance;
    }
    static Singlton *instance;

private:
    Singlton() { cout << "ctor of Singlton " << endl; }
};

Singlton *Singlton::instance = nullptr;

int main()
{
    Singlton *pobj1 = Singlton::getSinglton();
    Singlton *pobj2 = Singlton::getSinglton();

    if (pobj1 == pobj2)
    {
        printf("two objects equate!\n");
    }
    return 0;
}
#endif