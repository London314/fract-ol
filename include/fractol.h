/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omougel <omougel@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 07:18:58 by omougel           #+#    #+#             */
/*   Updated: 2024/03/18 22:57:46 by omougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/include/libft.h"
# include "../mlx_linux/mlx.h"
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\"\
	or \n\t\"./fractol julia <value_1> <value_2>\""

# define WIDTH	800
# define HEIGHT	800

#define BLACK       0x000000  // RGB(0, 0, 0)
#define WHITE       0xFFFFFF  // RGB(255, 255, 255)
#define RED         0xFF0000  // RGB(255, 0, 0)
#define GREEN       0x00FF00  // RGB(0, 255, 0)
#define BLUE        0x0000FF  // RGB(0, 0, 255)
#define YELLOW      0xFFFF00
#define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
#define LIME_SHOCK      0xCCFF00  // A blinding lime
#define NEON_ORANGE     0xFF6600  // A blazing neon orange
#define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
#define AQUA_DREAM      0x33CCCC  // A bright turquoise
#define HOT_PINK        0xFF66B2  // As the name suggests!
#define ELECTRIC_BLUE   0x0066FF  // A radiant blue
#define LAVA_RED        0xFF3300  // A bright, molten red

typedef struct s_complex
{
	double	r;
	double	i;
} t_complex;

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

void	fractal_init(t_fractal *fractal);
double	map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
double	atodbl(char *s);
t_complex sum_complex(t_complex z1, t_complex z2);
t_complex square_complex(t_complex z);
void	fractal_render(t_fractal *fractal);
int  close_handler(t_fractal *fractal);
int	key_handler(int	keysym, t_fractal *fractal);
int	mouse_handler(int button, int x, int y, t_fractal *fractal);
int	track_julia(int x, int y, t_fractal *fractal);

#endif // !FRACTOL_H
