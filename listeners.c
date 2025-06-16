#include "fractol.h"

int	close_win(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx, fractal->mlx_win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(1);
}
int trip_stop(t_fractal *fractal)
{
		fractal->color_offset = 1;
		render(fractal);
	return (0);
}
int trip_start(t_fractal *fractal)
{
		fractal->color_offset = (fractal->color_offset + 10) % 256;
		render(fractal);
	return (0);
}

int key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		return (close_win(fractal));
	if (keysym == XK_Left)
		fractal->x_offset -= 0.5 * fractal->range;
	if (keysym == XK_Right)
		fractal->x_offset += 0.5 * fractal->range;
	if (keysym == XK_Up)
		fractal->y_offset += 0.5 * fractal->range;
	if (keysym == XK_Down)
		fractal->y_offset -= 0.5 * fractal->range;
	if (keysym == XK_z)
		fractal->range *= 1.05;
	if (keysym == XK_x)
		fractal->range *= 0.95;  
	if (keysym == XK_c)
		mlx_loop_hook(fractal->mlx, trip_start, fractal);
	if (keysym == XK_v)
		mlx_loop_hook(fractal->mlx, trip_stop, fractal);
	render(fractal);
	return (0);
}

int click_handler(int button, int x, int y, t_fractal *fractal)
{
	double mouse_re = scale(x, -2, 2, WIDTH) * fractal->range + fractal->x_offset;
	double mouse_im = scale(y, 2, -2, HEIGHT) * fractal->range + fractal->y_offset;

	if (button == Button4)
		fractal->range *= 0.95;
	else if (button == Button5)
		fractal->range *= 1.05;
	else
		return (0);

	double new_range = fractal->range;

	fractal->x_offset = mouse_re - scale(x, -2, 2, WIDTH) * new_range;
	fractal->y_offset = mouse_im - scale(y, 2, -2, HEIGHT) * new_range;

	render(fractal);
	return (0);
}
