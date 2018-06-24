# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/14 08:41:35 by ndubouil          #+#    #+#              #
#    Updated: 2018/06/24 19:29:29 by ndubouil         ###   ########.fr        #
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
H		=	./includes
PA		=	./parser
PR		=	./printer
U_TOOLS	=	./printer/unicode_tools
B		=	./buffer
#  Files
HFILES	=	$(H)/libftprintf.h
SRC		=	$(PA)/is_valid_flags.c		\
			$(PA)/is_valid_sizeflag.c	\
			$(PA)/is_valid_type.c		\
			$(PA)/init_flags.c			\
			$(PA)/set_flags.c			\
			$(PA)/set_size.c			\
			$(PA)/set_type.c			\
			$(PA)/set_width.c			\
			$(PA)/set_precision.c		\
			$(PR)/print_char.c			\
			$(PR)/print_big_char.c			\
			$(PR)/print_big_string.c			\
			$(PR)/print_string.c		\
			$(PR)/print_address.c		\
			$(PR)/print_number.c		\
			$(PR)/print_octal.c			\
			$(PR)/print_hexa.c			\
			$(PR)/print_unsigned_number.c		\
			$(B)/buffer.c				\
			$(U_TOOLS)/get_big_char.c				\
			$(U_TOOLS)/ft_bigcharlen.c				\
			$(U_TOOLS)/ft_bigstrlen.c				\
			$(U_TOOLS)/ft_wstrlen.c				\
			ft_printf.c
OBJ		=	$(patsubst %.c,%.o,$(SRC))
# Name
NAME	=	libftprintf.a

.PHONY: all clean fclean re

all:		$(NAME)

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
		@$(CC) $(CFLAGS) -c $< -o $@ -I$(H)

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
