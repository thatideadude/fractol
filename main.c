#include "fractol.h"

int main(int argc, char **argv)
{
	if ((argc == 2 && !ft_ncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_ncmp(argv[1], "julia", 5)))
	{
		write(1, "a", 1);
	}
	else 
	{
		put_error();
		exit(1);
	}
}
