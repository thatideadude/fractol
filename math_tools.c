#include "fractol.h"

double	ft_sqrt(double n)
{
	double	guess;
	double	epsilon;

	guess = n / 2.0;
	epsilon = 0.00001;
	if (n <= 0)
		return (0);
	while ((guess * guess - n) > epsilon || (n - guess * guess) > epsilon)
		guess = (guess + n / guess) / 2.0;
	return (guess);
}

double	scale(double num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * num / old_max + new_min);
}
