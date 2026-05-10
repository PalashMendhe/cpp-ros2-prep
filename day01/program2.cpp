#include <iostream>
#include <string>

struct SensorReading {
    std::string sensorName;
    double value;
    bool isValid;
};

void printReading(SensorReading r);
bool isInRange(SensorReading r, double min, double max);

int main(){
    SensorReading r1{"LIDAR", 3.75, true};
    SensorReading r2{"Camera", 0.0, false};
    SensorReading r3{"Ultrasonic", 1.25, true};

    printReading(r1);
    printReading(r2);
    printReading(r3);

    std::cout << "R1 in range [1.0, 5.0]: " << isInRange(r1, 1.0, 5.0) << std::endl;
    std::cout << "R2 in range [1.0, 5.0]: " << isInRange(r2, 1.0, 5.0) << std::endl;
    std::cout << "R3 in range [1.0, 5.0]: " << isInRange(r3, 1.0, 5.0) << std::endl;
}

void printReading(SensorReading r) {
    std::cout << "Sensor: " << r.sensorName << ", Value: " << r.value 
              << ", Valid: " << (r.isValid ? "Yes" : "No") << std::endl;
}
bool isInRange(SensorReading r, double min, double max) {
    return r.value >= min && r.value <= max;
}
