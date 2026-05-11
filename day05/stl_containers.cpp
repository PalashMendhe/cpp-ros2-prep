#include<iostream>
#include<vector>
#include<list>

class SensorBuffer{
    std::vector<double> buffer;
    size_t maxSize_;

public:
    SensorBuffer(size_t maxSize) : maxSize_(maxSize) {}

    void addReading(double value) {
    buffer.push_back(value);
    if(buffer.size() > maxSize_) {
        buffer.erase(buffer.begin());
    }
    printAll();
}
void getAverage(){
    double sum = 0.0;
    for(double reading : buffer){
        sum += reading;
    }
    std::cout << sum /buffer.size() << std::endl; 
}

void getLatest(){
    if(!buffer.empty()){
        std::cout << buffer.back() << std::endl;
    }
}
void printAll(){
    for(double reading : buffer){
        std::cout << reading << " ";
    }
    std::cout << std::endl;
}
};

int main(){
    size_t maxSize_ = 5;
    SensorBuffer sensor(maxSize_);
    sensor.addReading(10.5);
    sensor.addReading(12.3);
    sensor.addReading(9.8);
    sensor.addReading(11.0);
    sensor.addReading(13.2);
    sensor.addReading(14.1); 
    sensor.addReading(15.0);
    sensor.addReading(16.5);

    sensor.getAverage();
    sensor.getLatest();
    sensor.printAll();
    return 0;
}

//push_back() used to add elements at the end of the vector
//emplace_back() used to construct elements in place at the end of the vector, avoiding unnecessary copying.