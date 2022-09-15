NAME = cub3d

SRC = $(wildcard *.c)

OBJ = $(SRC:%.c=%.o)

CFLAG = # -Wall -Wextra -Werror

MLX = mlx/libmlx.a

all : $(OBJ)
	@make -C mlx/
	@make -C 42-Libft/
	@gcc $(CFLAG) $(SRC) $(MLX) 42-Libft/libft.a 42-Get_next_line/get_next_line.c 42-Get_next_line/get_next_line_utils.c -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) -ggdb

clean :
	@make clean -C mlx/
	@rm -rf *.o

fclean : clean

re : fclean all

.PHONY : all clean fclean re

norm :
	norminette
