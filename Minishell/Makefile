# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/13 20:19:46 by codespace         #+#    #+#              #
#    Updated: 2024/04/14 12:44:38 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell
LIBFT		=	libft/libft.a
INC			= 	inc/
BINDIR		=	bin/
SRC_DIR		= 	src/
OBJ_DIR		=	objs/

				
SRC 		= $(addprefix $(SRC_DIR), $(SRC_FILES))
SRC_FILES	= 	main.c
OBJS_FILES	= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)




CC			= gcc
FLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=address
# LIBS		=  -lreadline
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
# $(CC) $(CFLAGS) -o $(NAME) $(LIBFT) $(OBJ) -lreadline

all:		$(NAME)


$(NAME): $(LIBFT) $(OBJS_FILES) 
	@mkdir -p $(BINDIR)
	$(CC) -o ./$(BINDIR)/$(NAME) $(FLAGS) $(OBJS_FILES) $(LIBFT) -I$(INC) -lreadline
	@echo "$(BLUE)COMPILING MINISHELL...$(CLEAR)"
	@echo "$(GREEN)MINISHELL COMPILED SUCCESFUL!$(CLEAR)"
			
$(LIBFT):
	@make -C libft/

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -I$(INC) -c $< -o $@
						
clean:
			@echo "$(YELLOW)FILES REMOVED!$(DEF_COLOR)"
			@$(RM) $(OBJ_DIR)
			@$(RM) $(BINDIR)
			@make -C libft/ clean
			
fclean:		clean
			@$(RM)  $(NAME)
			@make -C libft/ fclean
			@echo "$(RED)$(NAME) REMOVED!$(DEF_COLOR)"
			
re:			fclean all

.PHONY:		all clean fclean re libft