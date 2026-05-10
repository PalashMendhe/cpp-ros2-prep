#include <iostream>
#include <array>

int main(){
    std::array<double, 10> SensorReadings = {0.0, 0.1, 0.9, -2.1, 3.5, -4.0, -5.2, 6.8, 7.3, 8.9};
    int validReadingsCount = 0;
    for (const auto& reading : SensorReadings){

        if ( reading < 0.0 ){
            std::cout << "[Error] Invalid reading: " << reading << std::endl;
            continue;
        }
        else if ( reading == 0.0){
            std::cout << "[warning] zero reading detected" << reading << std::endl;
            validReadingsCount++;
        }
        else if (reading > 0.0 && reading < 2.0)
        {
            std::cout << "[Info] Low reading" << reading <<std::endl;
            validReadingsCount++;
        }
        else{
            std::cout << "[Info] Normal reading: " << reading << std::endl;
            validReadingsCount++;
        }   
    }
    std::cout << "Valid readings count: " << validReadingsCount << std::endl;
    return 0;
}