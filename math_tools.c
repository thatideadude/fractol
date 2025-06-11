#include "fractol.h"

double	scale(double num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * num / old_max + new_min);
}
