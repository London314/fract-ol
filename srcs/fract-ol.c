/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omougel <omougel@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 07:21:11 by omougel           #+#    #+#             */
/*   Updated: 2024/03/11 15:59:55 by omougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract-ol.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	close_win(int keysym, t_vars *vars)
{
	printf("%d\n", keysym);
	if (keysym == XK_Escape)
	{
		if (vars->mlx && vars->win)
			mlx_destroy_window(vars->mlx, vars->win);
		if (vars->mlx)
		{
			mlx_destroy_display(vars->mlx);
			free(vars->mlx);
		}
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello World ! 42");
	printf("mlx:%p, win:%p\n", vars.mlx, vars.win);
	mlx_key_hook(vars.mlx, &close_win, &vars);
	mlx_loop(vars.mlx);
	//close_win(&vars);
}
