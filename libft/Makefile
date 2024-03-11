# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omougel <omougel@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 16:45:04 by omougel           #+#    #+#              #
#    Updated: 2024/03/07 14:36:47 by omougel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libft.a

SRCS = char/ft_isalnum.c\
			 char/ft_isalpha.c\
			 char/ft_isascii.c\
			 char/ft_isdigit.c\
			 char/ft_isprint.c\
			 char/ft_tolower.c\
			 char/ft_toupper.c\
			 gnl/get_next_line.c\
			 gnl/get_next_line_utils.c\
			 lst/ft_lstadd_back.c\
			 lst/ft_lstadd_front.c\
			 lst/ft_lstclear.c\
			 lst/ft_lstdelone.c\
			 lst/ft_lstiter.c\
			 lst/ft_lstlast.c\
			 lst/ft_lstmap.c\
			 lst/ft_lstnew.c\
			 lst/ft_lstsize.c\
			 mem/ft_bzero.c\
			 mem/ft_calloc.c\
			 mem/ft_memchr.c\
			 mem/ft_memcmp.c\
			 mem/ft_memcpy.c\
			 mem/ft_memmove.c\
			 mem/ft_memset.c\
			 numbers/ft_atoi.c\
			 numbers/ft_atol.c\
			 numbers/ft_itoa.c\
			 numbers/ft_max.c\
			 numbers/ft_min.c\
			 printf/ft_displayprintf.c\
			 printf/ft_printf.c\
			 printf/ft_printf_utils.c\
			 put.../ft_putchar_fd.c\
			 put.../ft_putendl_fd.c\
			 put.../ft_putnbr_base.c\
			 put.../ft_putnbr_fd.c\
			 put.../ft_putstr_fd.c\
			 str/ft_split.c\
			 str/ft_strchr.c\
			 str/ft_strcmp.c\
			 str/ft_strdup.c\
			 str/ft_striteri.c\
			 str/ft_strjoin.c\
			 str/ft_strlcat.c\
			 str/ft_strlcpy.c\
			 str/ft_strlen.c\
			 str/ft_strlen_till_c.c\
			 str/ft_strmapi.c\
			 str/ft_strncmp.c\
			 str/ft_strnstr.c\
			 str/ft_strrchr.c\
			 str/ft_strtrim.c\
			 str/ft_substr.c\

INCLUDES = include/libft.h include/ft_printf.h

INC_DIR = include/
OBJS_DIR = .objects/

OBJS = $(patsubst %.c, ${OBJS_DIR}%.o, ${SRCS})

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}
	@echo "${BOLD}${GREEN}${NAME} done!${END}"

${NAME}: ${OBJS}
	ar -rcs ${NAME} ${OBJS}

${OBJS_DIR}%.o: %.c ${INCLUDES} Makefile
	mkdir -p $(shell dirname $@)
	cc ${CFLAGS} -c $< -o $@

clean:
	rm -rf ${OBJS_DIR}
	@echo "${BOLD}${RED}$@ done!${END}"

fclean: clean
	rm -f $(NAME)
	@echo "${BOLD}${RED}$@ done!${END}"

re: fclean all

RED = \033[31m
GREEN = \033[32m
BOLD = \033[1m
END = \033[0m
