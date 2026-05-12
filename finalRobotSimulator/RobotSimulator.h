#ifndef ROBOT_SIMULATOR_H
#define ROBOT_SIMULATOR_H

#include "RobotBase.h"
#include "sensorBuffer.h"
#include "TopicRegistry.h"
#include "MessageQueue.h"

#include <cstddef>
#include <memory>
#include <string>

class RobotSimulator : public RobotBase {
public:
    RobotSimulator(std::string name, std::size_t bufferSize);
    
    void init() override;
    void update() override;
    void shutdown() override;
    
    void queueCommand(const Command& cmd);

private:
    std::unique_ptr<SensorBuffer> sensorBuffer_;
    std::unique_ptr<MessageQueue> messageQueue_;
    std::shared_ptr<TopicRegistry> topicRegistry_;
    int cycleCount_ = 0;
};

#endif