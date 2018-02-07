/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 10:24:46 by ndubouil          #+#    #+#             */
/*   Updated: 2018/02/07 10:17:55 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"
#include <stdio.h>

int		main()
{
	//int i = 3;
	//int i = ft_printf("coucou %s %s %c %d\n", "blabla", "Nico", 'a', 10);
	//ft_putnbr(i);
	//ft_printf("binaire : %b\n", 50);
	//ft_printf("le mien : %o\n", 50);
	//ft_printf("%-0");
	//ft_printf("%-11.34lll");
	printf("%c\n", 'c');
	ft_printf("%c\n", 'c');
	//ft_printf("%", 50);
	
	return (0);
}
