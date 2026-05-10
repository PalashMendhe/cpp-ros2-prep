#include <iostream>
#include "robot_node.h"

int main(){
    SensorNode mySensor("Lidar", 100.0);
    mySensor.spin(5);
    mySensor.setSensorValue(42.0);
    return 0;

    // Polymorphism — base pointer to derived object
    NodeBase* basePtr = new SensorNode("Camera", 50.0);
    basePtr->spin(3);
    delete basePtr;
}
