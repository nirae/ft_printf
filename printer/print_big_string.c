/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_big_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 20:00:04 by ndubouil          #+#    #+#             */
/*   Updated: 2018/06/20 20:07:01 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		second_case(int c, char result[5])
{
	result[0] = 0xc0 | ((c >> 6) & 0x1f);
	if (MB_CUR_MAX != 1)
	{
		result[1] = 0x80 | (c & 0x3f);
		result[2] = '\0';
	}
	else
		result[1] = '\0';
}

void		third_case(int c, char result[5])
{
	result[0] = 0xe0 | ((c >> 12) & 0x0f);
	if (MB_CUR_MAX != 1)
	{
		result[1] = 0x80 | ((c >> 6) & 0x3f);
		result[2] = 0x80 | (c & 0x3f);
		result[3] = '\0';
	}
	else
		result[1] = '\0';
}

void		fourth_case(int c, char result[5])
{
	result[0] = 0xf0 | ((c >> 18) & 0x07);
	if (MB_CUR_MAX != 1)
	{
		result[1] = 0x80 | ((c >> 12) & 0x3f);
		result[2] = 0x80 | ((c >> 6) & 0x3f);
		result[3] = 0x80 | (c & 0x3f);
		result[4] = '\0';
	}
	else
		result[1] = '\0';
}

void		dispatch_size(t_env *env, int len, char result[5])
{
	if (len == 1)
	{
		result[0] = (unsigned char)env->types.i;
		result[1] = '\0';
	}
	else if (len == 2)
		second_case(env->types.i, result);
	else if (len == 3)
		third_case(env->types.i, result);
	else if (len == 4)
		fourth_case(env->types.i, result);
	else
		env->len = -1;
}

int			take_len(int i)
{
	if (MB_CUR_MAX == 1 && i > 255)
		return (-1);
	else if ((i >= 0 && i <= 0x7f) || MB_CUR_MAX == 1)
		return (1);
	else if (i >= 0x80 && i <= 0x7ff)
		return (2);
	else if (((i >= 0x800 && i <= 0xd7ff) ||
				(i >= 0xe000 && i <= 0xffff)))
		return (3);
	else if (i >= 0x10000 && i <= 0x10ffff)
		return (4);
	else
		return (-1);
}

int			put_big_char()
{
	
}

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

static void		print_string_with_precision(t_env *env, int len)
{
	int				i;

	i = -1;
	if (env->flags.precision >= 0)
	{
		while (++i < env->flags.precision && i < len)
			env->len += putchar_in_buffer(&env->buff, env->types.str[i]);
	}
	else
		env->len += putstr_in_buffer(&env->buff, env->types.str);
}

/*
 ** Printer for flag 's'
 */

int		print_big_string(t_env *env)
{
	char				nullstr[7];
	int					len;

	ft_strcpy(nullstr, "(null)");
	if ((env->types.str = va_arg(env->va, char *)) == NULL)
		env->types.str = nullstr;
	len = ft_strlen(env->types.str);
	if (env->flags.width >= 1)
	{
		if (env->flags.align == RIGHT)
			print_width(env, len);
		print_string_with_precision(env, len);
		if (env->flags.align == LEFT)
			print_width(env, len);
		return (TRUE);
	}
	print_string_with_precision(env, len);
	return (TRUE);
}
