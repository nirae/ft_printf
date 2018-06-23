/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_big_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:06:45 by ndubouil          #+#    #+#             */
/*   Updated: 2018/06/23 02:09:00 by ndubouil         ###   ########.fr       */
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



void		dispatch_size(t_env *env, int c, int len, char result[5])
{
	if (len == 1)
	{
		result[0] = (unsigned char)c;
		result[1] = '\0';
	}
	else if (len == 2)
		second_case(c, result);	
	else if (len == 3)
		third_case(c, result);	
	else if (len == 4)
		fourth_case(c, result);
	else
		env->len = -1;
}

int			take_len(int i)
{
	if ((MB_CUR_MAX == 1 && i > 255) || (i > 0xD7FF && i < 0xE000))
		return (-1);
	if ((i >= 0 && i <= 0x7f) || MB_CUR_MAX == 1)
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

int		take_big_char(t_env *env, int c, char result[5])
{
	int		len;
	
	if ((len = take_len(c)) == -1)
		return (-1);
	dispatch_size(env, c, len, result);
	return (len);
}

/*
** Printer for flag 'C'
*/
#include <stdio.h>
int		print_big_char(t_env *env)
{
	long long int		i;
	char				result[5];
	int					len;

	i = -1;
	env->types.i = va_arg(env->va, int);
	if ((len = take_big_char(env, env->types.i, result)) == -1)
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
		//dispatch_size(env, len, result);
		env->len += putstr_in_buffer(&env->buff, result);
		if (env->flags.align == LEFT)
			while (++i < env->flags.width - len)
				env->len += putchar_in_buffer(&env->buff, ' ');
		//print_buffer(&env->buff);	
		return (TRUE);
	}
	//dispatch_size(env, len, result);
	env->len += putstr_in_buffer(&env->buff, result);
	return (TRUE);
}
