#ifndef MATHUTILS_H
#define MATHUTILS_H

double clamp(double value, double min, double max);
double lerp(double a, double b, double t);
double mapRange(double value, double inMin, double inMax, 
                double outMin, double outMax);

#endif