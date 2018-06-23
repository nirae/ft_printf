/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:08:59 by ndubouil          #+#    #+#             */
/*   Updated: 2018/06/22 20:28:27 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "../libft/libft.h"
# include <locale.h>
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

typedef union					u_types
{
	char						c;
	char						*str;
	wchar_t						*wc;
	int							i;
	long int					li;
	long long int				lli;
	unsigned long long int 		ulli;
	short int					si;
}								t_types;

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

# define BUFFER_SIZE 4096

typedef	struct		s_buffer
{
	int				len;
	int				pos_last_conv;
	char			buff[BUFFER_SIZE];
}					t_buffer;

typedef struct		s_env
{
	t_types			types;
	t_buffer		buff;
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

int					print_char(t_env *env);
int					print_big_char(t_env *env);
int					print_big_string(t_env *env);
int					print_string(t_env *env);
int					print_address(t_env *env);
int					print_number(t_env *env);
int					print_unsigned_number(t_env *env);
int					print_octal(t_env *env);
int					print_hexa(t_env *env);

int					take_big_char(t_env *env, int c, char result[5]);
int					take_len(int i);
/*
** BUFFER
*/

int					putstr_in_buffer(t_buffer *buff, char *str);
int					putchar_in_buffer(t_buffer *buff, char c);
void				print_buffer(t_buffer *buff);
void				delete_end_of_buffer(t_buffer *buff, int start);

char				*ft_lli_itoa_base(long long int n, char *base_str);
char				*ft_ulli_itoa_base(unsigned long long int n, char *base_str);

int					ft_printf(const char *str, ...);

#endif
