/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 08:12:31 by ndubouil          #+#    #+#             */
/*   Updated: 2018/02/12 09:05:49 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Initialisation of all flags in struct t_flags
**
** By Default :
** 		Align - : right
**		Sign + : false
**		Zero 0 : false
**		Space ' ' : false
**		Hash # : false
**		Width XXX: zero
**		Precision .XXX : zero
**		Size l ll h hh j z none : false
*/

void	init_flags(t_env **env)
{
	F_ALIGN = RIGHT;
	F_SIGN = FALSE;
	F_ZERO = FALSE;
	F_SPACE = FALSE;
	F_HASH = FALSE;
	F_WIDTH = 0;
	F_PRECISION = 0;
	F_SIZE = FALSE;
	F_TYPE = FALSE;
}
