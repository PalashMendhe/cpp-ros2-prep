#ifndef ROBOT_SIMULATOR_H
#define ROBOT_SIMULATOR_H

#include "RobotBase.h"
#include "SensorBuffer.h"
#include "TopicRegistry.h"
#include "MessageQueue.h"
#include <memory>

class RobotSimulator : public RobotBase {
    public:
        RobotSimulator(std::string name, size_t buffersize);
        void init() override;
        void update() override;
        void shutdown() override;

        void queueCommand(const Command& cmd);
    private:
        std::unique_ptr<SensorBuffer> sensorBuffer_;
        std::shared_ptr<TopicRegistry> topicRegistry_;
        std::unique_ptr<MessageQueue> messageQueue_;
        int cycleCount_ = 0;
};

#endif