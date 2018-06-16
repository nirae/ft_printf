/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 10:24:46 by ndubouil          #+#    #+#             */
/*   Updated: 2018/06/14 20:25:14 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>

void 	ft_getleaks(char *str)
{
	system("leaks printf");
	printf("%s\n", str);
	getchar();
}

int		main()
{
	//int i = 3;
	//int i = ft_printf("coucou %s %s %c %d\n", "blabla", "Nico", 'a', 10);
	//ft_putnbr(i);
	//ft_printf("binaire : %b\n", 50);
	//ft_printf("le mien : %o\n", 50);
	//ft_printf("%-130.13c", 'c');
	//ft_printf("%-11.34lll");
	//printf("le vrai :\n");
	//printf("hello ca%----4c %1c va %10c%-c ??", '\0', '\n', (char)564, 0);
	//ft_printf("le mien :\n");
	//ft_printf("hello ca%----4c %1c va %10c%-c ??\n", '\0', '\n', (char)564, 0);
	//ft_printf("coucou tout le monde %-0100%");
	//long int d = 3;
	//printf("vrai : %D\n", d);
	ft_printf("moii : %C\n", 0x40501);
	printf("vrai : %C\n", 0x40501);
	//ft_printf("vrai : u%4.2ss %-1.s\n %---5.3s", "coco", NULL, "yooo");
	//ft_printf("moii : u%4.2ss %-1.s\n %---5.3s", "coco", NULL, "yooo");
	//ft_getleaks("coucou");
	
	return (0);
}
