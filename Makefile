NAME = 	fractol

SRC = 	src/main.c \
		src/mouse.c \
		src/show.c \
		src/hook.c \
		src/fractals.c \
		src/fractals_bonus.c \

FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@gcc -o $@ -c $< 

$(NAME): $(OBJ)
	@echo "\033[35m(ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ Compiling... Wait a sec.\033[0m"
	@make -C libft
	@gcc -o $(NAME) $(FLAGS) $(OBJ) libft/libft.a -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit
	@echo "\033[36m(•̀ᴗ•́)و $(NAME) generated!\033[0m"

clean:
	@make clean -C libft
	@rm -f $(OBJ)
	@echo "\033[33m¯\_(ツ)_/¯ Objects removed!\033[0m"

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@echo "\033[33m(╯°□°）╯︵ ┻━┻ $(NAME) removed!\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re