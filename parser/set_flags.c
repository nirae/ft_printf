/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 08:37:23 by ndubouil          #+#    #+#             */
/*   Updated: 2018/02/12 09:46:25 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Flags setter
**
** Take the string, check until flags don't match and fill struct t_flags
** Work with flags '-' '+' '0' ' ' '#'
** Return TRUE when finished
*/

int		set_flags(char *str, t_env **env)
{
	if (!is_valid_flags(str[POS]))
		return (TRUE);
	// DEBUG
	//printf("flag : %c\n", str[POS]);
	if (str[POS] == '-')
	{
		F_ALIGN = LEFT;
		F_ZERO = FALSE;
	}
	if (str[POS] == '+')
	{
		F_SIGN = TRUE;
		F_SPACE = FALSE;
	}
	if (str[POS] == '0' && F_ALIGN != LEFT)
		F_ZERO = TRUE;
	if (str[POS] == ' ' && !F_SIGN)
		F_SPACE = TRUE;
	F_HASH = (str[POS] == '#') ? TRUE : FALSE;
	POS++;
	return (set_flags(str, env));
}
