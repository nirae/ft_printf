# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 15:04:58 by ndubouil          #+#    #+#              #
#    Updated: 2018/01/11 15:50:15 by ndubouil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binaries
CC		=	/usr/bin/gcc
AR		=	/usr/bin/ar
RANLIB	=	/usr/bin/ranlib
RM		=	/bin/rm
# Directories
HEADER	=	.
LIBHEADER	= ./libft/
LIBFT		= ./libft
# Compilation flags
CFLAGS	=	-Wall -Wextra -Werror
# Files
SRC		=	$(LIBFT)/ft_putchar.c		\
	  	$(LIBFT)/ft_putstr.c			\
	  	$(LIBFT)/ft_putchar_fd.c		\
	  	$(LIBFT)/ft_putstr_fd.c			\
	  	$(LIBFT)/ft_ispositive.c		\
	  	$(LIBFT)/ft_putnbr.c			\
	  	$(LIBFT)/ft_putnbr_fd.c			\
	  	$(LIBFT)/ft_putendl.c			\
	  	$(LIBFT)/ft_putendl_fd.c		\
	 	$(LIBFT)/ft_strclr.c			\
	  	$(LIBFT)/ft_striter.c			\
	  	$(LIBFT)/ft_striteri.c			\
	  	$(LIBFT)/ft_strequ.c			\
	  	$(LIBFT)/ft_strnequ.c			\
	  	$(LIBFT)/ft_memalloc.c			\
	  	$(LIBFT)/ft_memdel.c			\
	  	$(LIBFT)/ft_strnew.c			\
	  	$(LIBFT)/ft_strdel.c			\
	  	$(LIBFT)/ft_strlen.c			\
	  	$(LIBFT)/ft_isalpha.c			\
	  	$(LIBFT)/ft_isupper.c			\
	  	$(LIBFT)/ft_islower.c			\
	  	$(LIBFT)/ft_toupper.c			\
	  	$(LIBFT)/ft_tolower.c			\
	  	$(LIBFT)/ft_isdigit.c			\
	  	$(LIBFT)/ft_isalnum.c			\
	  	$(LIBFT)/ft_isascii.c			\
	  	$(LIBFT)/ft_isprint.c			\
	  	$(LIBFT)/ft_strmap.c			\
	  	$(LIBFT)/ft_strmapi.c			\
	  	$(LIBFT)/ft_strsub.c			\
	  	$(LIBFT)/ft_strjoin.c			\
	  	$(LIBFT)/ft_strtrim.c			\
	  	$(LIBFT)/ft_isspace_tab_nl.c	\
	  	$(LIBFT)/ft_strdup.c			\
	  	$(LIBFT)/ft_strcpy.c			\
	  	$(LIBFT)/ft_strncpy.c			\
	  	$(LIBFT)/ft_strcat.c			\
	  	$(LIBFT)/ft_strncat.c			\
	  	$(LIBFT)/ft_strlcat.c			\
	  	$(LIBFT)/ft_strchr.c			\
	  	$(LIBFT)/ft_strrchr.c			\
	  	$(LIBFT)/ft_strcmp.c			\
	  	$(LIBFT)/ft_strncmp.c			\
	  	$(LIBFT)/ft_strstr.c			\
	  	$(LIBFT)/ft_strnstr.c			\
	  	$(LIBFT)/ft_atoi.c				\
	  	$(LIBFT)/ft_isspace.c			\
	  	$(LIBFT)/ft_itoa.c				\
	  	$(LIBFT)/ft_strrev.c			\
	  	$(LIBFT)/ft_strsplit.c			\
	  	$(LIBFT)/ft_memset.c			\
	  	$(LIBFT)/ft_memcpy.c			\
	  	$(LIBFT)/ft_memmove.c			\
	  	$(LIBFT)/ft_memccpy.c			\
	  	$(LIBFT)/ft_memchr.c			\
	  	$(LIBFT)/ft_memcmp.c			\
	  	$(LIBFT)/ft_bzero.c				\
	  	$(LIBFT)/ft_strsplit.c			\
	  	$(LIBFT)/ft_count_words.c		\
	  	$(LIBFT)/ft_lstnew.c			\
	  	$(LIBFT)/ft_lstdelone.c			\
	  	$(LIBFT)/ft_lstdel.c			\
	  	$(LIBFT)/ft_lstadd.c			\
	  	$(LIBFT)/ft_lstiter.c			\
	  	$(LIBFT)/ft_lstmap.c			\
	  	$(LIBFT)/ft_isblank.c			\
	  	$(LIBFT)/ft_str_is_alpha.c		\
	  	$(LIBFT)/ft_str_is_lowercase.c	\
	  	$(LIBFT)/ft_str_is_uppercase.c	\
	  	$(LIBFT)/ft_iscntrl.c			\
	  	$(LIBFT)/ft_isgraph.c			\
	  	$(LIBFT)/ft_str_is_numeric.c	\
	  	$(LIBFT)/ft_str_is_printable.c	\
	  	$(LIBFT)/ft_lstaddend.c			\
	  	$(LIBFT)/ft_lstlen.c			\
	  	$(LIBFT)/ft_sqrt.c				\
	  	$(LIBFT)/ft_lsti.c				\
		ft_printf.c
OBJ		=	$(patsubst %.c,%.o,$(SRC))
HFILES	=	$(HEADER)/libftprintf.h
# Name
NAME	=	libftprintf.a

.PHONY: all clean fclean re

all:		$(NAME)
			@true

$(NAME):	$(OBJ) $(HFILES) Makefile
			@echo "Building $(NAME) ..."
			@$(AR) rc $(NAME) $(OBJ)
			@$(RANLIB) $(NAME)
			@echo "The library $(NAME) is ready"

%.o:		%.c
			@echo "Creating $@ ..."
			@$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER)

clean:
			@$(RM) -f $(OBJ)

fclean: clean
			@$(RM) -f $(NAME)

re: fclean all
