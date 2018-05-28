/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulli_itoa_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 20:14:51 by ndubouil          #+#    #+#             */
/*   Updated: 2018/05/29 00:03:12 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_count(int n, int base)
{
	int		i;

	i = 1;
	while (n >= base)
	{
		n = n / base;
		i++;
	}
	return (i - 1);
}

char		*ft_lli_itoa_base(long long int n, int base)
{
	int		len;
	int		i;
	char	*result;

	len = ft_count(n, base);
	if (!(result = ft_strnew(len + 1)))
		return (0);
	i = 0;
	while (i <= len)
	{
		result[i++] = (n % base) + (n % base > 9 ? 'a' - 10 : 48);
		n = n / base;
	}
	return (ft_strrev(result));
}
