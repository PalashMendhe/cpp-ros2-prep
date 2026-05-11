#include <iostream>
#include <map>

void updateTopicData(std::map<std::string, double>& topicData, const std::string& name, double value) {
    topicData[name] = value;
}
void printAllTopics(const std::map<std::string, double>& topicData) {
    for (const auto& pair : topicData) {
        std::cout << "Topic: " << pair.first << ", Value: " << pair.second << std::endl;
    }
}
void topicExists(const std::map<std::string, double>& topicData, const std::string& name) {
    if (topicData.find(name) != topicData.end()) {
        std::cout << "Topic exists: " << name << std::endl;
    } else {
        std::cout << "Topic does not exist: " << name << std::endl;
    }
}

int main(){
    std::map<std::string, double> topicData;
    updateTopicData(topicData, "/scan", 1.5);
    updateTopicData(topicData, "/odom", 0.5);
    updateTopicData(topicData, "/imu", 0.8);
    updateTopicData(topicData, "/cmd_vel", 0.2);
    updateTopicData(topicData, "/battery", 0.9);
    printAllTopics(topicData);
    topicExists(topicData, "/scan");
    topicExists(topicData, "/nonexistent");

    return 0;
}