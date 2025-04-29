FILES = builtins/env.c builtins/exit.c builtins/export_utils.c builtins/export.c builtins/minishell_cmd.c builtins/my_cd.c builtins/my_echo.c tools/ft_lstlast.c builtins/my_pwd.c builtins/unset.c tools/ft_isalpha.c tools/ft_isalnum.c \
 main.c tools/compare_string.c tools/creat_node.c tools/env_dup.c tools/free_while.c    tools/find_env.c  tools/swap_string.c tools/atoi.c tools/ft_isdigit.c tools/ft_lstsize.c tools/ft_open.c tools/ft_putstr_fd.c \
 open_files.c excute.c check_is_builtins.c tools/here_doc.c  tools/hard_code_env.c tools/ft_strncmp.c tools/ft_lstadd_back.c tools/ft_itoa.c tools/ft_strlen.c tools/ft_split.c tools/ft_strdup.c tools/ft_strjoin.c tools/free_and_joined.c\
 tools/change_value_struct_env.c tools/ft_strchr.c 
NAME = minishell
cc = cc 
FLAGS = #-Wall -Wextra -Werror
OBJ = $(FILES:.c=.o)
HEADER1 = builtins/builtins.h
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