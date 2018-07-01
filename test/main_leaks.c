/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_leaks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 19:44:41 by ndubouil          #+#    #+#             */
/*   Updated: 2018/07/01 16:18:58 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
//#include <stdio.h>

/*void 	//ft_getleaks/g(char *str)
{
	system("leaks my_test_printf");
	printf("%s\n", str);
	getchar();
}*/

int main(void)
{
	ft_printf("\n");
	//ft_getleaks/g("sans conversion");
	ft_printf("%%\n");
	//ft_getleaks/g("2 pourcent");
	ft_printf("%d\n", 42);
	//ft_getleaks/g("d");
	ft_printf("%d%d\n", 42, 41);
	//ft_getleaks/g("d d");
	ft_printf("%d%d%d\n", 42, 43, 44);
	//ft_getleaks/g("d d d");
	ft_printf("%ld\n", 2147483647);
	//ft_getleaks/g("ld");
	ft_printf("%lld\n", 9223372036854775807);
	//ft_getleaks/g("lld");
	ft_printf("%x\n", 505);
	//ft_getleaks/g("x");
	ft_printf("%X\n", 505);
	//ft_getleaks/g("X");
	ft_printf("%p\n", &ft_printf);
	//ft_getleaks/g("p");
	ft_printf("%20.15d\n", 54321);
	//ft_getleaks/g("20.15d");
	ft_printf("%-10d\n", 3);
	//ft_getleaks/g("-10d");
	ft_printf("% d\n", 3);
	//ft_getleaks/g(" d");
	ft_printf("%+d\n", 3);
	//ft_getleaks/g("+d");
	ft_printf("%010d\n", 1);
	//ft_getleaks/g("010d");
	ft_printf("%hhd\n", 0);
	//ft_getleaks/g("hhd");
	ft_printf("%jd\n", 9223372036854775807);
	//ft_getleaks/g("jd");
	ft_printf("%zd\n", 4294967295);
	//ft_getleaks/g("zd");
	ft_printf("%\n");
	//ft_getleaks/g("%");
	ft_printf("%U\n", 4294967295);
	//ft_getleaks/g("U");
	ft_printf("%u\n", 4294967295);
	//ft_getleaks/g("u");
	ft_printf("%o\n", 40);
	//ft_getleaks/g("o");
	ft_printf("%%#08x\n", 42);
	//ft_getleaks/g("2 pourcent #08x");
	ft_printf("%x\n", 1000);
	//ft_getleaks/g("x");
	ft_printf("%#X\n", 1000);
	//ft_getleaks/g("#X");
	ft_printf("%s\n", NULL);
	//ft_getleaks/g("s");
	ft_printf("%S\n", L"ݗݜशব");
	//ft_getleaks/g("S");
	ft_printf("%s%s\n", "test", "test");
	//ft_getleaks/g("s s");
	ft_printf("%s%s%s\n", "test", "test", "test");
	//ft_getleaks/g("s s s");
	ft_printf("%c\n", 'a');
	//ft_getleaks/g("a");
	ft_printf("%C\n", 15000);
	//ft_getleaks/g("C");
	return (0);
}
