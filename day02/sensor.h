#ifndef SENSOR_H
#define SENSOR_H

#include <string>

// Declaration only — no implementation here
struct SensorData {
    std::string name;
    double value;
    bool isValid_;
};

class Sensor {
public:
    Sensor(std::string name, double minRange, double maxRange);
    
    void updateReading(double newValue);
    double getReading() const;
    bool isInRange() const;
    void printStatus() const;

private:
    std::string name_;
    double value_;
    double minRange_;
    double maxRange_;
    bool isValid_;
};

#endif // SENSOR_H