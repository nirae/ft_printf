/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:08:59 by ndubouil          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/01/22 00:16:11 by ndubouil         ###   ########.fr       */
=======
/*   Updated: 2018/01/24 14:53:28 by ndubouil         ###   ########.fr       */
>>>>>>> 6d65c02773ae7a694a3414f79ea2db07883708fe
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

<<<<<<< HEAD

=======
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
>>>>>>> 6d65c02773ae7a694a3414f79ea2db07883708fe

/*
** ft_printf
*/
int					ft_printf(const char *str, ...);

#endif
