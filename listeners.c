#include "fractol.h"

int	close_win(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx, fractal->mlx_win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(1);
}

int key_handler(int keysym, t_fractal *fractal)
{
	printf("keysym: %d\n", keysym);
	if (keysym == XK_Escape)
		return (close_win(fractal));
	if (keysym == XK_Left)
		fractal->x_offset += 0.5 * fractal->range;
	if (keysym == XK_Right)
		fractal->x_offset -= 0.5 * fractal->range;
	if (keysym == XK_Up)
		fractal->y_offset -= 0.5 * fractal->range;
	if (keysym == XK_Down)
		fractal->y_offset += 0.5 * fractal->range;
	if (keysym == XK_z)
		fractal->res *= 2;
	if (keysym == XK_x)
		fractal->res *= 2;
	render(fractal);
}

int click_handler(int button, int x, int y, t_fractal *fractal)
{
	if (button == Button4)
		fractal->range *= 1.05;
	if (button == Button5)
		fractal->range *= 0.95;
	render(fractal);
}
