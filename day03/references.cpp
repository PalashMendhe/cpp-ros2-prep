// passing by value = copy of parameter is made and used in function
// passing by reference = reference to original parameter is passed to function
// passing by pointer = address of original parameter is passed to function

#include <iostream>
#include <string>

void scaleReading(double& value, double factor){
    value *= factor;
}
void scaleReadingPtr(double* value, double factor){
    *value *= factor;
}
void printReading(const double& value){
    std::cout << "The reading is: " << value << std::endl;
}
int main(){
    double reading = 10.0;
    double factor = 2.0;
    std::cout << "Original reading: " << reading << std::endl;
    scaleReading(reading, factor);
    std::cout << "Scaled reading (by reference): " << reading << std::endl;
    reading = 10.0; // Reset reading
    scaleReadingPtr(&reading, factor);
    std::cout << "Scaled reading (by pointer): " << reading << std::endl;
    printReading(reading);
    return 0;
}