/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 09:12:18 by ndubouil          #+#    #+#             */
/*   Updated: 2018/02/12 09:18:39 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Size setter
** Take the string, check if there is a valid flag and fill struct t_flags
** Work with h hh l ll j z
** Return TRUE when finished or FALSE if no flags found
*/

int		set_size(char *str, t_env **env)
{
	if (!is_valid_sizeflag(str[POS]))
		return (FALSE);
	if (str[POS] == 'h')
		F_SIZE = H;
	else if (str[POS] == 'l')
		F_SIZE = L;
	else if (str[POS] == 'j')
		F_SIZE = J;
	else if (str[POS] == 'z')
		F_SIZE = Z;
	POS++;
	if (F_SIZE == H && str[POS] == 'h')
	{
		F_SIZE = HH;
		POS++;
	}
	else if (F_SIZE == L && str[POS] == 'l')
	{
		F_SIZE = LL;
		POS++;
	}
	return (TRUE);
}
