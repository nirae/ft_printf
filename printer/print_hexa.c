/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 00:39:59 by ndubouil          #+#    #+#             */
/*   Updated: 2018/06/05 00:10:55 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		print_width(t_env *env, int len, char c)
{
	int				i;
	int				limit;

	i = -1;
	
	if ((c == '0' && env->flags.precision < 0) || env->flags.width <= 0)
	{
		if (env->flags.hash && (ft_strcmp("0", env->types.str) != 0 || env->flags.precision > 1))
		{
			if (env->flags.type == 'X')
				env->len += putstr_in_buffer(&env->buff, "0X");
			else
				env->len += putstr_in_buffer(&env->buff, "0x");
		}
	}
	if (env->flags.width <= 0)
		return (0);
	if (env->flags.precision > len)
		len = len + (env->flags.precision - len);
	if (ft_strcmp("0", env->types.str) == 0 && env->flags.precision == 0)
		limit = env->flags.width;
	else
		limit = env->flags.width - len;
	if (env->flags.hash && ft_strcmp("0", env->types.str) != 0)
		limit -= 2;
	if (c == '0' && env->flags.precision >= 0)
		c = ' ';
	if (env->flags.space && c == '0')
	{
		limit--;
		env->len += putchar_in_buffer(&env->buff, ' ');
	}
	while (++i < limit)
		env->len += putchar_in_buffer(&env->buff, c);
	if (c != '0')
	{
		if (env->flags.hash && (ft_strcmp("0", env->types.str) != 0 || env->flags.precision > 1))
		{
			if (env->flags.type == 'X')
				env->len += putstr_in_buffer(&env->buff, "0X");
			else
				env->len += putstr_in_buffer(&env->buff, "0x");
		}
	}
	return (1);
}

static int		print_string_with_precision(t_env *env, int len)
{
	int				i;
	
	i = (env->flags.precision - len);
	if ((ft_strcmp(env->types.str, "0") == 0) && env->flags.precision == 0)
		return (0);
	if (env->flags.precision > len)
	{
		while (i > 0)
		{
			env->len += putchar_in_buffer(&env->buff, '0');
			i--;
		}
	}
	env->len += putstr_in_buffer(&env->buff, env->types.str);
	return (0);
}

static void		get_number(t_env *env)
{
	char	ref[16];

	if (env->flags.type == 'X')
		ft_strcpy(ref, "0123456789ABCDEF");
	else
		ft_strcpy(ref, "0123456789abcdef");
	if (env->flags.size == H)
		env->types.str = ft_ulli_itoa_base((unsigned short)va_arg(env->va, int), ref);
	else if (env->flags.size == HH)
		env->types.str = ft_ulli_itoa_base((unsigned char)va_arg(env->va, int), ref);
	else if (env->flags.size == L || env->flags.type == 'O')
		env->types.str = ft_ulli_itoa_base(va_arg(env->va, unsigned long int), ref);
	else if (env->flags.size == LL)
		env->types.str = ft_ulli_itoa_base(va_arg(env->va, unsigned long long int), ref);
	else if (env->flags.size == J)
		env->types.str = ft_ulli_itoa_base(va_arg(env->va, uintmax_t), ref);
	else if (env->flags.size == Z)
		env->types.str = ft_ulli_itoa_base((unsigned long long)va_arg(env->va, unsigned long long int), ref);
	else
		env->types.str = ft_ulli_itoa_base(va_arg(env->va, unsigned int), ref);
}

/*
**
*/

int		print_hexa(t_env *env)
{
	int					len;

	get_number(env);
	len = ft_strlen(env->types.str);
		if (env->flags.align == RIGHT)
		{
			if (env->flags.zero && env->flags.precision <= len)
			{
				if (env->types.str[0] == '-')
				{
					env->len += putchar_in_buffer(&env->buff, '-');
					env->types.str = &env->types.str[1];
				}
				print_width(env, len, '0');
			}
			else
				print_width(env, len, ' ');
		}
		if (env->flags.space && !env->flags.sign && !env->flags.width)
			env->len += putchar_in_buffer(&env->buff, ' ');
		print_string_with_precision(env, len);
		if (env->flags.align == LEFT)
			print_width(env, len, ' ');
		return (TRUE);
	return (TRUE);
}
