/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 09:37:19 by ndubouil          #+#    #+#             */
/*   Updated: 2018/05/28 14:48:02 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Precision setter
** Take the string, check if there is a '.' and number and fill struct t_flags
** Work also with * flag
** Return TRUE when finished or FALSE if no precision found
*/

int		set_precision(char *str, t_env **env)
{
	int		i;

	i = 0;
	if (str[POS] != '.')
	{
		F_PRECISION = -1;
		return (FALSE);
	}
	POS++;
	while (ft_isdigit(str[POS]))
	{
		i = (str[POS] - '0' + i * 10);
		POS++;
	}
	if (str[POS] == '*')
	{
		i = va_arg((*env)->va, int);
		if (i < 0)
			i = -1;
		POS++;
	}
	F_PRECISION = i;
	return (TRUE);
}
