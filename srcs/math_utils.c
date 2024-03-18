/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omougel <omougel@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:29:12 by omougel           #+#    #+#             */
/*   Updated: 2024/03/18 11:19:27 by omougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double	map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
	return ((new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min);
}

t_complex sum_complex(t_complex z1, t_complex z2)
{
	t_complex result;

	result.r = z1.r + z2.r;
	result.i = z1.i + z2.i;
	return (result);
}

t_complex square_complex(t_complex z)
{
	t_complex result;

	result.r = z.r * z.r - z.i * z.i;
	result.i = 2 * z.r * z.i;
	return (result);
}
