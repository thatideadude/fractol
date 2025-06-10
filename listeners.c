#include "fractol.h"

int	close_win(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx, fractal->mlx_win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(0);
}

int key_handler(int keysym, t_fractal *fractal)
{
	printf("keysym: %d\n", keysym);
	if (keysym == XK_Escape)
		close_win(fractal);
	if (keysym == XK_Left)
		fractal->x_offset += 0.5;
	if (keysym == XK_Right)
		fractal->x_offset -= 0.5;
	if (keysym == XK_Up)
		fractal->y_offset -= 0.5;
	if (keysym == XK_Down)
		fractal->y_offset += 0.5;
	if (keysym == XK_z)
		fractal->res += 128;
	if (keysym == XK_x)
		fractal->res -= 128;
	render(fractal);
}
