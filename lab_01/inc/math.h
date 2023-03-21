#ifndef MATH_H
#define MATH_H

#include <cmath>

#define PI M_PI
#define TO_RADIANS(angle) ((angle) * PI / 180)

double get_cos(const double &angle);
double get_sin(const double &angle);

#endif // MATH_H
