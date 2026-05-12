#include <map>
#include <string>
#include <iostream>
#include "TopicRegistry.h"

void TopicRegistry::set(const std::string& topic, double value) {
    data_[topic] = value;
}
void TopicRegistry::printAll() const {
    std::cout << "Topic Registry Contents:" << std::endl;
    for (const auto& entry : data_) {
        std::cout << "  " << entry.first << ": " << entry.second << std::endl;
    }
}
double TopicRegistry::get(const std::string& topic) const {
    auto it = data_.find(topic);
    if (it != data_.end()) {
        return it->second;
    }
    std::cerr << "[ERROR] Topic '" << topic << "' not found!" << std::endl;
    return 0.0; // or throw an exception
}
bool TopicRegistry::exists(const std::string& topic) const {
    return data_.find(topic) != data_.end();
}