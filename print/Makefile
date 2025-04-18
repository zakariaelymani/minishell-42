NAME  = libftprintf.a
FILES = putadres.c putchar.c putnber.c putunbr.c putuHEX.c putstr.c puthex.c ft_printf.c
CC = cc 
FLAGE = -Wall -Wextra -Werror
OBFILS = $(FILES:.c=.o)
CREATE =  ar rcs
HEADER = ft_printf.h
RM = rm -f

%.o : %.c $(HEADER)
	$(CC) $(FLAGE) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBFILS)
	$(CREATE) $(NAME) $(OBFILS) 
clean:
	$(RM) $(OBFILS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
