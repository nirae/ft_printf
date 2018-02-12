/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 10:51:16 by ndubouil          #+#    #+#             */
/*   Updated: 2018/02/12 14:13:21 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Printer for flag 'c'
** Return TRUE if OK or FALSE if malloc failed
*/

int		print_char(t_env **env)
{
	long long int		i;
	char				*result;

	i = 0;
	U_C = (char)va_arg((*env)->va, int);
	if (F_WIDTH > 1)
	{
		if (!(result = ft_strnew(F_WIDTH)))
			return (FALSE);
		if (F_ALIGN == RIGHT)
			while (i < F_WIDTH - 1)
				result[i++] = ' ';
		result[i++] = U_C;
		if (F_ALIGN == LEFT)
			while (i < F_WIDTH)
				result[i++] = ' ';
		write(1, result, i);
		LEN += i;
		ft_strdel(&result);
		return (TRUE);
	}
	write(1, &U_C, 1);
	LEN++;
	return (TRUE);
}
