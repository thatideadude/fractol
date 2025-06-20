#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <unistd.h>
# include <math.h>

# define ERROR_MSG "Error.\n"
# define HEIGHT 800
# define WIDTH	800

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;

typedef struct s_fractal
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	char	*name;
	int		res;
	int		color_offset;
	double	x_offset;
	double	y_offset;
	double	range;
	double	x_julia;
	double	y_julia;
	double	hue;
	int		frame;
	int		shade;
}				t_fractal;

//str_tools
int			ft_ncmp(char *s1, char *s2, int n);
void		put_error(void);
double		atodouble(char *str, int sign, double power);

//math_tools
double		ft_sqrt(double n);
double		scale(double num, double new_min, double new_max, double old_max);

//starters
void		fractal_start(t_fractal *fractal);
void		start_listening(t_fractal *fractal);

//renderers
void		prepare_fractal(t_complex *z, t_complex *c, t_fractal *fractal);
void		render(t_fractal *fractal);
void		render_pixel(int x, int y, t_fractal *fractal);
void		print_pixel(int x, int y, t_img *img, int hue);
void		start_data(t_fractal *fractal);
int			mouse_mov(int x, int y, t_fractal *fractal);
void		render_hue(t_fractal *fractal, t_complex z);

//listeners
int			click_handler(int button, int x, int y, t_fractal *fractal);
int			key_handler(int keysym, t_fractal *fractal);
int			close_win(t_fractal *fractal);

#endif
