#include "RobotSimulator.h"
#include <memory>

int main() {
    auto robot = std::make_shared<RobotSimulator>("AMR_01", 5);
    
    // Queue some commands before spinning
    robot->queueCommand({"MOVE", 1.5});
    robot->queueCommand({"ROTATE", 0.785});
    robot->queueCommand({"STOP", 0.0});
    
    robot->spin(10);
    return 0;
}