/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_leaks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 19:44:41 by ndubouil          #+#    #+#             */
/*   Updated: 2018/06/25 18:34:18 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>

void 	ft_getleaks(char *str)
{
	system("leaks printf -fullContent");
	printf("%s\n", str);
	getchar();
}

int main(void)
{
	ft_printf("\n");
	ft_getleaks("sans conversion");
	//ft_printf("%%\n");
	//ft_getleaks("2 pourcent");
	ft_printf("%d\n", 42);
	ft_getleaks("d");
	ft_printf("%d%d\n", 42, 41);
	ft_getleaks("d d");
	ft_printf("%d%d%d\n", 42, 43, 44);
	ft_getleaks("d d d");
	ft_printf("%ld\n", 2147483647);
	ft_getleaks("ld");
	ft_printf("%lld\n", 9223372036854775807);
	ft_getleaks("lld");
	//ft_printf("%x\n", 505);
	//ft_getleaks("x");
	//ft_printf("%X\n", 505);
	//ft_getleaks("X");
	ft_printf("%p\n", &ft_printf);
	ft_getleaks("p");
	ft_printf("%20.15d\n", 54321);
	ft_getleaks("20.15d");
	ft_printf("%-10d\n", 3);
	ft_getleaks("-10d");
	ft_printf("% d\n", 3);
	ft_getleaks(" d");
	ft_printf("%+d\n", 3);
	ft_getleaks("+d");
	ft_printf("%010d\n", 1);
	ft_getleaks("010d");
	ft_printf("%hhd\n", 0);
	ft_getleaks("hhd");
	ft_printf("%jd\n", 9223372036854775807);
	ft_getleaks("jd");
	ft_printf("%zd\n", 4294967295);
	ft_getleaks("zd");
	//ft_printf("%\n");
	//ft_getleaks("%");
	ft_printf("%U\n", 4294967295);
	ft_getleaks("U");
	ft_printf("%u\n", 4294967295);
	ft_getleaks("u");
	//ft_printf("%o\n", 40);
	//ft_getleaks("o");
	//ft_printf("%%#08x\n", 42);
	//ft_getleaks("2 pourcent #08x");
	//ft_printf("%x\n", 1000);
	//ft_getleaks("x");
	//ft_printf("%#X\n", 1000);
	//ft_getleaks("#X");
	ft_printf("%s\n", NULL);
	ft_getleaks("s");
	ft_printf("%S\n", L"ݗݜशব");
	ft_getleaks("S");
	ft_printf("%s%s\n", "test", "test");
	ft_getleaks("s s");
	ft_printf("%s%s%s\n", "test", "test", "test");
	ft_getleaks("s s s");
	ft_printf("%c\n", 'a');
	ft_getleaks("a");
	ft_printf("%C\n", 15000);
	ft_getleaks("C");
	return (0);
}
