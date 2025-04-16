FILES = tools/ft_strncmp.c tools/ft_strlen.c tools/ft_strjoin.c tools/ft_strdup.c tools/ft_strchr.c tools/ft_split.c tools/ft_lstsize.c tools/ft_lstlast.c tools/ft_lstadd_back.c tools/ft_itoa.c tools/ft_isalpha.c tools/ft_isalnum.c \
env.c main.c export.c tools/compare_string.c tools/creat_node.c tools/env_dup.c tools/free_while.c  minishell_cmd.c  tools/find_env.c  my_pwd.c my_echo.c my_cd.c unset.c tools/swap_string.c tools/atoi.c tools/ft_isdigit.c exit.c

NAME = minishell
cc = cc 
FLAGS = -Wall -Wextra -Werror
OBJ = $(FILES:.c=.o)
HEADER1 = minishell.h
HEADER2 = struct.h 
HEADER3 = tools/tools.h

all: $(NAME)
%.o: %.c $(HEADER1) $(HEADER2) $(HEADER3)
	$(CC) $(FLAGS) -c $< -o $@


$(NAME): $(OBJ)
	$(cc) $(FLAGS) $(OBJ) -lreadline -o $(NAME) 

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all