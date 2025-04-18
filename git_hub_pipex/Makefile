FILE =  pipex.c utils.c
NAME = pipex
CC = cc 
bonfile = utils_bonus.c pipex_bonus.c here_doc.c
FLAGS = -Wall -Werror -Wextra 
FILES=$(FILE:.c=.o)
OBJbo = $(bonfile:.c=.o)
lib=libft/libft.a
 %.o: %.c pipex.h
	@$(CC) $(FLAGS)  -c $< -o $@
%.o: %.c pipex_bonus.h 
	@$(CC) $(FLAGS)  -c $< -o $@
all: $(NAME)

$(NAME): $(FILES) pipex.h
	@make -C libft
	@$(CC) $(FLAGS) $(FILES) $(lib) -o $(NAME) 
bonus: ${OBJbo} fclean pipex_bonus.h
	@make -C libft
	@$(CC) $(FLAGS) $(bonfile) $(lib) -o $(NAME)  $(lib)
clean:
	@make clean -C libft
	@rm -rf $(FILES)
	@rm -rf $(OBJbo)
fclean:clean
	@make clean -C libft
	@rm -rf $(NAME)
re: fclean all
