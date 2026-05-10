#include <iostream>
#include "sensor.h"

int main(){
    Sensor tempSensor("Temperature", -40.0, 125.0);
    tempSensor.updateReading(25.5);
    tempSensor.printStatus();

    tempSensor.updateReading(-50.0);
    tempSensor.printStatus();

    tempSensor.updateReading(0.0); 
    tempSensor.printStatus();

    tempSensor.updateReading(1.5); 
    tempSensor.printStatus();

    tempSensor.updateReading(30.0); 
    tempSensor.printStatus();



    Sensor pressureSensor("Pressure", 0.0, 200.0);
    pressureSensor.updateReading(150.0);
    pressureSensor.printStatus();

    Sensor humiditySensor("Humidity", 0.0, 100.0);
    humiditySensor.updateReading(45.0);
    humiditySensor.printStatus();
    return 0;
}