#include<iostream>
#include<vector>
#include<algorithm>

void processSensorData(const std::vector<double>& data, const std::function<double(double)>& predicate);
int main(){
    auto square = [](double x) { return x*x; };
    std::cout << square(5.0) << std::endl;

    double threshold = 10.0;
    auto is_greater = [threshold](double x) { 
        if (x > threshold) {
            return true;
        } else {
            return false;
        }
     };

    auto metersToFeet = [](double meters) { return meters * 3.28084; };
    int count = 0;
    auto counter = [&count]() { count++; };
    counter(); counter(); counter(); counter(); counter();
    std::cout << "Count: " << count << std::endl;

    processSensorData({1.0, 5.0, 10.0, 15.0}, square);
    processSensorData({1.0, 5.0, 10.0, 15.0}, metersToFeet);
    return 0;

}

void processSensorData(const std::vector<double>& data, const std::function<double(double)>& predicate) {
    for (const auto& value : data) {
        std::cout << predicate(value) << " ";
    }
    std::cout << std::endl;
}