# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 15:02:50 by codespace         #+#    #+#              #
#    Updated: 2024/02/26 17:02:54 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo
LIBFT		=	libft/libft.a


SRC_DIR		= 	src/
SRC_FILES	= main.c \
				parsing.c \
				print.c \
				init_data.c \
				simulation.c \
				thread_safe_functions.c \
				actions.c \
				syncro_utils.c \
				utils.c \
				exit.c 
				
SRC 		= $(addprefix $(SRC_DIR), $(SRC_FILES))


OBJ_DIR		= objs/
OBJS_FILES	= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)


CC			= gcc
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


$(NAME):  $(OBJS_FILES) $(LIBFT)
	@echo "$(BLUE)COMPILING PHILOSOPHERS.$(CLEAR)"
	$(CC) $(FLAGS) $(INC) $(OBJS_FILES) $(THREADS) $(LIBFT) -o $(NAME)
	@printf "033[1;34m$(NAME)\033[25G\033[33mCompile $< $(OKLOGO)"
	@echo "$(MAGENTA)\tUsage ./Philosophers <n_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [n_time_each_philosoher_eat]"
	@echo "$(GREEN)PHILOSOPHERS COMPILED SUCCESFUL!$(CLEAR)"
			
			
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@
			
$(LIBFT):
			@make -C ./libft
			
clean:
			@echo "$(YELLOW)FILES REMOVED!$(DEF_COLOR)"
			@$(RM) $(OBJ_DIR)
			@make clean -C ./libft

fclean:		clean
			@make fclean -C ./libft
			@$(RM)  $(NAME)
			@echo "$(RED)$(NAME) REMOVED!$(DEF_COLOR)"
			@echo "$(RED)$(NAME_CLIENT) REMOVED!$(DEF_COLOR)"
			@echo "$(RED)$(NAME_SERVER) REMOVED!$(DEF_COLOR)"

re:			fclean all

.PHONY:		all clean fclean re libft print