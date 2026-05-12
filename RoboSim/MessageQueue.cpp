#include <queue>
#include <string>
#include <iostream>
#include "MessageQueue.h"

namespace {
std::queue<Command> commands_;
}

void MessageQueue::push(const Command& cmd){
    commands_.push(cmd);
}

bool MessageQueue::process(){
    if (commands_.empty()){
        return false;
    }
    else{
        Command cmd = commands_.front();
        std::cout << "Processing command: " << cmd.type << " with value " << cmd.value << std::endl;
        commands_.pop();
        return true;
    }
}
bool MessageQueue::empty() const {
    return commands_.empty();
}
size_t MessageQueue::size() const {
    return commands_.size();
}