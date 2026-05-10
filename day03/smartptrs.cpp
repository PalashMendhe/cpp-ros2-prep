#include <iostream>
#include <string>
#include <memory>
#include "sensor.h"

void testSensor();
void use_count();

int main(){
    use_count();
    std::shared_ptr<Sensor> sensorPtr1 = std::make_shared<Sensor>("Temperature Sensor", 25.0, 100.0);
    testSensor();
    use_count();
    return 0;
}

void testSensor(){
    std::shared_ptr<Sensor> sensorPtr1 = std::make_shared<Sensor>("temperature sensor", 25.0, 100.0);
    sensorPtr1 -> updateReading(30.0);
    sensorPtr1 -> printStatus();

}
void use_count(){
    std::shared_ptr<Sensor> sensorPtr1 = std::make_shared<Sensor>("temperature sensor", 25.0, 100.0);
    std::cout << "Use count: " << sensorPtr1.use_count() << std::endl; 
    {
        std::shared_ptr<Sensor> sensorPtr2 = sensorPtr1; 
        std::cout << "Use count after creating sensorPtr2: " << sensorPtr1.use_count() << std::endl; 
    }
    std::cout << "Use count after sensorPtr2 goes out of scope: " << sensorPtr1.use_count() << std::endl; 
}