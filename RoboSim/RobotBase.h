#ifndef ROBOT_BASE_H
#define ROBOT_BASE_H

#include <string>
#include <iostream>

class RobotBase {
public:
    RobotBase(std::string name) : name_(name) {}
    virtual ~RobotBase() {}
    
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void shutdown() = 0;
    
    std::string getName() const { return name_; }
    
    void spin(int cycles) {
        init();
        for (int i = 0; i < cycles; ++i) update();
        shutdown();
    }

protected:
    std::string name_;
    bool isRunning_ = false;
};

#endif