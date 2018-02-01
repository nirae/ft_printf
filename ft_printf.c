/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 09:38:44 by ndubouil          #+#    #+#             */
/*   Updated: 2018/02/01 20:02:49 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

///////////////////////////////////////////////////////////
#include <stdio.h>

void	print_tflags(t_env *env)
{
	printf("alignement : %d\n", env->flags.align);	
	printf("signe : %d\n", env->flags.sign);
	printf("zero : %d\n", env->flags.zero);
	printf("espace : %d\n", env->flags.space);
	printf("hash : %d\n", env->flags.hash);
	printf("width : %lld\n", env->flags.width);
	printf("precision : %d\n", env->flags.precision);
}
///////////////////////////////////////////////////////////

int		is_valid_flags(char c)
{
	if (c == '-' || c == '+' || c == '0' || c == ' ' || c == '#')
		return (1);
	return (0);
}

// Initialise tous les flags par defaut
void	init_all_flags(t_env **env)
{
	// flags
	(*env)->flags.align = RIGHT;
	(*env)->flags.sign = FALSE;
	(*env)->flags.zero = FALSE;
	(*env)->flags.space = FALSE;
	(*env)->flags.hash = FALSE;
	// width
	(*env)->flags.width = 0;
	// precision
	(*env)->flags.precision = 0;
}

// Rempli les flags
int		set_flags(char *str, t_env **env)
{
	// Point de sortie -> Si le flag est invalide
	if (!is_valid_flags(str[(*env)->pos]))
		return (0);
	// DEBUG
	printf("flag : %c\n", str[(*env)->pos]);
	// GESTION des flags
	if (str[(*env)->pos] == '-')
	{
		(*env)->flags.align = LEFT;
		(*env)->flags.zero = FALSE;
	}
	if (str[(*env)->pos] == '+')
	{
		(*env)->flags.sign = TRUE;
		(*env)->flags.space = FALSE;
	}
	if (str[(*env)->pos] == '0' && (*env)->flags.align != LEFT)
		(*env)->flags.zero = TRUE;
	if (str[(*env)->pos] == ' ' && !(*env)->flags.sign)
		(*env)->flags.space = TRUE;
	(*env)->flags.hash = (str[(*env)->pos] == '#') ? TRUE : FALSE;
	// Flag suivant
	(*env)->pos++;
	// Recursif
	return (set_flags(str, env));
}

// Rempli la largeur
int		set_width(char *str, t_env **env)
{
	long long int		i;

	i = 0;
	// micro-atoi
	while (ft_isdigit(str[(*env)->pos]))
	{
		i = (str[(*env)->pos] - '0' + i * 10);
		(*env)->pos++;
	}
	if (str[(*env)->pos] == '*')
	{
		i = va_arg((*env)->va, int);
		(*env)->pos++;
	}
	(*env)->flags.width = i;
	return (0);
}

int		set_precision(char *str, t_env **env)
{
	int		i;

	i = 0;
	if (str[(*env)->pos] != '.')
		return (0);
	(*env)->pos++;
	// micro-atoi
	while (ft_isdigit(str[(*env)->pos]))
	{
		i = (str[(*env)->pos] - '0' + i * 10);
		(*env)->pos++;
	}
	if (str[(*env)->pos] == '*')
	{
		i = va_arg((*env)->va, int);
		(*env)->pos++;
	}
	(*env)->flags.precision = i;
	return (0);
}

int		is_valid_type(char c)
{
	if (c == 's' || c == 'd' || c == 'i' || c == 'c' || c == 'p' ||
		c == 'b' || c == 'o')
		return (1);
	return(0);
}

void	parser(char *str, t_env *env)
{
	//if (is_valid_flags(str[env->pos]))
	init_all_flags(&env);
	set_flags(str, &env);
	set_width(str, &env);
	set_precision(str, &env);
}

void	print_types(char c, t_env *env)
{
	if (c == 's')
	{
		env->types.str = va_arg(env->va, char *);
		ft_putstr(env->types.str);
		env->len += ft_strlen(env->types.str);
	}
	if (c == 'd' || c == 'i')
	{
		env->types.i = va_arg(env->va, int);
		ft_putnbr(env->types.i);
		env->len += ft_strlen(ft_itoa(env->types.i));
	}
	if (c == 'c')
	{
		env->types.c = (char)va_arg(env->va, int);
		ft_putchar(env->types.c);
		env->len += 1;
	}
	if (c == 'p')
	{
		env->types.i = va_arg(env->va, int);
		ft_putstr("0x7fff");
		ft_putstr(ft_itoa_base(env->types.i, 16));
		env->len += ft_strlen(ft_itoa_base(env->types.i, 16));
	}
	if (c == 'b')
	{
		env->types.i = va_arg(env->va, int);
		ft_putstr(ft_itoa_base(env->types.i, 2));
		env->len += ft_strlen(ft_itoa_base(env->types.i, 2));
	}
	if (c == 'o')
	{
		env->types.i = va_arg(env->va, int);
		ft_putstr(ft_itoa_base(env->types.i, 8));
		env->len += ft_strlen(ft_itoa_base(env->types.i, 8));
	}
	env->pos += 1;
}

int		ft_printf(const char *str, ...)
{
	t_env		env;
	char		*string;

	va_start(env.va, str);
	string = (char *)str;
	env.pos = 0;
	env.len = 0;
	while (string[env.pos] != 0)
	{
		if (string[env.pos] != '%')
		{
			ft_putchar(string[env.pos]);
			env.pos++;
			env.len++;
			continue;
		}
		env.pos++;
		parser(string, &env);
		print_tflags(&env);
		//if (is_valid_type(string[env.pos]))
		//	print_types(string[env.pos], &env);
	}
	va_end(env.va);
	return (env.len);
}
