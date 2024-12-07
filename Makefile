NAME=libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_printf_utils.c ft_printf_options.c ft_printers.c

HEADER = ft_printf.h  

OBJS = $(SRC:.c=.o)

all: $(NAME)
	@echo "\n(•̀ᴗ•́)و $(NAME) generado!(•̀ᴗ•́)\n"
$(NAME): $(OBJS)
#	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -> si fuera un ejecutable, ahora ar rc para hacer libreria
	ar rc $(NAME) $(OBJS)
	@echo "\ngenerado: $(OBJS)\n"
$(OBJS): $(SRC) ft_printf.h 
	$(CC) $(CFLAGS) -c $(SRC) 

clean:
	rm -f $(OBJS) 

fclean:
	rm -f *.o
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re  