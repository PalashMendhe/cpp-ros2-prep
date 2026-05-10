#include "sensor.h"
#include <iostream>

Sensor::Sensor(std::string name, double minRange, double maxRange)
    : name_(std::move(name)), value_(0.0), minRange_(minRange), maxRange_(maxRange), isValid_(false)
{
}

void Sensor::updateReading(double newValue){
    if(newValue < minRange_ || newValue > maxRange_){
        std::cout << "[ERROR] " << name_ << ": reading " 
                  << newValue << " out of range ["
                  << minRange_ << ", " << maxRange_ << "]" << std::endl;
        isValid_ = false;  // flag it, don't change value
        return;
    }
    value_ = newValue;
    isValid_ = true;
}
double Sensor::getReading() const {
    return value_;
}
bool Sensor::isInRange() const {
    return (value_ >= minRange_ && value_ <= maxRange_);
}
void Sensor::printStatus() const {
    if (value_ < 0.0){
        std::cout << "[Error] Invalid Reading: " << name_ << std::endl;
    }
    else if (value_ == 0.0){
        std::cout << "[Warning] Zero reading detected:" << name_ << std::endl;

    }
    else if (value_ > 0.0 && value_ < 2.0){
        std::cout << "[Info] Low reading: " << name_ << std::endl;
    }
    else{
        std::cout << "[Info] Normal reading: " << name_ << std::endl;
    }
}