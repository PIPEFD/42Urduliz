# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/08 11:13:42 by codespace         #+#    #+#              #
#    Updated: 2023/11/20 23:11:09 by dbonilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	push_swap
MAIN		=	push_swap.c
LIBFT		=	libft/libft.a
INC			=	includes/
SRC_DIR		=	src/


CC			=	gcc -fsanitize=address -g3
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f


SRC_FILES	=	ft_push.c ft_swap.c ft_rotate.c ft_rotater.c ft_size_argv.c \
				ft_size_5.c ft_size_2_3.c ft_rotates.c ft_check.c  \
				ft_size_big.c ft_args.c ft_const.c


SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			= 	$(SRC:.c=.o)

# **************************************************************************** #

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJ)
			@$(CC) $(FLAGS) $(MAIN) $(OBJ) $(LIBFT) -I$(INC) -o $(NAME)
			@echo "push_swap compiled!"

$(LIBFT):
			make -C ./libft

print:		$(LIBFT) $(OBJ)
			@$(CC) $(FLAGS) $(MAIN) -D PR=1 $(OBJ) $(LIBFT) -I$(INC) -o $(NAME)
			@echo "push_swap compiled!"
.c.o:
			@echo "Compiling:"
			@$(CC) $(FLAGS) -I$(INC) -c $< -o $(<:.c=.o)

clean:
			@$(RM) $(OBJ) 
			@echo "file removed."
			@make clean -C ./libft

fclean:		clean
			@make fclean -C ./libft
			@$(RM) $(NAME) checker
			@echo "$(NAME)removed!"

re:			fclean all

.PHONY:		all clean fclean re libft print