#include <iostream>
#include <string>
#include <memory>

class RobotComponent
{
    private:
        std::string name_;
        bool isActive_;
        int updateCount_;
    public:
        RobotComponent(const std::string& name_) : name_(name_), isActive_(false), updateCount_(0) {}
        ~RobotComponent(){
            std::cout << "Destroying RobotComponent: "<< name_ << std::endl;
        }
        void activate(){
            isActive_ = true;
            std::cout << name_ << "Activated" << std:: endl;
        }
        void update(){
            if (isActive_){
                updateCount_++;
                std::cout << name_ << "Updated " << updateCount_ << " times." << std::endl;
            }
        }
        void printStatus(){
            std::cout << "Component: " << name_ << ", Active: " << (isActive_ ? "Yes" : "No") << ", Update Count: " << updateCount_ << std::endl;
        }
};
int main(){
    RobotComponent* arm = new RobotComponent("Arm");
    auto leg = std::make_shared<RobotComponent>("Leg");
    RobotComponent wheel("Wheel");
    
    arm->activate();
    leg->activate();
    wheel.activate();

    for(int i=0; i < 3; i++){
        arm->update();
        leg->update();
        wheel.update();
    }
    arm->printStatus();
    leg->printStatus();
    wheel.printStatus();
    delete arm;
    return 0;
}
//deleting leg will cause memeory leak since it is manage by a shared pointer, it will automatically deallocate memeory whaen it goes out of scope.