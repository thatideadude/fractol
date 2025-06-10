#include "fractol.h"
# include "minilibx-linux/mlx.h"

static void	malloc_err(void)
{
	perror("Malloc failled./n");
	exit(1);
}

void	start_listeners(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_win, KeyPress, KeyPressMask, key_handler, fractal);
//	mlx_hook(fractal->mlx_win, ButtonPress, ButtonPressMask, mouse_handler, fractal);
//	mlx_hook(fractal->mlx_win, DestroyNotify, DestroyNotifyMask, close_handler, fractal);
}

void	start_data(t_fractal *fractal)
{
	fractal->res = 256;
	fractal->x_offset = 0.0;
	fractal->y_offset = 0.0;
}

void	fractal_start(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		malloc_err();
	fractal->mlx_win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, fractal->name);
	if (!fractal->mlx_win)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		malloc_err();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->img.img_ptr)
	{
		mlx_destroy_display(fractal->mlx);
		mlx_destroy_window(fractal->mlx, fractal->mlx_win);
		free(fractal->mlx);
		malloc_err();
	}
	start_data(fractal);
	start_listeners(fractal);
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr, &fractal->img.bpp, 
												&fractal->img.line_len, &fractal->img.endian);
}
