		### BASICS ###

NAME 			= minirt
CC 				= gcc
CFLAGS 			= -g -o -Wall -Wextra -Werror -I.
LFLAGS			= -ldl -lglfw -pthread -lm
RM 				= rm -rf
VALGRIND		= valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes --show-reachable=yes --suppressions=mlx.supp
FILE			= test.rt

		### LIBRARIES ###

LIBFT			= libft/libft.a
MLX42			= MLX42/build/libmlx42.a

		### SOURCE ###

SOURCES			= src/main.c src/parsing/reading_file.c src/parsing/parsing_utils.c

HEADERS			= minirt.h

OBJECTS			= $(SOURCES:.c=.o)

%.o:			%.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@

all: 			$(NAME)

$(NAME):		$(LIBFT) $(MLX42) $(OBJECTS)
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MLX42) $(LFLAGS) -o $(NAME)

$(LIBFT):
	@echo "Compiling libft..."
	@make -C libft/ --no-print-directory

$(MLX42):
	@echo "Compiling MLX42..."
	@if [ ! -d "MLX42" ]; then git clone https://github.com/codam-coding-college/MLX42.git; fi
	@(cd MLX42/ && cmake -B ./build && cmake --build ./build -j4)

clean:
	@echo "Cleaning objects..."
	@$(RM) $(OBJECTS)
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
debug:			re

fsanitize:		CFLAGS += -g -fsanitize=address
fsanitize:		re

gprof:			CFLAGS += -g -pg
gprof:			re

norminette:
	norminette $(SOURCES) $(HEADERS) ./libft

.PHONY:			all clean fclean re run fsanitize debug gprof norminette
