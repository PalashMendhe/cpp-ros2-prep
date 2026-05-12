#include "RobotSimulator.h"
#include <utility>

RobotSimulator::RobotSimulator(std::string name, size_t bufferSize)
    : RobotBase(std::move(name)) {
    sensorBuffer_  = std::make_unique<SensorBuffer>(bufferSize);
    messageQueue_  = std::make_unique<MessageQueue>();
    topicRegistry_ = std::make_shared<TopicRegistry>();
    std::cout << "[INIT] " << name_ << " components created" << std::endl;
}

void RobotSimulator::queueCommand(const Command& cmd) {
    messageQueue_->push(cmd);
}

void RobotSimulator::init() {
    isRunning_ = true;
    std::cout << "[INIT] " << name_ << " ready" << std::endl;
}

void RobotSimulator::update() {
    cycleCount_++;
    
    // Simulate sensor reading
    static double reading = 1.0;
    reading += 0.3;
    
    // Buffer it
    sensorBuffer_->addReading(reading);
    
    // Compute average and store
    double avg = sensorBuffer_->getAverage();
    topicRegistry_->set("/sensor/latest", reading);
    topicRegistry_->set("/sensor/avg", avg);
    
    // Process one command if available
    messageQueue_->process();
    
    // Cycle summary
    std::cout << "Cycle " << cycleCount_ 
              << " | latest=" << reading 
              << " avg=" << avg << std::endl;
}

void RobotSimulator::shutdown() {
    isRunning_ = false;
    std::cout << "[SHUTDOWN] " << name_ << " after " 
              << cycleCount_ << " cycles" << std::endl;
    topicRegistry_->printAll();
}