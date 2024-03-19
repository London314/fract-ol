/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omougel <omougel@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:39:29 by omougel           #+#    #+#             */
/*   Updated: 2024/03/19 09:40:46 by omougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx, fractal->mlx_win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	else if (keysym == XK_Left)
		fractal->shift_x -= 0.5 * fractal->zoom;
	else if (keysym == XK_Right)
		fractal->shift_x += 0.5 * fractal->zoom;
	else if (keysym == XK_Up)
		fractal->shift_y += 0.5 * fractal->zoom;
	else if (keysym == XK_Down)
		fractal->shift_y -= 0.5 * fractal->zoom;
	else if (keysym == XK_w)
		fractal->iterations_definition += 10;
	else if (keysym == XK_s)
		fractal->iterations_definition -= 10;
	fractal_render(fractal);
	return (0);
}

int	track_julia(int x, int y, t_fractal *fract)
{
	if (!ft_strcmp(fract->name, "julia"))
	{
		fract->julia_r = map(x, -2, 2, WIDTH) * fract->zoom + fract->shift_x;
		fract->julia_i = map(y, 2, -2, HEIGHT) * fract->zoom + fract->shift_y;
	}
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	if (button == Button5)
		fractal->zoom *= 1.05;
	else if (button == Button4)
		fractal->zoom *= 0.95;
	else if (button == Button1)
		track_julia(x, y, fractal);
	fractal_render(fractal);
	return (0);
}
