#include <iostream>
#include <functional>
#include <string>
#include <map>
#include <optional>
#include <vector>

std::pair<double, double> getMinMax(const std::vector<double>& data) {
    double minVal = data[0];
    double maxVal = data[0];
    for (const auto& val : data) {
        if (val < minVal) minVal = val;
        if (val > maxVal) maxVal = val;
    }
    return {minVal, maxVal};
}


std::optional<double> getSensorReading(const std::vector<double>& data, int index) {
    if (index < 0 || index >= data.size()) {
        return std::nullopt;
    }
    return data[index];
}
int main(){
    std::map<std::string, double > sensorTopics = {
        {"/lidar", 0.5},
        {"/camera", 1.0},
        {"/radar", 1.5},
        {"/gps", 2.0},
        {"/imu", 2.5}
    };
    std::vector<double> readings;
    for (const auto& [topic, value] : sensorTopics) {
        readings.push_back(value);
    }
    auto [minVal, maxVal] = getMinMax(readings);

    getSensorReading(readings, 2).has_value() ? std::cout << getSensorReading(readings, 2).value() << std::endl : std::cout << "Invalid index" << std::endl;
    getSensorReading(readings, 5).has_value() ? std::cout << getSensorReading(readings, 5).value() << std::endl : std::cout << "Invalid index" << std::endl;

    std::cout << "Min: " << minVal << ", Max: " << maxVal << std::endl;
    return 0;
}