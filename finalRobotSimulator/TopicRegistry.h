// TopicRegistry.h
#ifndef TOPIC_REGISTRY_H
#define TOPIC_REGISTRY_H

#include <map>
#include <string>
#include <iostream>

class TopicRegistry {
public:
    void set(const std::string& topic, double value);
    double get(const std::string& topic) const;
    bool exists(const std::string& topic) const;
    void printAll() const;

private:
    std::map<std::string, double> data_;
};
#endif