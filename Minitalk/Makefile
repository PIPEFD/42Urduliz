# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 20:20:19 by codespace         #+#    #+#              #
#    Updated: 2023/12/02 00:22:36 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
MAIN		=	ft_push_swap.c
LIBFT		=	libft/libft.a
INC			=	inc/
SRC_DIR		=	src/


CC			=	gcc -g3
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

SRC_FILES	=	../src/client.c ../src/server.c \


SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			= 	$(SRC:.c=.o)

# **************************************************************************** #

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJ)
			@$(CC) $(FLAGS) $(MAIN) $(OBJ) $(LIBFT) -I$(INC) -o $(NAME)
			@echo "$(GREEN)push_swap compiled!$(DEF_COLOR)"

$(LIBFT):
			@make -C ./libft

print:		$(LIBFT) $(OBJ)
			@$(CC) $(FLAGS) $(MAIN) -D PR=1 $(OBJ) $(LIBFT) -I$(INC) -o $(NAME)
			@echo "$(GREEN)push_swap compiled!$(DEF_COLOR)"
.c.o:
			@echo "$(BLUE)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(FLAGS) -I$(INC) -c $< -o $(<:.c=.o)

clean:
			@$(RM) $(OBJ) 
			@echo "$(YELLOW)$(OBJ) file removed.$(DEF_COLOR)"
			@make clean -C ./libft

fclean:		clean
			@make fclean -C ./libft
			@$(RM) $(NAME) checker
			@echo "$(RED)$(NAME) removed!$(DEF_COLOR)"

re:			fclean all

.PHONY:		all clean fclean re libft print