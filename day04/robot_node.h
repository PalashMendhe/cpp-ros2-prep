#ifndef ROBOT_NODE_H
#define ROBOT_NODE_H

#include <string>
#include <iostream>

// Base class — simulates rclcpp::Node
class NodeBase {
public:
    NodeBase(std::string name);
    virtual ~NodeBase();
    
    std::string getName() const;
    virtual void initialize() = 0;  // pure virtual — must override
    virtual void update() = 0;      // pure virtual — must override
    void spin(int cycles);          // not virtual — same for all nodes

protected:
    std::string nodeName_;
    bool isRunning_;
};

// Derived class — simulates your actual ROS 2 node
class SensorNode : public NodeBase {
public:
    SensorNode(std::string name, double sensorRange);
    
    void initialize() override;
    void update() override;
    void setSensorValue(double value);

private:
    double sensorRange_;
    double currentValue_;
    int cycleCount_;
};

#endif