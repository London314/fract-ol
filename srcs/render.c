/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omougel <omougel@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:22:16 by omougel           #+#    #+#             */
/*   Updated: 2024/03/18 22:40:42 by omougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = y * img->line_len + x * (img->bpp / 8);
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	mandel_vs_julia(t_complex z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strcmp(fractal->name, "julia"))
	{
		c->r = fractal->julia_r;
		c->i = fractal->julia_i;
	}
	else
	{
		c->r = z.r;
		c->i = z.i;
	}
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.r = map(x, -2, 2, 0, WIDTH - 1) * fractal->zoom + fractal->shift_x;
	z.i = map(y, 2, -2, 0, HEIGHT - 1) * fractal->zoom + fractal->shift_y;
	i = 0;
	mandel_vs_julia(z, &c, fractal);
	while (i < fractal->iterations_definition)
	{
		z = sum_complex(square_complex(z), c);
		if (z.r * z.r + z.i * z.i > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, 0, fractal->iterations_definition);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractal->img, BLACK);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->mlx_win, fractal->img.img_ptr, 0, 0);
}
