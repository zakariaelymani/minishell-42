BUILTINS = builtins/env.c \
		   builtins/exit.c \
		   builtins/export_utils.c \
		   builtins/my_cd.c \
		   builtins/my_echo.c \
		   builtins/export.c \
		   builtins/unset.c \
		   builtins/my_pwd.c \
		   builtins/minishell_cmd.c \

EXECUTE = executing_files/check_is_builtins.c \
		  executing_files/dup_fd_pipe.c \
		  executing_files/dup_input_output.c \
		  executing_files/open_files.c \
		  executing_files/execute.c

TOOLS_HELP = tools/tools_env/add_ifnot_exists.c \
			 tools/tools_env/change_value_struct_env.c \
			 tools/tools_env/convert_to_array.c \
			 tools/tools_env/creat_node.c \
			 tools/tools_env/get_env.c \
			 tools/tools_env/hard_code_env.c \
			 tools/tools_env/return_value.c \
			 tools/tools_libft/ft_isalnum.c \
			 tools/tools_libft/ft_isalpha.c \
			 tools/tools_libft/ft_isdigit.c \
			 tools/tools_libft/ft_itoa.c \
			 tools/tools_libft/ft_lstadd_back.c \
			 tools/tools_libft/ft_lstadd_front_bonus.c \
			 tools/tools_libft/ft_lstlast.c \
			 tools/tools_libft/ft_lstsize.c \
			 tools/tools_libft/ft_memcpy.c \
			 tools/tools_libft/ft_memset.c \
			 tools/tools_libft/ft_putstr_fd.c \
			 tools/tools_libft/ft_split.c \
			 tools/tools_libft/ft_strchr.c \
			 tools/tools_libft/ft_strdup.c \
			 tools/tools_libft/ft_strjoin.c \
			 tools/tools_libft/ft_strlcpy.c \
			 tools/tools_libft/ft_strlen.c \
			 tools/tools_libft/ft_strncmp.c \
			 tools/tools_libft/ft_substr.c \
			 tools/atoi.c \
			 tools/cmd_size.c \
			 tools/free_and_joined.c \
			 tools/free_while.c \
			 tools/here_doc.c \
			 tools/last_node_cmd.c \
			 tools/swap_string.c \
			 tools/ft_open.c \
			 tools/tools_env/find_path.c \
			 tools/tools_env/env_dup.c \
			 main.c \
			 tools/tools_env/find_env.c \
			 tools/compare_string.c \
			 tools/tools_env/clear_function.c \

PARSING = parsing.c \
		  readline_bonus.c

NAME = minishell
CC = cc
OBJ = $(BUILTINS:.c=.o) \
	  $(TOOLS_HELP:.c=.o) \
	  $(PARSING:.c=.o) \
	  $(EXECUTE:.c=.o)

FLAGS = -Wall -Wextra -Werror -g -fsanitize=address 
HEADER1 = builtins/builtins.h
HEADER2 = struct.h
HEADER3 = tools/tools.h
HEADER4 = minishell.h
HEADER5 = executing_files/excute_header.h

all: $(NAME)

%.o: %.c $(HEADER1) $(HEADER2) $(HEADER3) $(HEADER4) $(HEADER5)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -lreadline -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re