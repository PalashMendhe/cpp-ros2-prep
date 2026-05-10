#include <iostream>
#include <string>

double calculateAvg(double a, double b, double c);
void printSensorReading(const std::string& sensorName, double value);
double metersToFeet(double meters);

int main(){
    int count = 5;
    double dist = 3.75;
    float angle = 45.0f;
    std::string sensorName = "LIDAR";

    std::cout << "Count: " << count << std::endl;
    std::cout << "Distance: " << dist << " meters" << std::endl;
    std::cout << "Angle: " << angle << " degrees" << std::endl;

    double avg = calculateAvg(10.0, 20.0, 30.0);
    std::cout << "Average: " << avg << std::endl;
    printSensorReading(sensorName, dist);
    printSensorReading("Camera", 0.0);
    double feet = metersToFeet(dist);
    std::cout << dist << " meters is equal to " << feet << " feet." << std::endl;

    return 0;
}
double calculateAvg(double a, double b, double c) {
    return (a + b + c) / 3.0;
}
void printSensorReading(const std::string& sensorName, double value) {
    std::cout << "Sensor: " << sensorName << ", Value: " << value << std::endl;
}

double metersToFeet(double meters) {
    return meters * 3.28084;
}