# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 15:04:16 by vkuusela          #+#    #+#              #
#    Updated: 2025/07/09 15:25:23 by vkuusela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			= cc

CFLAGS 		= -Wall -Wextra -Werror -I.

NAME 		= libft.a

RM 			= rm -f

AR 			= ar -rcs

HEADERS		= libft.h

SOURCES 	= ft_isdigit.c \
			  ft_memset.c \
			  ft_strdup.c \
			  ft_strncmp.c \
			  ft_atoi.c \
			  ft_isprint.c \
			  ft_putchar_fd.c \
			  ft_striteri.c \
			  ft_strnstr.c \
			  ft_bzero.c \
			  ft_itoa.c \
			  ft_putendl_fd.c \
			  ft_strjoin.c \
			  ft_strrchr.c \
			  ft_calloc.c \
			  ft_memchr.c \
			  ft_putnbr_fd.c \
			  ft_strlcat.c \
			  ft_strtrim.c \
			  ft_isalnum.c \
			  ft_memcmp.c \
			  ft_putstr_fd.c \
			  ft_strlcpy.c \
			  ft_substr.c \
			  ft_isalpha.c \
			  ft_memcpy.c \
			  ft_split.c \
			  ft_strlen.c \
			  ft_tolower.c \
			  ft_isascii.c \
			  ft_memmove.c \
			  ft_strchr.c \
			  ft_strmapi.c \
			  ft_toupper.c \
			  ft_lstnew.c \
			  ft_lstadd_front.c \
			  ft_lstsize.c \
			  ft_lstadd_back.c \
			  ft_lstdelone.c \
			  ft_lstclear.c \
			  ft_lstiter.c \
			  ft_lstmap.c \
			  ft_lstlast.c \
			  ft_printf.c \
			  ft_hex_print.c \
			  ft_string_print.c \
			  ft_number_print.c \
			  ft_free.c \
			  get_next_line.c \
			  ft_abs.c \
			  ft_free_str_arr.c \
			  ft_strcmp.c

OBJECTS 	= $(SOURCES:.c=.o)

%.o:		%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)


clean:
	$(RM) $(OBJECTS) $(B_OBJECTS)

fclean:		clean
	$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re
