// MessageQueue.h
#ifndef MESSAGE_QUEUE_H
#define MESSAGE_QUEUE_H

#include <queue>
#include <string>
#include <iostream>

struct Command {
    std::string type;
    double value;
};

class MessageQueue {
public:
    void push(const Command& cmd);
    bool process(); // pops and prints one command, returns false if empty
    bool empty() const;
    size_t size() const;
};

#endif