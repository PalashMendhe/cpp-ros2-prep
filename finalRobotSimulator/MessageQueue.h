#ifndef MESSAGE_QUEUE_H
#define MESSAGE_QUEUE_H

#include <cstddef>
#include <queue>
#include <string>

struct Command {
    std::string type;
    double value;
};

class MessageQueue {
public:
    void push(const Command& cmd);
    bool process();
    bool empty() const;
    std::size_t size() const;

private:
    std::queue<Command> queue_;
};

#endif