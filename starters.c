#include "fractol.h"
#include <X11/X.h>

static void	malloc_err(void)
{
	perror("Malloc failed./n");
	exit(EXIT_FAILURE);
}

void	start_listeners(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_win, KeyPress, KeyPressMask, key_handler, fractal);
	mlx_hook(fractal->mlx_win, ButtonPress, ButtonPressMask, click_handler, fractal);
	mlx_hook(fractal->mlx_win, DestroyNotify, StructureNotifyMask, close_win, fractal);
	mlx_hook(fractal->mlx_win, MotionNotify, PointerMotionMask, mouse_mov, fractal);
}

void    start_data(t_fractal *fractal)
{
    fractal->res = 100;
    fractal->x_offset = 0.0;
    fractal->y_offset = 0.0;
    fractal->img.bpp = 0;
	fractal->img.img_ptr = 0;
	fractal->img.pixels_ptr = 0;
    fractal->img.endian = 0;
    fractal->img.line_len = 0;
	fractal->range = 1.0;
	fractal->hue = 0xffffff;
}

void	fractal_start(t_fractal *fractal)
{
	start_data(fractal);
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
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr, &fractal->img.bpp, 
												&fractal->img.line_len, &fractal->img.endian);
	start_listeners(fractal);
}
