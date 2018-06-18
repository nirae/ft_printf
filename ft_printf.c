/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 09:38:44 by ndubouil          #+#    #+#             */
/*   Updated: 2018/06/18 14:49:25 by ndubouil         ###   ########.fr       */
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

int		print_percent(t_env *env)
{
	long long int		i;

	i = -1;
	env->types.c = '%';
	if (env->flags.width > 1)
	{
		if (env->flags.align == RIGHT)
			while (++i < env->flags.width - 1)
			{
				if (env->flags.zero)
					env->len += putchar_in_buffer(&env->buff, '0');
				else
					env->len += putchar_in_buffer(&env->buff, ' ');
			}
		env->len += putchar_in_buffer(&env->buff, env->types.c);
		if (env->flags.align == LEFT)
			while (++i < env->flags.width - 1)
				env->len += putchar_in_buffer(&env->buff, ' ');
		return (TRUE);
	}
	env->len += putchar_in_buffer(&env->buff, env->types.c);
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
	if ((env->flags.type == 'c' && env->flags.size == L) ||
		env->flags.type == 'C')
		print_big_char(env);
	else if (env->flags.type == '%')
		print_percent(env);
	else if (env->flags.type == 'C' || (env->flags.type == 'c' && env->flags.size == L))
		print_big_char(env);
	else if (env->flags.type == 'c')
		print_char(env);
	else if (env->flags.type == 's')
		print_string(env);
	else if (env->flags.type == 'p')
		print_address(env);
	else if (env->flags.type == 'd' || env->flags.type == 'i' || env->flags.type == 'D')
		print_number(env);
	else if (env->flags.type == 'u' || env->flags.type == 'U')
		print_unsigned_number(env);
	else if (env->flags.type == 'o' || env->flags.type == 'O')
		print_octal(env);
	else if (env->flags.type == 'x' || env->flags.type == 'X')
		print_hexa(env);
	else
		return (0);
	return (1);
}

int		ft_printf(const char *str, ...)
{
	t_env		env;
	char		*string;
	char		*locale;

	locale = setlocale(LC_ALL, "");
	va_start(env.va, str);
	string = (char *)str;
	env.pos = 0;
	env.len = 0;
	env.buff.len = 0;
	while (string[env.pos] != 0)
	{
		if (string[env.pos] != '%')
		{
			env.len += putchar_in_buffer(&env.buff, string[env.pos]);
			env.pos++;
			continue;
		}
		env.pos++;
		if (!parser(string, &env))
			return (FAIL);
		// DEBUG
	//	print_tflags(&env);
		printer(&env);
		//if (is_valid_type(string[env.pos]))
		//	print_types(string[env.pos], &env);
	}
	va_end(env.va);
	print_buffer(&env.buff);
	return (env.len);
}
