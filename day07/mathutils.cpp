double clamp(double value, double min, double max) {
    if (value < min) {
        return min;
    } else if (value > max) {
        return max;
    } else {
        return value;
    }
}
double lerp(double a, double b, double t) {
    return a + t * (b - a);
}
double mapRange(double value, double inMin, double inMax, double outMin, double outMax) {
    double t = (value - inMin) / (inMax - inMin);
    return lerp(outMin, outMax, t);
}