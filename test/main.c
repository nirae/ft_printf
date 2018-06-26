/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 10:24:46 by ndubouil          #+#    #+#             */
/*   Updated: 2018/06/27 00:20:49 by ndubouil         ###   ########.fr       */
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

	// POUR TEST S
	//int s[4];
	//s[0] = 0x53;
	//s[1] = 0x3abc;
	//s[2] = 0x81000;
	//s[3] = '\0';
	
	// TEST MANUELS
	/*
	ft_putendl("moi = ");
	int a = 0;	
	a = ft_printf("%d", 42);
	ft_putendl("\nvrai = ");
	int b = 0;
	b = printf("%d", 42);
	*/


//////////////////////////////////////////////////////
///////// CAS INDEFINIS FAUX SUR MOULITEST //////////
//////////////////////////////////////////////////////

	// LE MIEN

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
	
	// LE VRAI

	//int b = printf("%");
	//int b = printf("%llx, %llx", 0, ULLONG_MAX);
	//int b = printf("%hD, %hD", 0, USHRT_MAX);
	//int b = printf("%hhO, %hhO", 0, USHRT_MAX);
	//int b = printf("{%-15p}", 0);
	//int b = printf("{%03c}", 0);
	//int b = printf("{%-15Z}", 123);
	//int b = printf("%+o", 0);
	//int b = printf("{% C}", 0);
	//int b = printf("%4.1S", L"Jambon");
	//int b = printf("%.0p, %.p", 0, 0);
	//int b = printf("%.p, %.0p", 0, 0);
	//int b = printf("% o|%+o", 42, 42);
	//int b = printf("{%*3d}", 0, 0);
	//int b = printf("{%f}{%F}", 1.42, 1.42);

//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
	
	return (0);
}
