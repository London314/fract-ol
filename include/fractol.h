/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omougel <omougel@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 07:18:58 by omougel           #+#    #+#             */
/*   Updated: 2024/03/20 22:01:23 by omougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx_linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\"\
	or \n\t\"./fractol julia <value_1> <value_2>\""

# define WIDTH	800
# define HEIGHT	800

# define BLACK 0x000000
# define WHITE 0xFFFFFF

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pix_ptr;
	int		bpp;
	int		e;
	int		li_len;
}				t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	double	escape_value;
	int		iterations_definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_r;
	double	julia_i;
}				t_fractal;

void		fractal_init(t_fractal *fractal);
double		map(double unscal_num, double new_min, double new_max,
				double old_max);
double		atodbl(char *s);
int			ft_strcmp(const char *s1, const char *s2);
void		ft_putstr_fd(char *s, int fd);
int			ft_isdigit(int c);
size_t		ft_strlen(const char *s);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
void		fractal_render(t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int			key_handler(int keysym, t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			track_julia(int x, int y, t_fractal *fractal);

#endif // !FRACTOL_H
