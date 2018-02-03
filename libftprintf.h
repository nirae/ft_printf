/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:08:59 by ndubouil          #+#    #+#             */
/*   Updated: 2018/02/03 16:49:17 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

# define TRUE 1
# define FALSE 0

# define RIGHT 2
# define LEFT 3

# define H 4
# define HH 5
# define L 6
# define LL 7
# define J 8
# define Z 9

typedef union		u_types
{
	char			c;
	char			*str;
	int				i;
	double			d;
}					t_types;

typedef struct		s_flags
{
	int				align;
	int				sign;
	int				zero;
	int				space;
	int				hash;
	long long int	width;
	long long int	precision;
	int				size;
	char			type;
}					t_flags;

typedef struct		s_env
{
	t_types			types;
	int				len;
	int				pos;
	va_list			va;
	t_flags			flags;
}					t_env;

/*
** ft_printf
*/
int					ft_printf(const char *str, ...);

#endif
