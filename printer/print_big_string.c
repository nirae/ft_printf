/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_big_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 20:00:04 by ndubouil          #+#    #+#             */
/*   Updated: 2018/06/24 18:34:27 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static int		ft_wstrlen(wchar_t *str)
{
	int		i;
	int		len;

	i = -1;
	len = 0;
	while (str[++i] != 0)
		len++;
	return (len);
}

static int		ft_bigstrlen(wchar_t *str)
{
	int		i;
	int		len;

	i = -1;
	len = 0;
	while (str[++i] != 0)
	{
		len += take_len(str[i]);
	}
	return (len);
}

static int		print_width(t_env *env, int len)
{
	int				i;
	int				final_preci;

	i = 0;
	final_preci = 0;
	while ((final_preci + take_len(env->types.wstr[i])) < env->flags.precision)
	{
		if (take_len(env->types.wstr[i]) == -1)
		{
			env->len = -1;
			return (FALSE);
		}
		final_preci += take_len(env->types.wstr[i]);
		i++;
	}
	i = -1;
	if (env->flags.precision >= 0 && len > env->flags.precision)
		while (++i < env->flags.width - final_preci)
			env->len += putchar_in_buffer(&env->buff, ' ');
	else
		while (++i < env->flags.width - len)
			env->len += putchar_in_buffer(&env->buff, ' ');
	return (TRUE);
}

static int		print_string_with_precision(t_env *env, int len)
{
	int				i;
	char			result[5];
	int				c_len;
	int				big_len;

	i = -1;
	big_len = 0;
	if (env->flags.precision >= 0)
	{
		while (big_len < env->flags.precision && ++i < len)
		{
			if ((big_len += take_len(env->types.wstr[i])) > env->flags.precision)
			{
				big_len -= take_len(env->types.wstr[i]);
				break;
			}
			if ((c_len = take_big_char(env, env->types.wstr[i], result)) == -1)
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
			if ((c_len = take_big_char(env, env->types.wstr[i], result)) == -1)
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
 ** Printer for flag 'S'
 */

int		print_big_string(t_env *env)
{
	wchar_t				nullwstr[7];
	int					len;
	int					big_len;

	ft_wstrcpy(nullwstr, "(null)");
	if ((env->types.wstr = va_arg(env->va, wchar_t *)) == NULL)
		env->types.wstr = nullwstr;
	len = ft_wstrlen(env->types.wstr);
	big_len = ft_bigstrlen(env->types.wstr);
	if (env->flags.width >= 1)
	{
		if (env->flags.align == RIGHT)
			if (!(print_width(env, big_len)))
				return (FALSE);
		if (!(print_string_with_precision(env, len)))
			return (FALSE);
		if (env->flags.align == LEFT)
			if (!(print_width(env, big_len)))
				return (FALSE);
		return (TRUE);
	}
	if (!(print_string_with_precision(env, len)))
		return (FALSE);
	return (TRUE);
}
