/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 15:06:12 by ndubouil          #+#    #+#             */
/*   Updated: 2018/06/19 18:30:56 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	Put some string in the buffer t_buffer
**	Will be printed if the buffer is full
*/

int		putstr_in_buffer(t_buffer *buff, char *str)
{
	int		i;
	int		strlen;

	strlen = ft_strlen(str);
	i = -1;
	while (++i <= strlen)
	{
		if (buff->len == BUFFER_SIZE)
		{
			buff->buff[buff->len] = '\0';
			print_buffer(buff);
		}
		if (i == strlen)
		{
			buff->buff[buff->len] = '\0';
			return (strlen);
		}
		buff->buff[buff->len] = str[i];
		buff->len++;
	}
	return (strlen);
}

/*
**	Put some char in the buffer t_buffer
**	Will be printed if the buffer is full
*/

int		putchar_in_buffer(t_buffer *buff, char c)
{
	if (buff->len == BUFFER_SIZE)
	{
		buff->buff[buff->len] = '\0';
		print_buffer(buff);
	}
	buff->buff[buff->len] = c;
	buff->len++;
	return (1);
}

/*
**	Print and clean the buffer
*/

void		print_buffer(t_buffer *buff)
{
	write(1, buff->buff, buff->len);
	ft_bzero(buff->buff, buff->len);
	buff->len = 0;
	buff->pos_last_conv = 0;
}

#include <stdio.h>

void		delete_end_of_buffer(t_buffer *buff, int start)
{
	int i;

	//printf("\nSTART = %d\n", start);
	i = start;
	while (buff->buff[i] != '\0')
	{
		//ft_putchar(buff->buff[i]);
		buff->buff[i] = '\0';
		buff->len--;
		i++;	
	}
	print_buffer(buff);
}
