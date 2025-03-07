#include <iostream>
using namespace std;

class Device {
private:
    int deviceID;
    bool status;

public:
    Device(int id, bool stat) : deviceID(id), status(stat) {}

    virtual void displayDetails() {
        cout << "Device ID: " << deviceID << endl;
        cout << "Status: " << (status ? "On" : "Off") << endl;
    }
};

class SmartPhone : public Device {
private:
    float screenSize;

public:
    SmartPhone(int id, bool stat, float screen) : Device(id, stat), screenSize(screen) {}

    void displayDetails() override {
        Device::displayDetails();
        cout << "Screen Size: " << screenSize << " inches" << endl;
    }
};

class SmartWatch : public Device {
private:
    bool heartRateMonitor;

public:
    SmartWatch(int id, bool stat, bool hrMonitor) : Device(id, stat), heartRateMonitor(hrMonitor) {}

    void displayDetails() override {
        Device::displayDetails();
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Yes" : "No") << endl;
    }
};

class SmartWearable : public Device {
private:
    int stepCounter;

public:
    SmartWearable(int id, bool stat, int steps) : Device(id, stat), stepCounter(steps) {}

    void displayDetails() override {
        Device::displayDetails();
        cout << "Step Counter: " << stepCounter << " steps" << endl;
    }
};

int main() {
    SmartPhone phone(101, true, 6.5);
    SmartWatch watch(102, false, true);
    SmartWearable wearable(103, true, 5000);

    cout << "Smartphone Details: " << endl;
    phone.displayDetails();
    cout << "\nSmartwatch Details: " << endl;;
    watch.displayDetails();
    cout << "\nSmart Wearable Details: " << endl;;
    wearable.displayDetails();

    return 0;
}
