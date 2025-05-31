# FILES = builtins/env.c builtins/exit.c builtins/export_utils.c builtins/export.c builtins/minishell_cmd.c builtins/my_cd.c builtins/my_echo.c tools/ft_lstlast.c builtins/my_pwd.c builtins/unset.c tools/ft_isalpha.c tools/ft_isalnum.c \
#  main.c tools/compare_string.c tools/creat_node.c tools/env_dup.c tools/free_while.c  tools/find_env.c  tools/swap_string.c tools/atoi.c tools/ft_isdigit.c tools/ft_lstsize.c tools/ft_open.c tools/ft_putstr_fd.c \
#  tools/here_doc.c  tools/hard_code_env.c tools/ft_strncmp.c tools/ft_lstadd_back.c tools/ft_itoa.c tools/ft_strlen.c tools/ft_split.c tools/ft_strdup.c tools/ft_strjoin.c tools/free_and_joined.c\
#  tools/change_value_struct_env.c tools/ft_strchr.c   parsing.c tools/find_path.c tools/ft_strlcpy.c tools/ft_substr.c tools/last_node_cmd.c tools/cmd_size.c tools/convert_to_array.c excuting_files.c/check_is_builtins.c  \
# excuting_files.c/open_files.c excuting_files.c/dup_input_output.c excuting_files.c/dup_fd_pipe.c excuting_files.c/excute.c tools/add_ifnot_exists.c
FILES = builtins/env.c \
	builtins/exit.c \
    builtins/export.c \
    builtins/export_utils.c \
    builtins/minishell_cmd.c \
    builtins/my_cd.c \
    builtins/my_echo.c \
    builtins/my_pwd.c \
    builtins/unset.c \
	excuting_files/check_is_builtins.c \
    excuting_files/dup_fd_pipe.c \
    excuting_files/dup_input_output.c \
    excuting_files/excute.c \
    excuting_files/open_files.c \
	main.c \
	tools/ft_lstadd_back.c \
    tools/ft_lstlast.c \
    tools/ft_lstsize.c \
	tools/atoi.c \
    tools/compare_string.c \
    tools/creat_node.c \
    tools/env_dup.c \
    tools/free_and_joined.c \
    tools/free_while.c \
    tools/find_env.c \
    tools/find_path.c \
    tools/hard_code_env.c \
    tools/swap_string.c \
	tools/ft_open.c \
    tools/ft_putstr_fd.c \
    tools/ft_isalpha.c \
    tools/ft_isdigit.c \
    tools/ft_itoa.c \
    tools/ft_strlen.c \
    tools/ft_strchr.c \
    tools/ft_strlcpy.c \
    tools/ft_strncmp.c \
    tools/ft_split.c \
    tools/ft_strjoin.c \
    tools/ft_strdup.c \
    tools/ft_substr.c \
	tools/add_ifnot_exists.c \
    tools/change_value_struct_env.c \
	tools/here_doc.c \
	tools/last_node_cmd.c \
    tools/cmd_size.c \
	tools/convert_to_array.c \
	tools/ms_cmdappend.c \
	tools/ms_cmdlast.c \
	tools/ms_cmdnew.c \
	tools/ms_tokappend.c \
	tools/ms_tokclear.c \
	tools/ms_tokdelone.c \
	tools/ms_toklast.c \
	tools/ms_toknew.c \
	tools/ms_toksize.c \
	parsing/syntax_check.c \
	parsing/ms_tokenizer.c \
	parsing/get_word.c \
	parsing/parse.c \
	tools/return_value.c \
	tools/clear_function.c \
	tools/get_env.c \
	tools/ft_lstadd_front_bonus.c \
	tools/ft_isalnum.c \
	tools/ft_isspace.c

NAME = minishell
cc = cc 
FLAGS = -I. -I./parsing -g -Wall -Wextra -Werror # -fsanitize=address
OBJ = $(FILES:.c=.o)
HEADER1 = builtins/builtins.h
HEADER2 = struct.h 
HEADER3 = tools/tools.h
HEADER4 = minishell.h


all: $(NAME)

%.o: %.c $(HEADER1) $(HEADER2) $(HEADER3) $(HEADER4)
	$(CC) $(FLAGS)   -c $< -o $@ 


$(NAME): $(OBJ)
	$(cc) $(FLAGS) $(OBJ)  -lreadline -lbsd  -o   $(NAME) 



clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
