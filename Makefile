NAME = cub3d

SRC = $(wildcard *.c)

OBJ = $(SRC:%.c=%.o)

CFLAG = -Wall -Wextra -Werror

MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit mlx/libmlx.a

42-GET_NEXT_LINE = 42-Get_next_line/get_next_line.c 42-Get_next_line/get_next_line_utils.c

Libft = Libft/libft.a

all : $(OBJ)
	@make -C mlx/
	@make -C Libft/
	@gcc $(CFLAG) $(SRC) $(Libft) $(MLX) -o $(NAME) -ggdb -fsanitize=address

clean :
	@make clean -C mlx/
	@rm -rf *.o

fclean : clean
	@rm -rf 

re : fclean all

.PHONY : all clean fclean re

norm :
	norminette
