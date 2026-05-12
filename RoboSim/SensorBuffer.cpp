#include "SensorBuffer.h"

SensorBuffer::SensorBuffer(std::size_t capacity)
    : capacity_(capacity) {}

void SensorBuffer::addReading(double reading) {
    if (capacity_ == 0) {
        return;
    }

    if (readings_.size() == capacity_) {
        readings_.pop_front();
    }

    readings_.push_back(reading);
}

double SensorBuffer::getAverage() const {
    if (readings_.empty()) {
        return 0.0;
    }

    double sum = 0.0;
    for (double reading : readings_) {
        sum += reading;
    }

    return sum / static_cast<double>(readings_.size());
}