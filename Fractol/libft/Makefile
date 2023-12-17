# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/17 18:36:01 by dbonilla          #+#    #+#              #
#    Updated: 2023/12/17 18:36:02 by dbonilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
INCLUDES	=	inc/
SRC_DIR		=	src/
CC			=	gcc
CCFLAGS		=	-Wall -Wextra -Werror
AR			=	ar rc
RM			=	rm -f



SRC_FILES	=	ft_put/ft_putchar_fd.c \
				ft_put/ft_putnbr_fd.c ft_put/ft_putstr_fd.c \
				ft_to/ft_atoi.c \
				
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
# **************************************************************************************** #
all:			$(NAME)

$(NAME):		$(OBJ)
					@$(AR) $(NAME) $(OBJ)
					@echo "$(GREEN)LIBFT COMPILED SUCCESFUL!$(DEF_COLOR)"
.c.o:			
				@echo "$(BLUE)COMPILING... $< $(DEF_COLOR)"
				@$(CC) $(CCFLAGS) -I$(INCLUDES) -c $< -o $(<:.c=.o)
clean:
				@$(RM) $(OBJ)
				@echo "$(YELLOW)FILES REMOVED!$(DEF_COLOR)"

fclean:			clean
				@$(RM) $(NAME)
				@echo "$(RED)$(NAME) REMOVED!$(DEF_COLOR)"

re:				fclean all

.PHONY:			all clean fclean re bonus