#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include "minilibx-linux/mlx.h"
# include <math.h>
# include <unistd.h>

typedef struct	s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;

typedef struct	s_fractal
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
}				t_fractal;

//str_tools
int		ft_ncmp(char *s1, char *s2, int n);
void	put_error(void);

# define ERROR_MSG "Invalid input.\nPlease type \"./fractol mandelbrot\" or \"./fractol julia <value> <value>\"\n"

#endif
