# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/17 17:36:22 by dbonilla          #+#    #+#              #
#    Updated: 2024/03/09 22:21:09 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        =   fractol
LIBFT     	=	libft/libft.a
INC         =   inc/
SRC_DIR     =   src/
MLX         =   mlx/libmlx_Linux.a
# FLAGS_MLX =  -Lmlx -lmlx -framework OpenGL -framework AppKit

CC          =   gcc -fsanitize=address -g3
FLAGS       =   -Wall -Wextra -Werror 
RM          =   rm -f

SRC_FILES   =   main.c \
				init.c \
				map.c \
				fractal_render.c \
				

				
# draw_fractol.c \
# fast_inverse_sqrt.c \
# julia.c \
# mandelbrot.c \
                
SRC =   $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ =   $(SRC:.c=.o)



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

all:        $(NAME)

$(NAME):    $(MLX) $(OBJ) $(LIBFT)
			$(CC) -o $(NAME) $(FLAGS) $(OBJ) $(LIBFT) $(MLX) -I$(INCLUDES) -Lminilibx-linux -lX11 -lXext
			@echo "$(GREEN)FRACT'OL COMPILED SUCCESFUL!$(DEF_COLOR)"
            
$(LIBFT):
			@make -C ./libft
$(MLX):	
			@make -C ./mlx 2>/dev/null

.c.o:
			@echo "$(BLUE)COMPILING... $< $(DEF_COLOR)"
			$(CC) $(FLAGS) -I$(INC) -c $< -o $(<:.c=.o)

clean:
			@$(RM) $(OBJ)
			@echo "$(YELLOW)FILES REMOVED!$(DEF_COLOR)"
			@make clean -C ./libft
			@make clean -C ./mlx

fclean:     clean
#           @make fclean -C ./libft
			@$(RM)  $(NAME)
			@echo "$(RED)$(NAME) REMOVED!$(DEF_COLOR)"
            

re:         fclean all

.PHONY:     all clean fclean re libft print