#include <map>
#include <string>
#include <iostream>
#include "TopicRegistry.h"
#include <stdexcept>


void TopicRegistry::set(const std::string& topic, double value){
    data_[topic] = value;
}
double TopicRegistry::get(const std::string& topic) const{
    auto it = data_.find(topic);
    if (it != data_.end()){
        return it->second;
    } else {
        throw std::runtime_error("Topic not found: " + topic);
    }
}

bool TopicRegistry::exists(const std::string& topic) const{
    return data_.find(topic) != data_.end();
}
void TopicRegistry::printAll() const{
    for(const auto& pair : data_){
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}