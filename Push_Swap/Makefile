# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/08 11:13:42 by codespace         #+#    #+#              #
#    Updated: 2023/08/08 17:04:29 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
MAIN	=	ft_push_swap.c
LIBFT	=	libft/libft.a
INC		=	inc/
SRC_DIR	=	src/

CC		= gcc
FLAGS	=	-wall -wextra -werror
RM		=		rm -f


SRC_FILES	=	ft_push.c ft_swap.c ft_rotate.c ft_rev_rotate.c ft_sort.c \
					ft_sort_5.c ft_sort_2_3.c ft_visualize.c ft_smart_rotate.c \
					ft_sort_big.c ft_input_to_args.c ft_sort_big_cost.codespace

SRC			=		$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			=		$(BONUS:.c=.o)

# ----------------------------------------------------------------------------- #

all:		$(NAME)

$(NAME):		$(LIBFT) &(OBJ)
						@$(CC) $(FLAGS) $(MAIN) $(OBJ) &(LIBFT) -I$(INC) -o $(NAME)
						@echo "$(GREEN)push_swap compiled!$(DEF_COLOR)"

$(LIBFT):
						@make -C ./libft
						
bonus:			$(LIBFT) $(OBJ) $(OBJ_B)
						@$(CC) $(FLAGS) $(OBJ) $(OBJ_B) $(LIBFT) -I$(INC) -o checker
						@echo "$(GREEN) checker compiled!$(DEF_COLOR)"

print:			$(LIBFT) $(OBJ)
						@$(CC) $(FLAGS) $(MAIN) -D PR=1 $(OBJ) $(LIBFT) -I$(INC) -o $(NAME)
						@echo "$(GREEN)push_swap compiled!$(DEF_COLOR)"
.c.	o
					@echo "$(BLUE)Compiling: $< $(DEF_COLOR)"
					@$(CC) $(FLAGS) -I$(INC) -c $< -o $(<:.c=.o)

clean:
					@$(RM) $(OBJ) $(OBJ_B)
					@echo "$(YELLOW)$(OBJ) file removed.$(DEF_COLOR)"
					@make clean -C ./libft

fclean:			clean
					@make  fclean -C ./libft
					@$(RM) $(NAME) checker
					@echo "$(RED)$(NAME) removed!$(DEF_COLOR)"

re:				fclean  all

.PHONY			all clean fclean re libft print bonus
