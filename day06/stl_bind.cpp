#include <functional>
#include <iostream>
#include <string>

class RobotController {
public:
    RobotController(std::string name) : name_(name), speed_(0.0) {}
    
    void setSpeed(double speed) {
        speed_ = speed;
        std::cout << name_ << " speed set to: " << speed_ << std::endl;
    }
    
    void processReading(std::string source, double value) {
        std::cout << name_ << " received from " << source 
                  << ": " << value << std::endl;
    }
    
    double getSpeed() const { return speed_; }

private:
    std::string name_;
    double speed_;
};
int main(){
    RobotController controller("Robo1");

    std::function<void()> setSpeedFunc = std::bind(&RobotController::setSpeed, &controller, 1.5);
    setSpeedFunc();
    setSpeedFunc();
    setSpeedFunc();
    std::function<void(double)> processReadng= std::bind(&RobotController::processReading, &controller, "/lidar", std::placeholders:: _1);
    processReadng(0.5);
    processReadng(1.0);
    processReadng(1.5);
    return 0;
}
//What does &RobotController::setSpeed mean — why & and the class name
//&RobotController::setSpeed is a pointer to the member function setSpeed of the RobotController class. The & symbol indicates that we are taking the address of the member function, and RobotController::setSpeed specifies which member function we are referring to. This allows us to create a callable object that can be invoked later, in this case using std::bind to bind the member function to a specific instance of the class (controller