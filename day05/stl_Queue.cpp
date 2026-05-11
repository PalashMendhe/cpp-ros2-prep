#include<queue>
#include<iostream>

struct RosMessage{
    std::string topic;
    double value;
    int timestamp;

};
std::queue<RosMessage> messageQueue;

void publishMessage(std::queue<RosMessage>& messageQueue, std::string topic, double value, int timestamp) {
    RosMessage msg{topic, value, timestamp};
    messageQueue.push(msg);
}
void processMessages(std::queue<RosMessage>& messageQueue){
    while (!messageQueue.empty()){
        RosMessage msg = messageQueue.front();
        std::cout << "Processing message from topic: " << msg.topic << ", value: " << msg.value << ", timestamp: " << msg.timestamp << std::endl;
        messageQueue.pop();
    }
}
int main(){
    publishMessage(messageQueue, "/scan", 1.5, 1001);
    publishMessage(messageQueue, "/odom", 0.5, 1002);
    publishMessage(messageQueue, "/imu", 0.8, 1003);
    publishMessage(messageQueue, "/cmd_vel", 0.2, 1004);
    publishMessage(messageQueue, "/battery", 0.9, 1005);

    processMessages(messageQueue);

    return 0;
}

//vector stores elements contiguously in memory, for fast acces of elemnts by index.
//map vs unordered map time complexity: map-> O(log n) and unordered mao -> O(1). use map when you need sorted order of keys, and unordered map when you need faster access and don't care about order.
//don't know