#include "fractol.h"

int main(int argc, char **argv)
{
	t_fractal fractal;

	if ((argc == 2 && !ft_ncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_ncmp(argv[1], "julia", 5)))
	{
		fractal.name = argv[1];
		fractal_start(&fractal);
		render(&fractal);
		mlx_loop(fractal.mlx);
	}
	else 
	{
		put_error();
		exit(1);
	}
}
