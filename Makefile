NAME = cub3d

SRC = $(wildcard *.c)

OBJ = $(SRC:%.c=%.o)

CFLAG =  -Wall -Wextra -Werror

MLX = mlx/libmlx.a

all : $(OBJ)
	@make -C mlx/
	@make -C 42-Libft/
	@gcc $(CFLAG) $(SRC) $(MLX) 42-Libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) -ggdb

clean :
	@make clean -C mlx/
	@rm -rf *.o

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re

norm :
	norminette
