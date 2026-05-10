#include <iostream>
#include "robot_node.h"

NodeBase::NodeBase(std::string name) 
    : nodeName_(name), isRunning_(false) {
    std::cout << "[INIT] " << nodeName_ << " created" << std::endl;
}
NodeBase::~NodeBase(){
    std::cout << "Destroying NodeBase: " << nodeName_ << std::endl;
}
std::string NodeBase::getName() const {
    return nodeName_;
}

SensorNode::SensorNode(std::string name, double sensorRange) :NodeBase(name), sensorRange_(sensorRange), currentValue_(0.0), cycleCount_(0){
    std::cout << "[INIT] SensorNode Created: " << nodeName_ << " with range " << sensorRange_ << std::endl;
}
void SensorNode::initialize(){
    std::cout << "Initializing SensorNode: " << nodeName_ << std::endl;
    isRunning_ = true;
}
void SensorNode::update(){
    if (isRunning_){
        cycleCount_++;
        std::cout << "Current Value :" << currentValue_ << std::endl;
    }
}
void SensorNode::setSensorValue(double value){
    currentValue_ = value;
    std::cout << "Sensor value updated to: " << currentValue_ << std::endl;
}
void NodeBase::spin(int cycles) {
    initialize();
    for (int i = 0; i < cycles; i++) {
        update();
    }
}