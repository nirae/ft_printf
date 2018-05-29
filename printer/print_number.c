/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 22:17:55 by ndubouil          #+#    #+#             */
/*   Updated: 2018/05/29 19:04:29 by ndubouil         ###   ########.fr       */
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
	if (env->flags.sign == 1 && env->types.str[0] != '-')
		limit--;
	if (env->flags.space && c == '0')
	{
		limit--;
		env->len += putchar_in_buffer(&env->buff, ' ');
	}
	//if (env->flags.precision >= 0 && len > env->flags.precision)
	/*if (env->flags.precision >= 0 && len > env->flags.precision)
		while (++i < env->flags.width - (len - env->flags.precision))
			env->len += putchar_in_buffer(&env->buff, c);
	else
		while (++i < env->flags.width - len)
			env->len += putchar_in_buffer(&env->buff, c);*/
	//ft_putnbr(limit);
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
	if (env->types.str[0] == '-')
	{
		env->len += putchar_in_buffer(&env->buff, '-');
		env->types.str = &env->types.str[1];
		i++;
	}
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
	if (env->flags.size == H)
		env->types.str = ft_lli_itoa_base((short)va_arg(env->va, int), "0123456789");
	else if (env->flags.size == HH)
		env->types.str = ft_lli_itoa_base((char)va_arg(env->va, int), "0123456789");
	else if (env->flags.size == L || env->flags.type == 'D')
		env->types.str = ft_lli_itoa_base(va_arg(env->va, long int), "0123456789");
	else if (env->flags.size == LL)
		env->types.str = ft_lli_itoa_base(va_arg(env->va, long long int), "0123456789");
	else if (env->flags.size == J)
		env->types.str = ft_lli_itoa_base(va_arg(env->va, intmax_t), "0123456789");
	else if (env->flags.size == Z)
		env->types.str = ft_lli_itoa_base(va_arg(env->va, size_t), "0123456789");
	else
		env->types.str = ft_lli_itoa_base(va_arg(env->va, int), "0123456789");
}

/*
**
*/

int		print_number(t_env *env)
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
		if (env->flags.sign && env->types.str[0] != '-')
			env->len += putchar_in_buffer(&env->buff, '+');
		print_string_with_precision(env, len);
		if (env->flags.align == LEFT)
			print_width(env, len, ' ');
		return (TRUE);
	}
	print_string_with_precision(env, len);
	return (TRUE);
}
