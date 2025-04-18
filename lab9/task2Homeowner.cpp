#include<iostream>
#include<string>
using namespace std;

class SmartDevices {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void getStatus() = 0;
};

class LightBulb : SmartDevices {
protected:
    bool isOn;
    int brightness;

public:
    LightBulb() : isOn(false), brightness(0) {}
    void turnOn() override {
        isOn = true;
    }
    void turnOff() override {
        isOn = false;
    }
    void getStatus() override {
        cout << "Device Name: Light Bulb" << endl
             << "Status: " << (isOn ? "On" : "Off") << endl
             << "Brightness: " << brightness << "%" << endl;
    }
};

class Thermostat : SmartDevices {
protected:
    bool isOn;
    double temperature;

public:
    Thermostat() : isOn(false), temperature(0) {}
    void turnOn() override {
        isOn = true;
    }
    void turnOff() override {
        isOn = false;
    }
    void getStatus() override {
        cout << "Device Name: Thermostat" << endl
             << "Status: " << (isOn ? "On" : "Off") << endl
             << "Temperature: " << temperature << "K" << endl;
    }
};

int main() {
    LightBulb LB;
    Thermostat TS;
    LB.turnOn();
    TS.turnOn();
    cout << endl;
    LB.getStatus();
    cout << endl;
    TS.getStatus();
    cout << endl;
    return 0;
}