#include "fractol.h"

void	print_pixel(int x, int y, t_img *img, int hue)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = hue;
}

void	prepare_fractal(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_ncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->x_julia;
		c->y = fractal->y_julia;
	}
	else if (!ft_ncmp(fractal->name, "mandelbrot", 10))
	{
		c->x = z->x;
		c->y = z->y;
	}
}

void	render_hue(t_fractal *fractal, t_complex z)
{
	double	mag;
	int		shade;

	shade = fractal->shade;
	mag = ft_sqrt(z.x * z.x + z.y * z.y);
	fractal->shade = (int)(mag * 100) + fractal->color_offset % 256;
	fractal->hue = (shade * shade * shade
			* shade * shade * shade * shade * 10 << 4)
		| ((shade - 0x00ffaf) / 100 << 8)
		| (shade * shade * shade * shade * shade) << 16;
}
