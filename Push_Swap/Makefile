# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/20 11:34:36 by codespace         #+#    #+#              #
#    Updated: 2023/07/20 11:43:06 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = ./main.c ./srcs/error.c ./srcs/radix_sort.c ./srcs/sort.c ./srcs/stack_op.c ./srcs/stack_op2.c ./srcs/stack_utils2.c
OBJS = ${SRCS:.c=.o}

INCLUDE =./includes/push_swap.codespace
FLAGS = -Wall -Werror -Wextra

%.o: %.c ${INCLUDE}
		cc${FLAGS} -I ${INCLUDE} -c $< -o $@

${NAME}: ${OBJS}
		make -C ./libft
		cc ${OBJS} -l ./libft -l ft -o ${NAME}
all : ${NAME}

clean: 
		make clean -C .libft
		rm -f ${NAME}
re: fclean all

.PHONY: all clean fclean re