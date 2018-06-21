/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_big_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 20:00:04 by ndubouil          #+#    #+#             */
/*   Updated: 2018/06/21 21:19:37 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		print_width(t_env *env, int len)
{
	int				i;

	i = -1;
	if (env->flags.precision >= 0 && len > env->flags.precision)
		while (++i < env->flags.width - env->flags.precision)
			env->len += putchar_in_buffer(&env->buff, ' ');
	else
		while (++i < env->flags.width - len)
			env->len += putchar_in_buffer(&env->buff, ' ');
}

static int		print_string_with_precision(t_env *env, int len)
{
	int				i;
	char			result[5];
	int				c_len;

	i = -1;
	if (env->flags.precision >= 0)
	{
		while (++i < env->flags.precision && i < len)
		{
			if ((c_len = take_big_char(env, env->types.str[i], result)) == -1)
			{
				env->len = -1;
				return (FALSE);
			}
			env->len += putstr_in_buffer(&env->buff, result);
		}
	}
	else
	{
		while (++i < len)
		{
			if ((c_len = take_big_char(env, env->types.str[i], result)) == -1)
			{
				env->len = -1;
				return (FALSE);
			}
			env->len += putstr_in_buffer(&env->buff, result);
		}
	}
	return (TRUE);
}

/*
 ** Printer for flag 's'
 */

#include <stdio.h>

int		print_big_string(t_env *env)
{
	char				nullstr[7];
	int					len;

	ft_strcpy(nullstr, "(null)");
	if ((env->types.str = va_arg(env->va, char *)) == NULL)
		env->types.str = nullstr;
	len = ft_strlen(env->types.str);
	printf("LEN = %d\n", len);
	if (env->flags.width >= 1)
	{
		if (env->flags.align == RIGHT)
			print_width(env, len);
		if (!(print_string_with_precision(env, len)))
			return (FALSE);
		if (env->flags.align == LEFT)
			print_width(env, len);
		return (TRUE);
	}
	if (!(print_string_with_precision(env, len)))
		return (FALSE);
	return (TRUE);
}
