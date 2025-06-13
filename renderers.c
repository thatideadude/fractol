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
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
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
			fractal->hue = (40 + (i * 4)) % 256;
			fractal->hue = (((int)(fractal->hue * 0.4 + 255 * 0.6) << 16) 
				| (int)(fractal->hue * 0.2 + 255 * 0.8) << 8 
				| (int)(fractal->hue * 0.4 + 255 * 0.6));
            	//fractal->hue = ((100 + (i * 4)) % 256 << 16) | (100 + (i * 4)) % 256 << 16 
						// | (100 + (i * 4)) % 256;
            	print_pixel(x, y, &fractal->img, fractal->hue);
            return;
        }
        z.y = 2 * z.x * z.y + c.y;
        z.x = z2.x - z2.y + c.x;
    }
	print_pixel(x, y, &fractal->img, 0xa500050);
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
