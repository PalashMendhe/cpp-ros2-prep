#include <iostream>

#include "MessageQueue.h"

void MessageQueue::push(const Command& cmd) {
    queue_.push(cmd);
}

bool MessageQueue::process() {
    if (queue_.empty()) {
        std::cout << "Empty" << std::endl;
        return false;
    }

    const Command cmd = queue_.front();
    queue_.pop();
    std::cout << "Processing command: " << cmd.type << " with value " << cmd.value << std::endl;
    return true;
}

bool MessageQueue::empty() const {
    return queue_.empty();
}

std::size_t MessageQueue::size() const {
    return queue_.size();
}