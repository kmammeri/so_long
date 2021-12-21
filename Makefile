NAME = so_long

SRCS = ./sources/so_long.c ./sources/so_long_utils.c ./sources/get_next_line.c ./sources/get_next_line_utils.c ./sources/movement.c ./sources/mapping.c ./sources/printmap.c ./sources/check.c 

OBJS = ${SRCS:.c=.o}

SRCS_BONUS = ./bonus/so_long_bonus.c ./bonus/so_long_utils_bonus.c ./bonus/get_next_line_bonus.c \
./bonus/get_next_line_utils_bonus.c ./bonus/movement_bonus.c ./bonus/mapping_bonus.c \
./bonus/printmap_bonus.c ./bonus/check_bonus.c ./bonus/animation_bonus.c ./bonus/ft_itoa_bonus.c \
./bonus/enemy_bonus.c ./bonus/so_many_functions_bonus.c ./bonus/sprites_bonus.c

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

CC		= gcc
RM		= rm -f

MINILIBX = ./opengl/

CFLAGS = -Wall -Wextra -Werror

%.o: %.c ./includes/so_long.h ./includes/so_long_bonus.h
		${CC} ${CFLAGS} -c $< -o $@

all:	${NAME}

$(NAME): ${OBJS}
		make -C ${MINILIBX}
		${CC} ${CFLAGS} -framework OpenGL -framework AppKit -o $@ $^ opengl/libmlx.a

bonus: ${OBJS_BONUS}
		make -C ${MINILIBX}
		${CC} ${CFLAGS} -framework OpenGL -framework AppKit -o ${NAME} $^ opengl/libmlx.a

clean:
		make clean -C ${MINILIBX}
		${RM} ${OBJS} ${OBJS_BONUS}
 
fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re bonus