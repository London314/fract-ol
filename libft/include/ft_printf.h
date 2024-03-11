/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omougel <omougel@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:36:13 by omougel           #+#    #+#             */
/*   Updated: 2024/02/14 17:32:38 by omougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *str, ...);
int		ft_strlen_from_i_till_c(const char *str, int i, char c);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putaddress(void *ptr);
void	ft_putnbr(int nb, int *len);
void	ft_putnbr_blen(unsigned int nb, unsigned int b, char *base, int *len);

#endif
