/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulli_itoa_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 20:14:51 by ndubouil          #+#    #+#             */
/*   Updated: 2018/05/30 18:20:56 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_count(unsigned long long int n, int base)
{
	int		i;

	i = 0;
	while (n != 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char		*ft_ulli_itoa_base(unsigned long long int n, char *base_str)
{
	int		len;
	int		base;
	char	*result;

	base = ft_strlen(base_str);
	len = ft_count(n, base);
	if (!(result = ft_strnew(len)))
		return (NULL);
	result[0] = '0';
	while (n != 0)
	{
		result[--len] = base_str[n % base];
		n = n / base;
	}
	return (result);
}
