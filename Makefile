# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omougel <omougel@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 17:02:16 by omougel           #+#    #+#              #
#    Updated: 2024/03/18 12:07:30 by omougel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all libft mlx_linux clean fclean re

NAME = fractol

SRCS_FILES = events.c\
			 fractol.c\
			 init.c\
			 math_utils.c\
			 render.c

INCLUDES = include/fractol.h

LIBFT_DIR = libft/
SRCS_DIR = srcs/
OBJS_DIR = .objects/
MLX_DIR = mlx_linux

SRCS = $(addprefix ${SRCS_DIR},${SRCS_FILES})
OBJS = $(patsubst %.c, ${OBJS_DIR}%.o, ${SRCS})

CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
LIBFT = libft/libft.a

HEADER = include/fractol.h libft/include/libft.h

all: mlx_linux libft ${NAME}
	@echo "${BOLD}${GREEN}${NAME} done!${END}"

${NAME}: ${OBJS} ${LIBFT} 
	cc ${CFLAGS} ${OBJS} ${LIBFT} ${MLXFLAGS} -o ${NAME}  

libft:
	${MAKE} -C ${LIBFT_DIR}
	@echo "${BOLD}${GREEN}$@ done!${END}"

mlx_linux:
	make -C ${MLX_DIR}

${OBJS_DIR}%.o: %.c ${INCLUDES} Makefile
	mkdir -p $(shell dirname $@)
	cc ${CFLAGS} -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	${MAKE} -C ${LIBFT_DIR} clean
	${MAKE} -C ${MLX_DIR} clean
	rm -rf ${OBJS_DIR}
	@echo "${BOLD}${RED}$@ done!${END}"

fclean: clean
	${MAKE} -C ${LIBFT_DIR} fclean
	rm -f ${NAME}
	@echo "${BOLD}${RED}$@ done!${END}"

re: fclean all

RED = \033[31m
GREEN = \033[32m
BOLD = \033[1m
END = \033[0m
