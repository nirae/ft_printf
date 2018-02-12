/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 09:38:44 by ndubouil          #+#    #+#             */
/*   Updated: 2018/02/12 14:13:15 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

///////////////////////////////////////////////////////////
////////////////    DEBUG    //////////////////////////////
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
	printf("precision : %lld\n", env->flags.precision);
	printf("size : %d\n", env->flags.size);
	printf("type : %c\n", env->flags.type);
}
///////////////////////////////////////////////////////////
/*
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
   }*/

/*int		catch_arg()
  {
  char		*result;


  }

  int		print_integer(t_env **env)
  {

  }*/

int		print_percent(t_env **env)
{
	long long int		i;
	char				*result;

	i = 0;
	U_C = '%';
	if (F_WIDTH > 1)
	{
		if (!(result = ft_strnew(F_WIDTH)))
			return (FALSE);
		if (F_ALIGN == RIGHT)
			while (i < F_WIDTH - 1)
			{
				if (F_ZERO)
					result[i++] = '0';
				else
					result[i++] = ' ';
			}
		result[i++] = U_C;
		if (F_ALIGN == LEFT)
			while (i < F_WIDTH)
				result[i++] = ' ';
		write(1, result, i);
		LEN += i;
		ft_strdel(&result);
		return (TRUE);
	}
	write(1, &U_C, 1);
	LEN++;
	return (TRUE);
}

int		parser(char *str, t_env *env)
{
	init_flags(&env);
	set_flags(str, &env);
	set_width(str, &env);
	set_precision(str, &env);
	set_size(str, &env);
	if (!set_type(str, &env))
		return (FALSE);
	return (TRUE);
}

int		printer(t_env *env)
{
	//if ((env->flags.type == 'c' && env->flags.size == 'l') ||
	//	env->flags.type == 'C')
	//	print_lchar(&env);
	if (env->flags.type == '%')
		print_percent(&env);
	if (env->flags.type == 'c')
		print_char(&env);
	//if (env->flags.type == 'd' || env->flags.type == 'i')
	//	print_integer(&env);
	return (0);
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
		if (!parser(string, &env))
			return (FAIL);
		// DEBUG
		//print_tflags(&env);
		printer(&env);
		//if (is_valid_type(string[env.pos]))
		//	print_types(string[env.pos], &env);
	}
	va_end(env.va);
	return (env.len);
}
