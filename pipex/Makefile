FILE =  pipex.c utils.c
NAME = pipex
CC = cc 

FLAGS =  -Wall -Werror -Wextra 
FILES=$(FILE:.c=.o)

lib=libft/libft.a
 %.o: %.c pipex.h
	@$(CC) $(FLAGS)  -c $< -o $@

all: $(NAME)

$(NAME): $(FILES) pipex.h
	@make -C libft
	@$(CC) $(FLAGS) $(FILES) $(lib) -o $(NAME) 
clean:
	@make clean -C libft
	@rm -rf $(FILES)
	
fclean:clean
	@make fclean -C libft
	@rm -rf $(NAME)
re: fclean all
