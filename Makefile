# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/14 08:41:35 by ndubouil          #+#    #+#              #
#    Updated: 2018/01/17 12:26:18 by ndubouil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binaries and Flags
CC		=	/usr/bin/gcc
AR		=	/usr/bin/ar
RANLIB	=	/usr/bin/ranlib
RM		=	/bin/rm
CFLAGS	=	-Wall -Wextra -Werror
# Directories
LIB		=	./libft/
HEADER	=	.
#  Files
HFILES	=	$(HEADER)/libftprintf.h
SRC		=	ft_printf.c
OBJ		=	$(patsubst %.c,%.o,$(SRC))
# Name
NAME	=	libftprintf.a

.PHONY: all clean fclean re

all:		$(NAME)
		@true

$(NAME):	$(OBJ) $(MAIN) $(HFILES) $(LIB) Makefile
		@echo "Compiling libft ..."
		@make -C $(LIB)
		@echo "Building $(NAME) ..."
		@cp $(LIB)libft.a $(NAME)
		@$(AR) r $(NAME) $(OBJ)
		@$(RANLIB) $(NAME)
		@echo "I'm READY'"

%.o: 		%.c
		@echo "Creating $@ ..."
		@$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER)

clean:
		@echo "Cleaning Objs ..."
		@$(RM) -f $(OBJ)
		@echo "Cleaning libft Objs ..."
		@make clean -C $(LIB)

fclean:		clean
		@echo "Cleaning $(NAME) exec"
		@$(RM) -f $(NAME)
		@echo "Cleaning libft exec"
		@make fclean -C $(LIB)

re:			fclean all
