SRCS				= $(addprefix srcs/, ft_strlen.s ft_strcpy.s ft_strcmp.s \
						ft_write.s ft_read.s)

OBJS				= ${SRCS:.s=.o}

NAME				= libasm.a

CFLAGS				= -Wall -Wextra -Werror

test:				all
					@gcc ${CFLAGS} ${NAME} main.c
					@./a.out
					@rm -rf a.out

all:				${NAME}

.s.o:
					nasm -f macho64 $<

$(NAME):			${OBJS}
					ar -rcs ${NAME} ${OBJS}

clean:
					rm -rf ${OBJS}

fclean:				clean
					rm -rf ${NAME}

re:					fclean all

.PHONY:				all clean fclean re test
