#include<iostream>
using namespace std;

class Activity {
public:
    virtual double calculateCaloriesBurned() = 0;
};

class Running : public Activity {
protected:
    double distance;
    double time;

public:
    Running(double distance, double time) : distance(distance), time(time) {}
    double calculateCaloriesBurned() {
        return distance * time * 1.036;
    }
};

class Cycling : public Activity {
protected:
    double speed;
    double time;

public:
    Cycling(double speed, double time) : speed(speed), time(time) {}
    double calculateCaloriesBurned() {
        return speed / time * 7.032;
    }
};



int main()
{
    Running R(34.1, 60.2);
    Cycling C(12.1, 56.1);
    cout << endl;
    cout << "Calories burned through Running: " << R.calculateCaloriesBurned() << "J" << endl;
    cout << "Calories burned through Cycling: " << C.calculateCaloriesBurned() << "J" << endl;
    cout << endl;
    return 0;
}