/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 10:24:46 by ndubouil          #+#    #+#             */
/*   Updated: 2018/06/25 00:55:58 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>
#include <locale.h>
#include <limits.h>

void 	ft_getleaks(char *str)
{
	system("leaks my_test_printf");
	printf("%s\n", str);
	getchar();
}

int		main()
{
	//setlocale(LC_ALL, "");
	//int s[4];
	//s[0] = 0x53;
	//s[1] = 0x3abc;
	//s[2] = 0x81000;
	//s[3] = '\0';
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
	//ft_putendl("moi = ");
	//int a = ft_printf("%8C et coco %C titi %lc", 3250, 0x11ffff, 'a');
	//int a = ft_printf("yo%2C%-12lc et %C titi %C tyty", 'u', 254, 256, 'a');
	//int a = ft_printf("%9.6ls %S", s, (wchar_t *)'a');
	//ft_putchar('|');
	//int a;	
	//int a = ft_printf("%C", 0xdb02);
	//int a = ft_printf("%S", s);
	/*
	**	Cas indefinis faux sur Moulitest
	*/


	//int a = ft_printf("%");
	//int a = ft_printf("%llx, %llx", 0, ULLONG_MAX);
	//int a = ft_printf("%hD, %hD", 0, USHRT_MAX);
	//int a = ft_printf("%hhO, %hhO", 0, USHRT_MAX);
	//int a = ft_printf("{%-15p}", 0);
	//int a = ft_printf("{%03c}", 0);
	//int a = ft_printf("{%-15Z}", 123);
	//int a = ft_printf("%+o", 0);
	//int a = ft_printf("{% C}", 0);
	//int a = ft_printf("%4.1S", L"Jambon");
	//int a = ft_printf("%.0p, %.p", 0, 0);
	//int a = ft_printf("%.p, %.0p", 0, 0);
	//int a = ft_printf("% o|%+o", 42, 42);
	//int a = ft_printf("{%*3d}", 0, 0);
	//int a = ft_printf("{%f}{%F}", 1.42, 1.42);
	

	/*
	**
	*/
	
	//int b = printf("vrai = %-8d %C premiere phrase %d entre les deux %C normalement ca a foire avant\n", 125, 3250, 125, 0x11ffff);
	//ft_putendl("");
	//ft_putendl("vrai = ");
	//int b = printf("%9.6ls %S", s, (wchar_t *)'a');
	//int b = printf();
	//int b = printf("yo%2C%-12lc et %C titi %C tyty", 'u', 254, 256, 'a');
	//ft_putchar('|');
	
	//int b = 0;
	//int b = printf("%S", s);
	//b = printf("%hD, %hD", 0, USHRT_MAX);
	//b = printf("% o|%+o", 42, 42);
	//b = printf("{%f}{%F}", 1.42, 1.42);
	//b = printf("%15.4d", -42);
	//int b = printf("%.0p, %.p", 0, 0);
	//int b = printf("%C", 0xdb02);
	//printf("test : #-18x\n");	

	/*
	**	Cas indefinis faux sur Moulitest
	*/

	//int b = 0;

	//b = printf("%llx, %llx", 0, ULLONG_MAX);
	//b = printf("%.0p, %.p", 0, 0);
	//b = printf("{%03c}", 0);
//	b = printf("%hD, %hD", 0, USHRT_MAX);
	//b = printf("{%-15Z}", 123);
	//int b = printf("%hhO, %hhO", 0, USHRT_MAX);
	//int b = printf("{%-15p}", 0);
	//b = printf("{% C}", 0);
	//int b = printf("% o|%+o", 42, 42);
	//int b = printf("{%*3d}", 0, 0);
	//b = printf("%4.1S", L"Jambon");
	//int b = printf("%15.4d", -42);
	//int b = printf("{%f}{%F}", 1.42, 1.42);
	

	/*
	**
	*/


	//printf("\nretour moi = %d\n", a);
	//printf("retour vrai = %d\n", b);
	//ft_printf("vrai : u%4.2ss %-1.s\n %---5.3s", "coco", NULL, "yooo");
	//ft_printf("moii : u%4.2ss %-1.s\n %---5.3s", "coco", NULL, "yooo");
	ft_printf("%d", 3250);
	//ft_getleaks("fin du main");
	return (0);
}
