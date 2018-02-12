/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 09:26:20 by ndubouil          #+#    #+#             */
/*   Updated: 2018/02/12 11:26:13 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Width setter
** Take the strings, check if there is a width number and fill struct t_flags
** Work also with * flag
** Return TRUE when finished
*/

int		set_width(char *str, t_env **env)
{
	long long int		i;

	i = 0;
	while (ft_isdigit(str[POS]))
	{
		i = (str[POS] - '0' + i * 10);
		POS++;
	}
	if (str[POS] == '*')
	{
		i = va_arg((*env)->va, int);
		POS++;
	}
	F_WIDTH = i;
	return (TRUE);
}
