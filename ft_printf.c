/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 09:38:44 by ndubouil          #+#    #+#             */
/*   Updated: 2018/01/24 14:52:17 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		is_valid_type(char c)
{
	if (c == 's' || c == 'd' || c == 'i' || c == 'c' || c == 'p' || c == 'b' || c == 'o')
		return (1);
	return(0);
}

void	print_types(char c, va_list va, int *i, t_env *env)
{
	if (c == 's')
	{
		env->types.str = va_arg(va, char *);
		ft_putstr(env->types.str);
		env->len += ft_strlen(env->types.str);
	}
	if (c == 'd' || c == 'i')
	{
		env->types.i = va_arg(va, int);
		ft_putnbr(env->types.i);
		env->len += ft_strlen(ft_itoa(env->types.i));
	}
	if (c == 'c')
	{
		env->types.c = (char)va_arg(va, int);
		ft_putchar(env->types.c);
		env->len += 1;
	}
	if (c == 'p')
	{
		env->types.i = va_arg(va, int);
		ft_putstr("0x7fff");
		ft_putstr(ft_itoa_base(env->types.i, 16));
		env->len += ft_strlen(ft_itoa_base(env->types.i, 16));
	}
	if (c == 'b')
	{
		env->types.i = va_arg(va, int);
		ft_putstr(ft_itoa_base(env->types.i, 2));
		env->len += ft_strlen(ft_itoa_base(env->types.i, 2));
	}
	if (c == 'o')
	{
		env->types.i = va_arg(va, int);
		ft_putstr(ft_itoa_base(env->types.i, 8));
		env->len += ft_strlen(ft_itoa_base(env->types.i, 8));
	}
	*i += 1;
}

int		ft_printf(const char *str, ...)
{
	t_env		env;
	int			i;
	va_list		va;
	char		*string;

	va_start(va, str);
	string = (char *)str;
	i = 0;
	env.len = 0;
	while (string[i] != 0)
	{
		if (string[i] != '%')
		{
			ft_putchar(string[i]);
			i++;
			env.len++;
			continue;
		}
		i++;
		//if (is_valid_flag())
		if (is_valid_type(string[i]))
			print_types(string[i], va, &i, &env);
	}
	va_end(va);
	return (env.len);
}
