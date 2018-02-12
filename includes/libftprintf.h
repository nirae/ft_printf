/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:08:59 by ndubouil          #+#    #+#             */
/*   Updated: 2018/02/12 11:48:52 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

/*
** MACROS for struct t_env
*/

# define POS			(*env)->pos
# define LEN			(*env)->len

/*
** MACROS for struct t_flags in t_env
*/

# define F_ZERO			(*env)->flags.zero
# define F_ALIGN		(*env)->flags.align
# define F_SIGN			(*env)->flags.sign
# define F_SPACE		(*env)->flags.space
# define F_HASH			(*env)->flags.hash
# define F_WIDTH		(*env)->flags.width
# define F_PRECISION	(*env)->flags.precision
# define F_SIZE			(*env)->flags.size
# define F_TYPE			(*env)->flags.type

/*
** MACROS for union t_types in t_env
*/

# define U_C			(*env)->types.c
# define U_STR			(*env)->types.str
# define U_I			(*env)->types.i
# define U_LI			(*env)->types.li
# define U_LLI			(*env)->types.lli

# define RIGHT	2
# define LEFT	3

# define FAIL	-666

/*
** TRUE = 1
** FALSE = 0
*/

typedef enum		e_bool
{
	FALSE,
	TRUE
}					t_bool;

/*
** H =	4
** HH = 5
** L =	6
** LL = 7
** J =	8
** Z =	9
*/

typedef enum		e_size
{
	H = 4,
	HH,
	L,
	LL,
	J,
	Z
}					t_size;

typedef union		u_types
{
	char			c;
	char			*str;
	int				i;
	long int		li;
	long long int	lli;
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
** Parsing
*/

int					is_valid_flags(char c);
int					is_valid_sizeflag(char c);
int					is_valid_type(char c);
void				init_flags(t_env **env);
int					set_flags(char *str, t_env **env);
int					set_size(char *str, t_env **env);
int					set_type(char *str, t_env **env);
int					set_width(char *str, t_env **env);
int					set_precision(char *str, t_env **env);

/*
** Printing
*/

int					print_char(t_env **env);

int					ft_printf(const char *str, ...);

#endif
