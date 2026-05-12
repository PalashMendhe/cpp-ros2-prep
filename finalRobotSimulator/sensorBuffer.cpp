#include "sensorBuffer.h"

#include <numeric>

SensorBuffer::SensorBuffer(std::size_t maxSize)
    : maxSize_(maxSize)
{
}

void SensorBuffer::addReading(double reading) {
    if (maxSize_ == 0) {
        return;
    }

    if (readings_.size() >= maxSize_) {
        readings_.erase(readings_.begin());
    }

    readings_.push_back(reading);
}

double SensorBuffer::getAverage() const {
    if (readings_.empty()) {
        return 0.0;
    }

    const double sum = std::accumulate(readings_.begin(), readings_.end(), 0.0);
    return sum / static_cast<double>(readings_.size());
}

bool SensorBuffer::empty() const {
    return readings_.empty();
}

std::size_t SensorBuffer::size() const {
    return readings_.size();
}