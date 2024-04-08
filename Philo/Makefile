# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 15:02:50 by codespace         #+#    #+#              #
#    Updated: 2024/04/08 16:26:53 by dbonilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	PHILOSOPHERS



SRC_DIR		= 	src/
SRC_FILES	= 	main.c \
				parsing.c \
				data_init.c \
				simulation.c \
				syncro.c \
				thread_safe.c \
				routines.c \
				utils.c \
				print.c \
# exit.c 
				
SRC 		= $(addprefix $(SRC_DIR), $(SRC_FILES))


OBJ_DIR		= objs/
OBJS_FILES	= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)


CC			= gcc -fsanitize=address
FLAGS		= -Wall -Wextra -Werror
INC			=  -I inc/
THREADS		= -lpthread
RM			= rm -rf


DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;31m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
CLEAR = \033[0m
OKLOGO = \033[80G\033[32m[OK]\033[0m\n


# **************************************************************************** #

all:		$(NAME)


$(NAME):  $(OBJS_FILES)
	@echo "$(BLUE)COMPILING PHILOSOPHERS...$(CLEAR)"
	@$(CC) $(FLAGS) $(INC) $(OBJS_FILES) $(THREADS) -o $(NAME)
	@echo "$(GREEN)PHILOSOPHERS COMPILED SUCCESFUL!$(CLEAR)"
	@echo "$(MAGENTA)Usage ./Philosophers <n_philosophers> <time_to_die> <time_to_eat> <time_to_sleep>"
			
			
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@
						
clean:
			@echo "$(YELLOW)FILES REMOVED!$(DEF_COLOR)"
			@$(RM) $(OBJ_DIR)
			
fclean:		clean
			@$(RM)  $(NAME)
			@echo "$(RED)$(NAME) REMOVED!$(DEF_COLOR)"
			
re:			fclean all

.PHONY:		all clean fclean re libft print

