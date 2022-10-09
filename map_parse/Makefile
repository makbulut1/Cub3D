NAME = map.a

SRC = map_control.c control.c error.c file.c check.c parse.c free.c space_control.c\
zero_control.c

OBJ = $(SRC:%.c=%.o)

CC = gcc
CFLAGS = -g

all : $(OBJ) 
	@ar rcs $(NAME) $(OBJ) 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf *.o

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re 

norm :
	norminette