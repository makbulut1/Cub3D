NAME = cub3d

SRC = $(wildcard *.c)

MAP  = map_parse/map.a

OBJ = $(SRC:%.c=%.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit mlx/libmlx.a

42-GET_NEXT_LINE = 42-Get_next_line/get_next_line.c 42-Get_next_line/get_next_line_utils.c

Libft = Libft/libft.a

all : $(OBJ)
	@make -C mlx/
	@make -C Libft/
	@make -C map_parse/
	@$(CC) $(CFLAGS) $(OBJ) $(MAP) -I./map_parse/map_parse.h $(Libft) $(MLX) -o $(NAME) -fsanitize=address

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@make clean -C mlx/
	@make clean -C map_parse/
	@rm -rf *.o

fclean : clean
	@make fclean -C Libft
	@make fclean -C map_parse/
	@rm -rf 

re : fclean all

.PHONY : all clean fclean re deneme testdeneme

norm :
	norminette