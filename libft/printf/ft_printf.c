/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omougel <omougel@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:43:11 by omougel           #+#    #+#             */
/*   Updated: 2024/02/14 17:33:40 by omougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_display_params(char c, va_list var, int *return_len, int	*i)
{
	(*i)++;
	if (c == 'c')
		*return_len += ft_putchar(va_arg(var, int));
	else if (c == 's')
		*return_len += ft_putstr(va_arg(var, char *));
	else if (c == 'p')
		*return_len += ft_putaddress(va_arg(var, void *));
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(var, int), return_len);
	else if (c == 'u')
		ft_putnbr_blen(va_arg(var, size_t), 10, "0123456789", return_len);
	else if (c == 'x')
		ft_putnbr_blen(va_arg(var, size_t), 16, "0123456789ABCDEF", return_len);
	else if (c == '\0')
		*return_len = -1;
	else
	{
		*return_len += ft_putchar('%');
		if (c != '%')
			return ;
	}
	if (*return_len != -1)
		(*i)++;
}

int	ft_printf(const char *str, ...)
{
	va_list	var;
	int		i;
	int		return_len;

	i = 0;
	return_len = 0;
	if (!str)
		return (-1);
	va_start(var, str);
	while (str[i])
	{
		if (str[i] == '%')
			ft_display_params(str[i + 1], var, &return_len, &i);
		else
		{
			if (write(1, &str[i], ft_strlen_from_i_till_c(str, i, '%')) != -1)
			{
				return_len += ft_strlen_from_i_till_c(str, i, '%');
				i += ft_strlen_from_i_till_c(str, i, '%');
			}
		}
	}
	va_end(var);
	return (return_len);
}
