BLACK			=	"\033[0;30m"
RED				=	"\033[0;31m"
GREEN			=	"\033[0;32m"
YELLOW			=	"\033[0;33m"
CYAN			=	"\033[0;35m"
BLUE			=	"\033[0;36m"
WHITE			=	"\033[0;37m"
END				=	"\033[0;0m"

GET_OS := $(shell uname -s)

ifeq ($(GET_OS), Darwin)
	OS			=		MACOS
	LINK		=		https://projects.intra.42.fr/uploads/document/document/9232/minilibx_opengl.tgz
	ARCHIEVE	=		minilibx_opengl.tgz
	FOLDER		=		minilibx_opengl_20191021
else
	OS			=		LINUX
	LINK		=		https://projects.intra.42.fr/uploads/document/document/9225/minilibx-linux.tgz
	ARCHIEVE	=		minilibx-linux.tgz
	FOLDER		=		minilibx-linux
endif

DIR				= $(shell echo $(PWD))
RM				= rm -rf
NAME			= minilibx

LIB				= ./.$(NAME)

all : $(LIB)

clean :

fclean : 
	@echo $(YELLOW) "Removing $(NAME)..." $(END)
	@$(RM) $(NAME)* $(LIB)
	@echo $(RED) "$(NAME) deleted successfully!\n" $(END)

re : fclean all

$(LIB):
	@curl -O $(LINK)
	@gunzip -c $(ARCHIEVE) | tar xopf -
	@mv $(FOLDER) $(NAME)
	make -C $(NAME)
	@$(RM) *.tgz
	@mkdir $(LIB)

.PHONY: all  fclean re