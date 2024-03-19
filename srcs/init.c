/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omougel <omougel@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:53:42 by omougel           #+#    #+#             */
/*   Updated: 2024/03/19 09:42:33 by omougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}

static void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iterations_definition = 42;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_win, KeyPress, KeyPressMask, key_handler, fractal);
	mlx_hook(fractal->mlx_win, ButtonPress, ButtonPressMask,
		mouse_handler, fractal);
	mlx_hook(fractal->mlx_win, DestroyNotify, StructureNotifyMask,
		close_handler, fractal);
}

void	fractal_init(t_fractal *fract)
{
	fract->mlx = mlx_init();
	if (fract->mlx == NULL)
		malloc_error();
	fract->mlx_win = mlx_new_window(fract->mlx, WIDTH, HEIGHT, fract->name);
	if (fract->mlx_win == NULL)
	{
		mlx_destroy_display(fract->mlx);
		free(fract->mlx);
		malloc_error();
	}
	fract->img.img_ptr = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
	if (fract->img.img_ptr == NULL)
	{
		mlx_destroy_window(fract->mlx, fract->mlx_win);
		mlx_destroy_display(fract->mlx);
		free(fract->mlx);
		malloc_error();
	}
	fract->img.pix_ptr = mlx_get_data_addr(fract->img.img_ptr, &fract->img.bpp,
			&fract->img.li_len, &fract->img.e);
	events_init(fract);
	data_init(fract);
}
