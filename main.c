#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && !ft_ncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_ncmp(argv[1], "julia", 5)))
	{
		fractal.name = argv[1];
		if (!ft_ncmp(argv[1], "julia", 5))
		{
			fractal.x_julia = atodouble(argv[2], 1, 1);
			fractal.y_julia = atodouble(argv[3], 1, 1);
		}
		fractal_start(&fractal);
		render(&fractal);
		mlx_loop(fractal.mlx);
	}
	else
	{
		put_error();
		exit(EXIT_SUCCESS);
	}
	return (0);
}
