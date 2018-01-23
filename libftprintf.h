/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:08:59 by ndubouil          #+#    #+#             */
/*   Updated: 2018/01/23 16:46:36 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

typedef union		u_types
{
	char			c;
	char			*str;
	int				i;
	double			d;
}					t_types;

typedef struct		s_env
{
	t_types			types;
	int				len;
}					t_env;

/*
** ft_printf
*/
int					ft_printf(const char *str, ...);



#endif
