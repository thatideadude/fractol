#include "fractol.h"

void	print_pixel(int x, int y, t_img *img, int hue)
{
	int offset;

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

void paint_fractal(t_complex z, t_fractal *fractal, int x, int y)
{
	double	mag;
	int		shade;

	mag = ft_sqrt(z.x * z.x + z.y * z.y);
	shade = (int)(mag * 100) + fractal->color_offset % 256;
	fractal->hue = (shade * shade * shade * shade * shade * shade * shade * 10 << 4) | ((shade - 0x00ffaf) / 100 << 8) | (shade * shade * shade * shade * shade) << 16;
	if (fractal->color_offset > 1)
		print_pixel(x, y, &fractal->img, 0xffffff / shade);
	else
		print_pixel(x, y, &fractal->img, fractal->hue * fractal->color_offset);
}

void paint_background(int x, int y, t_fractal *fractal, int r)
{
	double	norm_x;
	double	norm_y;
	double	dist;
	int		g;
	int		b;

	norm_x = (double)x / WIDTH;
	norm_y = (double)y / HEIGHT;
	dist = ft_sqrt((norm_x - 0.5) * (norm_x - 0.5) + (norm_y - 0.5) * (norm_y - 0.5));
	if (dist > 1.0)
		dist = 1.0;
	r = 250;
	g = 233 + (int)(dist * 9);
	b = 232 + (int)(dist * 10);
	if (g > 255)
		g = 255 - fractal->color_offset;
	if (b > 255)
		b = 255 - fractal->color_offset;
	fractal->hue = (r << 16) | (g << 8) | b;
}

void render_pixel(int x, int y, t_fractal *fractal)
{
    t_complex z;
    t_complex c;
    t_complex z2;
    int i;

    z.x = (scale(x, -2, 2, WIDTH) * fractal->range) + fractal->x_offset;
    z.y = (scale(y, 2, -2, HEIGHT) * fractal->range) + fractal->y_offset;
    prepare_fractal(&z, &c, fractal);
    i = -1;
    while (++i < fractal->res)
    {
        z2.x = z.x * z.x;
        z2.y = z.y * z.y;
        if (z2.x + z2.y > 4.0)
        {
			fractal->hue = (100 + (i * 256)) / fractal->color_offset % 256;
			fractal->hue = (((int)((fractal->hue * 0.0005 + 255 * 0.9995)) << 16) 
				| (((int)((fractal->hue * 0.0005 + 255 * 0.9995)) << 8))
				| (((int)((fractal->hue * 0.0005 + 255 * 0.9995) + fractal->color_offset) << 4)));
			paint_background(x, y, fractal, 0);
			if (fractal->color_offset > 1)
            	print_pixel(x, y, &fractal->img, (int) fractal->hue * fractal->color_offset % 0xf0f0);
			else
            	print_pixel(x, y, &fractal->img, (int) fractal->hue);
            return;
        }
        z.y = 2 * z.x * z.y + c.y;
        z.x = z2.x - z2.y + c.x;
    }
	paint_fractal(z, fractal, x, y);
}

void	render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			render_pixel(x, y, fractal);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->mlx_win, fractal->img.img_ptr, 0, 0);
}
