/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 10:24:46 by ndubouil          #+#    #+#             */
/*   Updated: 2018/06/20 21:28:13 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>
#include <locale.h>

void 	ft_getleaks(char *str)
{
	system("leaks printf");
	printf("%s\n", str);
	getchar();
}

int		main()
{
	//char		*locale;
	//locale = setlocale(LC_ALL, "");
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
	//int a = ft_printf("moii = %-8d %C premiere phrase %d entre les deux %C normalement ca a foire avant\n", 125, 3250, 125, 0x11ffff);
	ft_putendl("moi = ");
	//int a = ft_printf("%8C et coco %C titi %lc", 250, 0x11ffff, 'a');
	int a = ft_printf("yo%2C%-12lc et %C titi %C tyty", 'u', 254, 256, 'a');
	//ft_putchar('|');
	//int a = ft_printf("%C", 256);
	
	ft_putendl("");
	//int b = printf("vrai = %-8d %C premiere phrase %d entre les deux %C normalement ca a foire avant\n", 125, 3250, 125, 0x11ffff);
	ft_putendl("vrai = ");
	//int b = printf("%8C et coco %C titi %lc", 250, 0x11ffff, 'a');
	int b = printf("yo%2C%-12lc et %C titi %C tyty", 'u', 254, 256, 'a');
	//ft_putchar('|');
	//int b = printf("%C", 256);
	//printf("test : #-18x\n");	

	printf("\nretour moi = %d\n", a);
	printf("retour vrai = %d\n", b);
	//ft_printf("vrai : u%4.2ss %-1.s\n %---5.3s", "coco", NULL, "yooo");
	//ft_printf("moii : u%4.2ss %-1.s\n %---5.3s", "coco", NULL, "yooo");
	//ft_getleaks("coucou");
	
	return (0);
}
