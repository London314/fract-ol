# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omougel <omougel@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 17:02:16 by omougel           #+#    #+#              #
#    Updated: 2024/03/21 06:52:17 by omougel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all mlx_linux clean fclean re

NAME = fractol

SRCS_FILES = events.c\
			 fractol.c\
			 init.c\
			 math_utils.c\
			 render.c\
			 string_utils.c

INCLUDES = include/fractol.h

SRCS_DIR = srcs/
OBJS_DIR = .objects/
MLX_DIR = mlx_linux

SRCS = $(addprefix ${SRCS_DIR},${SRCS_FILES})
OBJS = $(patsubst %.c, ${OBJS_DIR}%.o, ${SRCS})

CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

HEADER = include/fractol.h

all: mlx_linux ${NAME}
	@echo "${BOLD}${GREEN}${NAME} done!${END}"

${NAME}: ${OBJS} ${LIBFT} 
	cc ${CFLAGS} ${OBJS} ${MLXFLAGS} -o ${NAME}  

mlx_linux:
	make -C ${MLX_DIR}

${OBJS_DIR}%.o: %.c ${INCLUDES} Makefile
	mkdir -p $(shell dirname $@)
	cc ${CFLAGS} -I/usr/include -Imlx_linux -O2 -c $< -o $@

clean:
	${MAKE} -C ${MLX_DIR} clean
	rm -rf ${OBJS_DIR}
	@echo "${BOLD}${RED}$@ done!${END}"

fclean: clean
	rm -f ${NAME}
	@echo "${BOLD}${RED}$@ done!${END}"

re: fclean all

RED = \033[31m
GREEN = \033[32m
BOLD = \033[1m
END = \033[0m
