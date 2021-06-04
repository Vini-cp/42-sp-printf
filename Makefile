NAME = printf.a

SRCS_LIST = ft_printf_putchar.c ft_printf_print.c ft_printf_print_p_str.c \
ft_printf_print_c.c ft_printf_isflag.c ft_printf_empty_zeros.c ft_ptoa.c \
ft_printf_get_flag.c ft_printf_newflag.c to_string.c ft_ctoa.c ft_printf.c \
ft_utoa.c

FOLDER = src

SRCS = $(addprefix ${FOLDER}/, ${SRCS_LIST})

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Werror -Wextra

INCLUDE = -I./include

all : $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C ./42-sp-libft
	@cp 42-sp-libft/libft.a $(NAME)
	@ar -rcs $(NAME) $(OBJS)

clean :
	@$(MAKE) clean -C ./42-sp-libft
	@rm -rf *.o
	@rm -rf ./src/*.o

fclean : clean
	@$(MAKE) fclean -C ./42-sp-libft
	@rm -rf $(NAME)
	

re : fclean all

test:
	@gcc $(RUNFLAGS) $(TEST) ./$(NAME) \
	&& ./a.out \
	&& rm ./a.out

.PHONY: all clean fclean re
