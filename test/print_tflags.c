/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tflags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 00:08:34 by ndubouil          #+#    #+#             */
/*   Updated: 2018/06/27 00:10:40 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

/*
**	POUR DEBUG
**	Mettre juste avant l'appel au printer dans la ft_printf.c
*/

void	print_tflags(t_env *env)
{
	printf("alignement : %d\n", env->flags.align);
	printf("signe : %d\n", env->flags.sign);
	printf("zero : %d\n", env->flags.zero);
	printf("espace : %d\n", env->flags.space);
	printf("hash : %d\n", env->flags.hash);
	printf("width : %lld\n", env->flags.width);
	printf("precision : %lld\n", env->flags.precision);
	printf("size : %d\n", env->flags.size);
	printf("type : %c\n", env->flags.type);
}
