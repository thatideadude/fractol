#include "fractol.h"

double	scale(double num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * num / old_max + new_min);
}

double sin (double x){
    int i = 1;
    double cur = x;
    double acc = 1;
    double fact= 1;
    double pow = x;
    while (fabs(acc) > .00000001 &&   i < 100){
        fact *= ((2*i)*(2*i+1));
        pow *= -1 * x*x; 
        acc =  pow / fact;
        cur += acc;
        i++;
    }
    return cur;
}

double pow_custom(double base, int exp)
{
    double result = 1.0;
    for (int i = 0; i < exp; ++i)
        result *= base;
    return result;
}
double pow2(double x)
{
    // Approximate 2^x using Taylor expansion for small x
    // You could use a more accurate method, but this is simple:
    double result = 1.0;
    double term = 1.0;
    int i;
    for (i = 1; i < 20; i++) {
        term *= x * 0.69314718056 / i; // ln(2) ≈ 0.693...
        result += term;
    }
    return result;
}

double log_approx(double x)
{
    // Approximate natural log using Newton's method
    if (x <= 0.0)
        return -1e9;

    double y = x - 1;
    double result = 0.0;
    for (int i = 1; i <= 20; i++) {
        double term = (i % 2 == 1 ? 1 : -1) * pow_custom(y, i) / i;
        result += term;
    }
    return result;
}



double ft_log2(double x)
{
    if (x <= 0.0)
        return -1e9; // error value for invalid input

    double y = 1.0; // initial guess
    int i = 0;
    while (i++ < 20)
    {
        y = y - (pow2(y) - x) / (pow2(y) * log_approx(2.0));
    }
    return y;
}
