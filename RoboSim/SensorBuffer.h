#ifndef SENSOR_BUFFER_H
#define SENSOR_BUFFER_H

#include <cstddef>
#include <deque>

class SensorBuffer {
public:
    explicit SensorBuffer(std::size_t capacity);

    void addReading(double reading);
    double getAverage() const;

private:
    std::size_t capacity_;
    std::deque<double> readings_;
};

#endif // SENSOR_BUFFER_H