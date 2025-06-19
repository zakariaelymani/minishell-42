FILES = builtins/env.c \
	builtins/exit.c \
    builtins/export.c \
    builtins/export_utils.c \
    builtins/minishell_cmd.c \
    builtins/my_cd.c \
    builtins/my_echo.c \
    builtins/my_pwd.c \
    builtins/unset.c \
	executing_files/check_is_builtins.c \
    executing_files/dup_fd_pipe.c \
    executing_files/dup_input_output.c \
    executing_files/execute.c \
    executing_files/open_files.c \
	main.c \
	tools/tools_libft/ft_lstadd_back.c \
    tools/tools_libft/ft_lstlast.c \
    tools/tools_libft/ft_lstsize.c \
	tools/atoi.c \
    tools/compare_string.c \
    tools/tools_env/env_dup.c \
    tools/free_and_joined.c \
    tools/free_while.c \
    tools/tools_env/find_path.c \
    tools/tools_env/hard_code_env.c \
    tools/swap_string.c \
	tools/ft_open.c \
	tools/tools_libft/ft_cpynbr.c\
    tools/tools_libft/ft_lstadd_front_bonus.c\
    tools/tools_libft/ft_putstr_fd.c \
	tools/tools_libft/ft_isalnum.c\
    tools/tools_libft/ft_isalpha.c\
    tools/tools_libft/ft_isdigit.c \
    tools/tools_libft/ft_itoa.c \
    tools/tools_libft/ft_strlen.c \
    tools/tools_libft/ft_strchr.c \
    tools/tools_libft/ft_strlcpy.c \
    tools/tools_libft/ft_strncmp.c \
    tools/tools_libft/ft_split.c \
    tools/tools_libft/ft_strjoin.c \
    tools/tools_libft/ft_strdup.c \
    tools/tools_libft/ft_substr.c \
    tools/tools_libft/ft_isspace.c \
	tools/tools_libft/ft_memmove.c\
	tools/tools_libft/ft_strrchr.c\
    tools/tools_libft/ft_strnstr.c\
	tools/tools_env/add_ifnot_exists.c \
    tools/tools_env/change_value_struct_env.c \
	tools/here_doc.c \
	tools/last_node_cmd.c \
    tools/cmd_size.c \
    tools/safe_functions.c \
    tools/my_perror.c \
    tools/minishell_signals.c \
    tools/tools_env/clear_function.c \
    tools/tools_env/convert_to_array.c \
    tools/tools_env/creat_node.c \
    tools/tools_env/get_env.c \
    tools/tools_env/find_env.c \
    tools/tools_env/return_value.c \
    tools/tools_libft/ft_memset.c\
    tools/free_vars_if.c \
	tools/tools_parsing/ms_cmdappend.c \
	tools/tools_parsing/ms_cmdlast.c \
	tools/tools_parsing/ms_cmdnew.c \
	tools/tools_parsing/ms_tokappend.c \
	tools/tools_parsing/ms_tokclear.c \
	tools/tools_parsing/ms_tokdelone.c \
	tools/tools_parsing/ms_toklast.c \
	tools/tools_parsing/ms_toknew.c \
	parsing/ms_redirutils.c \
	parsing/syntax_check.c \
	parsing/ms_tokenizer.c \
	parsing/get_word.c \
	parsing/ms_expander.c \
	parsing/quote_utils.c \
	parsing/split_manager.c \
	parsing/expander_utils/expand_size.c \
	parsing/expander_utils/expand_copy.c \
    parsing/expander_utils/expand_tools.c \
    parsing/expander_utils/copy_helpers.c \
	parsing/expander_utils/size_helpers.c \
	parsing/parse.c \
    tools/get_next_line.c \
    tools/safe_malloc.c \

NAME = minishell
CC = cc
RM = rm -rf
FLAGS = -I. -I./parsing -I./tools -Wall -Wextra -Werror -fsanitize=address
OBJ = $(FILES:.c=.o)
HEADER1 = builtins/builtins.h
HEADER2 = struct.h 
HEADER3 = tools/tools.h
HEADER4 = minishell.h
HEADER5 = parsing/parsing.h
HEADER6 = executing_files/execute_header.h

HEADERS =  $(HEADER1) $(HEADER2) $(HEADER3) $(HEADER4) $(HEADER5) $(HEADER6)
all: $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@ 

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ)  -lreadline -o   $(NAME) 

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
