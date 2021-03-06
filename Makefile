NAME = 				fdf

CC = 				gcc

CFLAGS = 			-Wall -Wextra -Werror -g
GFLAGS =			-lmlx -framework OpenGL -framework AppKit

#Headers infos
HEA_PATH = 			./src
HEA_NAME = 			fdf.h
HEA = 				$(addprefix $(HEA_PATH)/,$(HEA_NAME))

#Sources infos
SRC_PATH = 			./src
SRC		 = 			$(wildcard $(SRC_PATH)/*.c)

#Objects infos
OBJ_PATH = 			./src
# OBJ_NAME = 			$(SRC_NAME:.c=.o)
OBJ = 				$(SRC:.c=.o)

all: $(NAME)

$(NAME): 			$(OBJ) $(HEA)
					@make -C libft/
					@$(CC) $(CFLAGS) $(OBJ) $(GFLAGS) libft/libft.a -o $(NAME)
					@echo "FdF compilation complete."

%.o: 				%.c $(HEA)
					@$(CC) $(CFLAGS) -c $< -o $@ 

clean:				
					@rm -rf $(OBJ)
					@make -C libft clean
					@echo "Object files deleted." 

fclean: 			clean
					@make -C libft fclean
					@rm -rf $(NAME) 
					@echo "Executable deleted."

re: 				fclean all

.PHONY: 			all clean fclean re