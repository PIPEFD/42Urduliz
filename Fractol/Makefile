# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/17 17:36:22 by dbonilla          #+#    #+#              #
#    Updated: 2023/12/23 20:55:57 by dbonilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol
# LIBFT		=	libft/libft.a
INC			=	inc/
SRC_DIR		=	src/
MLX			=	mlx/libmlx.a
# FLAGS_MLX	=  -Lmlx -lmlx -framework OpenGL -framework AppKit

CC			=	gcc -fsanitize=address -g3
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

SRC_FILES	=	main.c draw_fractol.c \
				fast_inverse_sqrt.c \
				mandelbrot.c 
SRC	=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ	=	$(SRC:.c=.o)



# COLORS

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;31m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# **************************************************************************** #

all:		$(NAME)

$(NAME):	$(OBJ) $(MLX)  $(SRC)
			@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(MLX) -I$(INC) -Lmlx -lmlx -framework OpenGL -framework AppKit
			@echo "$(GREEN)FRACT'OL COMPILED SUCCESFUL!$(DEF_COLOR)"			
			
			
# $(LIBFT):
# 			@make -C ./libft

$(MLX):
			@make -C ./mlx 2> /dev/null
			@echo "$(GREEN)mlx compilada!$(DEF_COLOR)"			


.c.o:
			echo "$(BLUE)COMPILING... $< $(DEF_COLOR)"
			$(CC) $(FLAGS) -I$(INC) -c $< -o $(<:.c=.o)

clean:
			@$(RM) $(OBJ_CLIENT)
			@echo "$(YELLOW)FILES REMOVED!$(DEF_COLOR)"
			@make clean -C ./libft
			@make clean -C ./mlx

fclean:		clean
# @make fclean -C ./libft
			@$(RM)  $(NAME)
			@echo "$(RED)$(NAME) REMOVED!$(DEF_COLOR)"
			

re:			fclean all

.PHONY:		all clean fclean re libft