SRCS				= $(addprefix srcs/, ft_strlen.s ft_strcpy.s ft_strcmp.s \
						ft_write.s ft_read.s ft_strdup.s ft_cinstr.s \
						ft_atoi_base_bonus.s ft_create_elem.s \
						ft_list_push_front_bonus.s \
						ft_list_size_bonus.s ft_list_sort_bonus.s \
						ft_list_remove_if_bonus.s)

OBJS				= ${SRCS:.s=.o}

NAME				= libasm.a

CFLAGS				= -Wall -Wextra -Werror

all:				${NAME}

test:				all main.o
					@ld -lc -no_pie -macosx_version_min 10.14 ${NAME} main.o
					#gcc ${CFLAGS} main.o ${NAME}
					@./a.out
					@rm -rf a.out
					@rm -rf test.txt

.s.o:
					nasm -f macho64 $<

.c.o:
					gcc ${CFLAGS} -c $<

$(NAME):			${OBJS}
					ar -rcs ${NAME} ${OBJS}

clean:
					rm -rf ${OBJS} main.o

fclean:				clean
					rm -rf ${NAME}

re:					fclean all

.PHONY:				all clean fclean re test
