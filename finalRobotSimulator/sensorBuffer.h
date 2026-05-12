#ifndef SENSOR_BUFFER_H
#define SENSOR_BUFFER_H

#include <cstddef>
#include <vector>

class SensorBuffer {
public:
    explicit SensorBuffer(std::size_t maxSize);

    void addReading(double reading);
    double getAverage() const;
    bool empty() const;
    std::size_t size() const;

private:
    std::size_t maxSize_;
    std::vector<double> readings_;
};

#endif // SENSOR_BUFFER_H