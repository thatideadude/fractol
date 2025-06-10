#include "fractol.h"

void	print_pixel(int x, int y, t_img *img, int hue)
{
	int offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = hue;
}
void	render_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			hue;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;  
	c.x = scale(x, -2, +2, WIDTH) + fractal->x_offset;
	c.y = scale(y, +2, -2, HEIGHT) + fractal->y_offset;

	while (i < fractal->res)
	{
		z = sum(square(z), c) ;
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			hue = scale(i,  0xffdfff, 0xffafff, fractal->res);
			print_pixel(x, y, &fractal->img, hue);
			return ;
		}
		++i;
		
	}
	print_pixel(x, y, &fractal->img, 0xafffaf);
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
