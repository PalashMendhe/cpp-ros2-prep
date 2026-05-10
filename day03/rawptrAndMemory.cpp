#include <iostream>
#include <string>

int main(){
    double x{ 10.0 };
    double* ptr{ &x }; 
    std::cout << "Value of x: " << x << std::endl; 
    std::cout << "Address of x: " << &x << std::endl;
    {
        double y{ 6.0 };
        ptr = &y;
        std::cout << "Value of y: " << y << std::endl;
    }
    ptr = nullptr;

    double sensorReadings[5] ;
    double *ptr2 = sensorReadings;
    for (int i = 0; i < 5; ++i){
        sensorReadings[i] = i * 1.1; 
        
    }
    for (int i = 0; i < 5; ++i){
        std::cout << "Sensor Reading" << i << ": " << *(ptr2 + i) << std::endl;
    }
    delete[] ptr2; 

    return 0;
}
//dangling pointer : pointer that holds the address of a variable that is no longer valid.
//ptr2 points to stack memory, not heap memory. delete[] will cause undefined behavior.