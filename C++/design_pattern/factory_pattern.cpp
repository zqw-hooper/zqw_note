#if 0
//**********************简单工厂模式*********************//
// A design without factory pattern
#include <iostream>
using namespace std;

// Library classes
class Vehicle
{
public:
    virtual void printVehicle() = 0;
};

class TwoWheeler : public Vehicle
{
public:
    void printVehicle()
    {
        cout << "I am two wheeler" << endl;
    }
};

class FourWheeler : public Vehicle
{
public:
    void printVehicle()
    {
        cout << "I am four wheeler" << endl;
    }
};

// Client (or user) class
class Client
{
public:
    Client(int type)
    {
        // Client explicitly creates classes according to type
        if (type == 1)
            pVehicle = new TwoWheeler();
        else if (type == 2)
            pVehicle = new FourWheeler();
        else
            pVehicle = NULL;
    }

    ~Client()
    {
        if (pVehicle)
        {
            delete[] pVehicle;
            pVehicle = NULL;
        }
    }

    Vehicle *getVehicle()
    {
        return pVehicle;
    }

private:
    Vehicle *pVehicle;
};

int main(int argc, const char *argv[])
{
    Client *pClient = new Client(1);
    Vehicle *pVehicle = pClient->getVehicle();
    pVehicle->printVehicle();

    return 0;
}
#elif 1

#include <iostream>
using namespace std;

enum VehicleType
{
    VT_TwoWheeler,
    VT_ThreeWheeler,
    VT_FourWheeler
};

// Library classes
class Vehicle
{
public:
    virtual void printVehicle() = 0;
    static Vehicle *Create(VehicleType type);
};
class TwoWheeler : public Vehicle
{
public:
    void printVehicle()
    {
        cout << "I am two wheeler" << endl;
    }
};
class ThreeWheeler : public Vehicle
{
public:
    void printVehicle()
    {
        cout << "I am three wheeler" << endl;
    }
};
class FourWheeler : public Vehicle
{
public:
    void printVehicle()
    {
        cout << "I am four wheeler" << endl;
    }
};

// Factory method to create objects of different types.
// Change is required only in this function to create a new object type
Vehicle *Vehicle::Create(VehicleType type)
{
    if (type == VT_TwoWheeler)
        return new TwoWheeler();
    else if (type == VT_ThreeWheeler)
        return new ThreeWheeler();
    else if (type == VT_FourWheeler)
        return new FourWheeler();
    else
        return NULL;
}

// Client class
class Client
{
public:
    // Client doesn't explicitly create objects
    // but passes type to factory method "Create()"
    Client()
    {
        VehicleType type = VT_ThreeWheeler;
        pVehicle = Vehicle::Create(type);
    }
    ~Client()
    {
        if (pVehicle)
        {
            delete[] pVehicle;
            pVehicle = NULL;
        }
    }
    Vehicle *getVehicle()
    {
        return pVehicle;
    }

private:
    Vehicle *pVehicle;
};

// Driver program
int main()
{
    Client *pClient = new Client();
    Vehicle *pVehicle = pClient->getVehicle();
    pVehicle->printVehicle();
    return 0;
}
#endif
