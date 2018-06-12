/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_number.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:34:01 by ndubouil          #+#    #+#             */
/*   Updated: 2018/06/12 23:31:42 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		print_width(t_env *env, int len, char c)
{
	int				i;
	int				limit;

	i = -1;
	if (env->flags.width <= 0)
		return (0);
	if (env->flags.precision > len)
		len = len + (env->flags.precision - len);
	limit = env->flags.width - len;
	if (c == '0' && env->flags.precision >= 0)
		c = ' ';
	while (++i < limit)
		env->len += putchar_in_buffer(&env->buff, c);
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
	if (env->flags.size == L || env->flags.type == 'U')
		env->types.str = ft_ulli_itoa_base(va_arg(env->va, unsigned long int), "0123456789");
	else if (env->flags.size == H)
		env->types.str = ft_ulli_itoa_base((unsigned short)va_arg(env->va, int), "0123456789");
	else if (env->flags.size == HH)
		env->types.str = ft_ulli_itoa_base((unsigned char)va_arg(env->va, int), "0123456789");
	else if (env->flags.size == LL)
		env->types.str = ft_ulli_itoa_base(va_arg(env->va, unsigned long long int), "0123456789");
	else if (env->flags.size == J)
		env->types.str = ft_ulli_itoa_base(va_arg(env->va, uintmax_t), "0123456789");
	else if (env->flags.size == Z)
		env->types.str = ft_ulli_itoa_base((unsigned long long)va_arg(env->va, unsigned long long int), "0123456789");
	else
		env->types.str = ft_ulli_itoa_base(va_arg(env->va, unsigned int), "0123456789");
}

/*
**
*/

int		print_unsigned_number(t_env *env)
{
	int					len;

	get_number(env);
	len = ft_strlen(env->types.str);
	if (env->flags.width >= 0)
	{
		if (env->flags.align == RIGHT)
		{
			if (env->flags.zero && env->flags.precision <= len)
			{
				print_width(env, len, '0');
			}
			else
				print_width(env, len, ' ');
		}
		print_string_with_precision(env, len);
		if (env->flags.align == LEFT)
			print_width(env, len, ' ');
		return (TRUE);
	}
	print_string_with_precision(env, len);
	return (TRUE);
}
