#include<iostream>
#include<cmath>
#include<algorithm>
#include "mathutils.h"


int main(){
    double clampedValue = clamp(5.5, 0.0, 10.0);
    std::cout << "Clamped Value: " << clampedValue << std::endl;
    double lerpedValue = lerp(2.0, 8.0, 0.25);
    std::cout << "Lerped Value: " << lerpedValue << std::endl;
    double mappedValue = mapRange(5.0, 0.0, 10.0, 100.0, 200.0);
    std::cout << "Mapped Value: " << mappedValue << std::endl;
    return 0;
}