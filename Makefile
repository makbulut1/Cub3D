NAME = cub3d

SRC = $(wildcard *.c)

OBJ = $(SRC:%.c=%.o)

CFLAG = -Wall -Wextra -Werror

MLX = mlx/libmlx.a

all : $(OBJ)
	@make -C mlx/
	@gcc $(CFLAG) $(SRC) $(MLX) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	@make clean -C mlx/
	@rm -rf *.o

fclean : clean

re : fclean all

.PHONY : all clean fclean re

norm :
	norminette
