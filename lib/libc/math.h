#ifndef _MATH_H
#define _MATH_H

#define NAN (0.0/0.0)
#define INFINITY (1.0/0.0)
#define M_PI (3.14159265358979323846)

#define isfinite(x) ((x) == (x) && (x) != INFINITY && (x) != -INFINITY)

double floor(double x);
double fmod(double x, double y);
double fabs(double x);
double cos(double x);
double sin(double x);
double tan(double x);
double sqrt(double x);
double pow(double base, double exponent);

#endif