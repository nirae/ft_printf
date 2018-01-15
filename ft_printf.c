/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 09:38:44 by ndubouil          #+#    #+#             */
/*   Updated: 2018/01/15 17:21:20 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		isconvers(char c)
{
	if (c == 's' || c == 'd')
		return (1);
	return(0);
}

int		ft_printf(const char *str, ...)
{
	int			i;
	int			len;
	va_list		va;
	char		*string;
	char		*p;

	va_start(va, str);
	string = (char *)str;
	i = 0;
	len = 0;
	while (string[i] != 0)
	{
		if (string[i] != '%')
		{
			ft_putchar(string[i]);
			i++;
			continue;
		}
		i++;
		if (isconvers(string[i]))
		{
			p = va_arg(va, char *);
			ft_putstr(p);
			i++;
		}
	}
	va_end(va);
	return (len);
}
