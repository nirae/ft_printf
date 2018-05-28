/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 19:54:58 by ndubouil          #+#    #+#             */
/*   Updated: 2018/05/29 00:05:01 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*static void		print_width(t_env *env, int len)
{
	int				i;

	i = -1;
	if (env->flags.precision >= 0 && len > env->flags.precision)
		while (++i < env->flags.width - env->flags.precision)
			env->len += putchar_in_buffer(&env->buff, ' ');
	else
		while (++i < env->flags.width - len)
			env->len += putchar_in_buffer(&env->buff, ' ');
}*/

/*
** Printer for flag 'p'
*/

int		print_address(t_env *env)
{
	int			i;

	i = -1;
	env->types.ulli = (unsigned long long int)va_arg(env->va, void *);
	if (env->flags.width > 1)
	{
		if (env->flags.align == RIGHT)
			while (++i < env->flags.width - 1)
				env->len += putchar_in_buffer(&env->buff, ' ');
		env->len += putstr_in_buffer(&env->buff, "0x");
		env->len += putstr_in_buffer(&env->buff, ft_lli_itoa_base(env->types.ulli, 16));
		if (env->flags.align == LEFT)
			while (++i < env->flags.width - 1)
				env->len += putchar_in_buffer(&env->buff, ' ');
		return (TRUE);
	}
	env->len += putstr_in_buffer(&env->buff, "0x");
	env->len += putstr_in_buffer(&env->buff, ft_itoa_base(env->types.i, 16));
	return (TRUE);
}
