CC= gcc
CFLAGS= -Wall -Wextra -Werror -fsanitize=address -g
RM=rm -f
NAME=push_swap
SRCS=ft_atoi.c \
	 ft_calloc.c \
	 ft_checks.c \
	 ft_errors.c \
	 ft_itoa.c \
	 ft_push_swap.c \
	 ft_split.c \
	 ft_strdup.c \
	 ft_strjoin.c \
	 ft_strlen.c \
	 ft_list.c \
	 ft_substr.c \
	 ft_sort_three.c \
	 ft_sort_five.c \
	 ft_sort_more.c \
	 ft_movements.c \
	 ft_movements_second.c \
	 ft_algo.c \
	 ft_algo_big.c \
	 ft_get_bottom_and_top.c \
	 ft_list_second.c \
	 ft_list_third.c \

OBJS=${SRCS:.c=.o}

all:	${NAME}

${NAME}:	${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
