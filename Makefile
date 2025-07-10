# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkuusela <vkuusela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/09 15:40:55 by vkuusela          #+#    #+#              #
#    Updated: 2025/07/09 15:41:41 by vkuusela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

		### BASICS ###

NAME 			= miniRT
CC 				= cc
CFLAGS 			= -Wall -Wextra -Werror -I.
LFLAGS			= -ldl -lglfw -pthread -lm
OFLAGS			= -O3 -flto -march=native
RM 				= rm -rf
VALGRIND		= valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes --show-reachable=yes --suppressions=mlx42.supp
FILE			= maps/test.rt
OBJDIR			= obj

		### LIBRARIES ###

LIBFT			= libft/libft.a
MLX42			= MLX42/build/libmlx42.a

		### SOURCE ###

SOURCES			= src/main.c src/parsing/reading_file.c src/parsing/parsing_utils.c src/parsing/parsing.c \
				  src/parsing/validation.c src/parsing/ft_atof.c src/parsing/exit_functions.c \
				  src/parsing/camera.c  src/parsing/light.c  src/parsing/shapes.c\
				  src/math/vector_operations.c src/math/vector_products.c \
				  src/math/vector_properties.c src/rendering/color.c \
				  src/rendering/camera.c src/rendering/ray.c src/rendering/render_loop.c \
				  src/rendering/hit_detection.c src/rendering/shading.c src/rendering/colors_functions.c\
				  src/rendering/shadow.c src/math/quaternion.c src/rendering/cylinder_detection.c

HEADERS			= minirt.h

OBJECTS			= $(SOURCES:%.c=$(OBJDIR)/%.o)

$(OBJDIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(OFLAGS) -c $< -o $@
	
all: 			$(NAME)

$(NAME):		$(LIBFT) $(MLX42) $(OBJECTS)
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OFLAGS) $(OBJECTS) $(LIBFT) $(MLX42) $(LFLAGS) -o $(NAME)

$(LIBFT):
	@echo "Compiling libft..."
	@make -C libft/ --no-print-directory

$(MLX42):
	@echo "Compiling MLX42..."
	@if [ ! -d "MLX42" ]; then git clone https://github.com/codam-coding-college/MLX42.git; fi
	@(cd MLX42/ && cmake -B ./build && cmake --build ./build -j4)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@echo "Cleaning objects..."
	@$(RM) $(OBJECTS) $(OBJDIR)
	@(cd libft/ && make clean)

fclean:			clean
	@echo "Full clean..."
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)
	@$(RM) MLX42/build/libmlx42.a

re:				fclean all

run:			all
	@$(VALGRIND) ./$(NAME) $(FILE)

debug:			CFLAGS += -g
debug:			OFLAGS = -Og
debug:			re

fsanitize:		CFLAGS += -g -fsanitize=address
fsanitize:		OFLAGS = -Og
fsanitize:		re

gprof:			CFLAGS += -g -pg
gprof:			OFLAGS = -Og
gprof:			re

norminette:
	norminette $(SOURCES) $(HEADERS) ./libft

.PHONY:			all clean fclean re run fsanitize debug gprof norminette
