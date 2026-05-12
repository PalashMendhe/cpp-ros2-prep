#include "RobotSimulator.h"
#include <iostream>
#include <memory>
#include <utility>

RobotSimulator::RobotSimulator(std::string name, std::size_t bufferSize)
    : RobotBase(std::move(name)),
      sensorBuffer_(std::make_unique<SensorBuffer>(bufferSize)),
      messageQueue_(std::make_unique<MessageQueue>()),
      topicRegistry_(std::make_shared<TopicRegistry>())
{
}

void RobotSimulator::init() {
    std::cout << "Initializing Robot Simulator: " << getName() << std::endl;
    isRunning_ = true;
    cycleCount_ = 0;
}

void RobotSimulator::update() {
    static double simulatedReading = 1.0;
    simulatedReading += 0.3;

    sensorBuffer_->addReading(simulatedReading);
    const double avg = sensorBuffer_->getAverage();

    topicRegistry_->set("/sensor/avg", avg);
    topicRegistry_->set("/sensor/latest", simulatedReading);

    messageQueue_->process();

    std::cout << "Cycle " << cycleCount_ << ": latest=" << simulatedReading
              << " avg=" << avg << std::endl;
    ++cycleCount_;
}

void RobotSimulator::shutdown() {
    std::cout << "Shutting down Robot Simulator: " << getName() << std::endl;
    isRunning_ = false;
}

void RobotSimulator::queueCommand(const Command& cmd) {
    messageQueue_->push(cmd);
}
