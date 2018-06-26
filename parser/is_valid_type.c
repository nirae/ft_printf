/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 08:09:38 by ndubouil          #+#    #+#             */
/*   Updated: 2018/06/26 22:18:26 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		is_valid_type(char c)
{
	if (c == 's' || c == 'd' || c == 'i' || c == 'c' || c == 'p' ||
		c == 'o' || c == '%' || c == 'D' || c == 'C' ||
		c == 'S' || c == 'O' || c == 'u' || c == 'U' || c == 'x' ||
		c == 'X' || c == 'b' || c == 'B')
		return (TRUE);
	return (FALSE);
}