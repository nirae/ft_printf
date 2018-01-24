/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 10:24:46 by ndubouil          #+#    #+#             */
/*   Updated: 2018/01/24 14:53:30 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"
#include <stdio.h>
// Pour open()
#include <fcntl.h>
#define BUFF_SIZE 5



int		main(int argc, char **argv)
{
	//int i = 3;
	//int i = ft_printf("coucou %s %s %c %d\n", "blabla", "Nico", 'a', 10);
	//ft_putnbr(i);
	//ft_printf("binaire : %b\n", 50);
	//ft_printf("le mien : %o\n", 50);
	printf("le vrai : %-d\n", 50);

	

	//////////////////////////// TEST READ //////////////////////////////
	if (argc == 2)
	{
		int		fd, n_lus;
		char	*final_string;
		char	*buffer;
		char	*temp;

		// Open le fichier en lecture seule
		fd = open(argv[1], O_RDONLY);
		// Initialisation de la string resultat + protection malloc
		if (!(final_string = ft_strnew(0)))
			return (0);
		// Initialisation du buffer
		if (!(buffer = ft_strnew(BUFF_SIZE)))
			return (0);
		// Tant qu'il y a quelque chose a lire
		while ((n_lus = read(fd, buffer, BUFF_SIZE)) > 0)
		{
			// pour leaks
			temp = final_string;
			// join le buffer avec ce qui a deja ete lu
			final_string = ft_strjoin(final_string, buffer);
			// pour leaks
			ft_strdel(&temp);
			// vider le buffer
			ft_strclr(buffer);
		}
		// pour leaks
		ft_strdel(&buffer);
		ft_printf("%s", final_string);
		close(fd);
	}
	////////////////////////////////////////////////////////////////
	return (0);
}
