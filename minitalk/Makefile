# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 20:20:19 by codespace         #+#    #+#              #
#    Updated: 2023/12/06 17:25:34 by dbonilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# MANDATORY
NAME		=	minitalk
NAME_CLIENT = 	client
NAME_SERVER = 	server
LIBFT		=	libft/libft.a
INC			=	inc/

CC			=	gcc -fsanitize=address -g3
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

SRC_CLIENT	=	src/client.c 
OBJ_CLIENT	= 	$(SRC_CLIENT:.c=.o)

SRC_SERVER	=	src/server.c 
OBJ_SERVER	= 	$(SRC_SERVER:.c=.o)

# **************************************************************************** #
# BONUS
NAME_BONUS		  =		minitalk_bonus
NAME_CLIENT_BONUS = 	client_bonus
NAME_SERVER_BONUS = 	server_bonus


SRC_CLIENT_BONUS	=	src_bonus/client_bonus.c 
OBJ_CLIENT_BONUS	= 	$(SRC_CLIENT_BONUS:.c=.o)

SRC_SERVER_BONUS	=	src_bonus/server_bonus.c 
OBJ_SERVER_BONUS	= 	$(SRC_SERVER_BONUS:.c=.o)


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
			
bonus:      $(NAME_BONUS)

$(NAME):	$(LIBFT) $(OBJ_SERVER) $(OBJ_CLIENT)
			@$(CC) -o $(NAME_CLIENT) $(FLAGS) $(SRC_CLIENT)-I$(INC) $(LIBFT)
			@echo "$(GREEN)CLIENT COMPILED SUCCESFUL!$(DEF_COLOR)"			
			@$(CC) -o $(NAME_SERVER) $(FLAGS) $(SRC_SERVER)-I$(INC) $(LIBFT)
			@echo "$(GREEN)SERVER COMPILED SUCCESFUL!$(DEF_COLOR)"
			
$(NAME_BONUS):	$(LIBFT) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)
			@$(CC) -o $(NAME_CLIENT_BONUS) $(FLAGS) $(SRC_CLIENT_BONUS)-I$(INC) $(LIBFT)
			@echo "$(GREEN)CLIENT BONUS COMPILED SUCCESFUL!$(DEF_COLOR)"			
			@$(CC) -o $(NAME_SERVER_BONUS) $(FLAGS) $(SRC_SERVER_BONUS)-I$(INC) $(LIBFT)
			@echo "$(GREEN)SERVER BONUS COMPILED SUCCESFUL!$(DEF_COLOR)"			
$(LIBFT):
			@make -C ./libft

.c.o:
			@echo "$(BLUE)COMPILING... $< $(DEF_COLOR)"
			@$(CC) $(FLAGS) -I$(INC) -c $< -o $(<:.c=.o)

clean:
			@$(RM) $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS)
			@echo "$(YELLOW)FILES REMOVED!$(DEF_COLOR)"
			@make clean -C ./libft

fclean:		clean
			@make fclean -C ./libft
			@$(RM)  $(NAME) $(NAME_SERVER) $(NAME_CLIENT) 
			@$(RM)  $(NAME_BONUS) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)
			@echo "$(RED)$(NAME) REMOVED!$(DEF_COLOR)"
			@echo "$(RED)$(NAME_CLIENT) REMOVED!$(DEF_COLOR)"
			@echo "$(RED)$(NAME_SERVER) REMOVED!$(DEF_COLOR)"
			@echo "$(RED)$(NAME_CLIENT_BONUS) REMOVED!$(DEF_COLOR)"
			@echo "$(RED)$(NAME_SERVER_BONUS) REMOVED!$(DEF_COLOR)"

re:			fclean all

.PHONY:		all bonus clean fclean re libft print 
