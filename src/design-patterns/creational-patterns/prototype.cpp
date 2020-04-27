#include <iostream>
#include <string>
using namespace std;

// Default Classes
class Device
{
public:
    ~Device(){};
    virtual void send(string data) = 0;
    virtual void setSpeed(int value) = 0;
    virtual int getSpeed() = 0;
};

class Bluetooth : public Device
{
public:
    Bluetooth() {}
    ~Bluetooth() {}
    void setSpeed(int value)
    {
        speed = value;
    }

    int getSpeed()
    {
        return speed;
    }

    void send(string data)
    {
        cout << "Sent By Bluetooth: " << data << " Speed: " << speed << endl;
    }
    int speed;
};

class Wifi : public Device
{
public:
    Wifi() {}
    ~Wifi() {}
    void setSpeed(int value)
    {
        speed = value;
    }

    int getSpeed()
    {
        return speed;
    }

    void send(string data)
    {
        cout << "Sent By Wifi: " << data << " Speed: " << speed << endl;
    }
    int speed;
};

/* Prototype Started
 * Problem: Slone the old object
 * Solution: Clone function
 */
class Prototype
{
public:
    Prototype() {}
    ~Prototype() {}
    virtual Device *clone(Device *oldOneObject) = 0;
};

class BluetoothPrototype : public Prototype
{
public:
    BluetoothPrototype() {}
    ~BluetoothPrototype() {}
    Device *clone(Device *oldOneObject)
    {
        Device *newOneObject = new Bluetooth();
        newOneObject->setSpeed(oldOneObject->getSpeed());
        return newOneObject;
    }
};

int main()
{
    Device *bluetoothObject = new Bluetooth();
    bluetoothObject->setSpeed(20);
    bluetoothObject->send("First object");

    Prototype *prototypeObject = new BluetoothPrototype;
    Device* cloneBluetoothObject = prototypeObject->clone(bluetoothObject);
    cloneBluetoothObject->send("Clone object crated");

    delete bluetoothObject;
    delete prototypeObject;
    return 0;
}