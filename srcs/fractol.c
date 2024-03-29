/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omougel <omougel@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:43:30 by omougel           #+#    #+#             */
/*   Updated: 2024/03/21 07:06:47 by omougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && !ft_strcmp(argv[1], "mandelbrot"))
		|| (argc == 4 && !ft_strcmp(argv[1], "julia")))
	{
		fractal.name = argv[1];
		if (!ft_strcmp(argv[1], "julia"))
		{
			fractal.julia_r = atodbl(argv[2]);
			fractal.julia_i = atodbl(argv[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
