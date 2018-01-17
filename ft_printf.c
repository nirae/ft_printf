/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 09:38:44 by ndubouil          #+#    #+#             */
/*   Updated: 2018/01/17 14:32:02 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		isconvers(char c)
{
	if (c == 's' || c == 'd')
		return (1);
	return(0);
}

void	conversion(char c, va_list va, int *i, int *len)
{
	char	*str;

	if (c == 's')
	{
		str = va_arg(va, char *);
		ft_putstr(str);
		*len += ft_strlen(str);
	}
	if (c == 'd' || c == 'i')
	{
		ft_putnbr(va_arg(va, int));
		*len += ft_strlen(ft_itoa(va_arg(va, int)));
	}
	*i += 1;
}

int		ft_printf(const char *str, ...)
{
	int			i;
	int			len;
	va_list		va;
	char		*string;

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
			conversion(string[i], va, &i, &len);
	}
	va_end(va);
	return (len);
}
