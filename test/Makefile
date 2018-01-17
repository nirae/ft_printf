# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 10:26:48 by ndubouil          #+#    #+#              #
#    Updated: 2018/01/17 08:20:53 by ndubouil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binaries and Flags
CC		=	/usr/bin/gcc
RM		=	/bin/rm
CFLAGS	=	-Wall -Wextra -Werror
# Directories
PRINTFLIB		=	..
LIB		=	../libft/
HEADER	=	.
# Files
MAIN	=	main.c
OBJ		=	$(patsubst %.c,%.o,$(SRC))
# Name
NAME	=	printf

.PHONY: all clean fclean re

all:		$(NAME)
			@true

$(NAME):	$(OBJ) $(MAIN) $(LIB) $(PRINTFLIB) Makefile
		@echo "Compiling libftprintf ..."
		@make -C $(PRINTFLIB)
		@echo "Building $(NAME) ..."
		@$(CC) $(CFLAGS) $(MAIN) $(OBJ) -L$(PRINTFLIB) -lftprintf -o $(NAME)
		@echo "OK"

%.o: 		%.c
		@echo "Creating $@ ..."
		@$(CC) $(CFLAGS) -c $< -o $@

clean:
		@echo "Cleaning Objs ..."
		@$(RM) -f $(OBJ)
		@echo "Cleaning  ft_printf Objs ..."
		@make clean -C $(PRINTFLIB)

fclean:		clean
		@echo "Cleaning $(NAME) exec"
		@$(RM) -f $(NAME)
		@echo "Cleaning ft_printf exec"
		@make fclean -C $(PRINTFLIB)

re:			fclean all
