/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_big_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:06:45 by ndubouil          #+#    #+#             */
/*   Updated: 2018/06/14 20:23:48 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		second_case(int c, char result[4])
{
	result[0] = 0xc0 | ((c >> 6) & 0x1f);
	result[1] = 0x80 | (c & 0x3f);
	result[2] = '\0';
}

void		third_case(int c, char result[4])
{
	result[0] = 0xe0 | ((c >> 12) & 0x0f);
	result[1] = 0x80 | ((c >> 6) & 0x3f);
	result[2] = 0x80 | (c & 0x3f);
	result[3] = '\0';
}
void		fourth_case(int c, char result[4])
{
	result[0] = 0xf0 | ((c >> 18) & 0x07);
	result[1] = 0x80 | ((c >> 12) & 0x3f);
	result[2] = 0x80 | ((c >> 6) & 0x3f);
	result[3] = 0x80 | (c & 0x3f);
}

void		dispatch_size(t_env *env, char result[4])
{
	if (env->types.i >= 0 && env->types.i <= 0x7f)
	{
		result[0] = (unsigned char)env->types.i;
		result[1] = '\0';
	}
	else if (env->types.i >= 0x80 && env->types.i <= 0x7ff)
		second_case(env->types.i, result);	
	else if ((env->types.i >= 0x800 && env->types.i <= 0xd7ff) ||
				(env->types.i >= 0xe000 && env->types.i <= 0xffff))
		third_case(env->types.i, result);	
	else if (env->types.i >= 0x10000 && env->types.i <= 0x10ffff)
		second_case(env->types.i, result);
	else
		env->len = -1;
}

int			take_len(int i)
{
	if (i >= 0 && i <= 0x7f)
		return (1);
	else if (i >= 0x80 && i <= 0x7ff)
		return (2);
	else if ((i >= 0x800 && i <= 0xd7ff) ||
				(i >= 0xe000 && i <= 0xffff))
		return (3);
	else if (i >= 0x10000 && i <= 0x10ffff)
		return (4);
	else
		return (-1);
}

/*
** Printer for flag 'C'
*/

int		print_big_char(t_env *env)
{
	long long int		i;
	char				result[4];
	int					len;

	i = -1;
	env->types.i = va_arg(env->va, int);
	if ((len = take_len(env->types.i)) == -1)
	{
		env->len = -1;
		return (FALSE);
	}
	if (env->types.i == 0)
		env->len++;
	if (env->flags.width > 1)
	{
		if (env->flags.align == RIGHT)
			while (++i < env->flags.width - len)
				env->len += putchar_in_buffer(&env->buff, ' ');
		dispatch_size(env, result);
		env->len += putstr_in_buffer(&env->buff, result);
		if (env->flags.align == LEFT)
			while (++i < env->flags.width - len)
				env->len += putchar_in_buffer(&env->buff, ' ');
		return (TRUE);
	}
	dispatch_size(env, result);
	env->len += putstr_in_buffer(&env->buff, result);
	return (TRUE);
}
