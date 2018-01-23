/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 10:24:46 by ndubouil          #+#    #+#             */
/*   Updated: 2018/01/23 16:42:39 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"
#include <stdio.h>

int		main(void)
{
	int i = 3;
	//int i = ft_printf("coucou %s %s %c %d\n", "blabla", "Nico", 'a', 10);
	//ft_putnbr(i);
	ft_printf("%p\n", i);
	printf("%p", i);
	return (0);
}
