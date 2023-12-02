# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/02 00:05:22 by codespace         #+#    #+#              #
#    Updated: 2023/12/02 00:06:49 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
INCLUDES	=	inc/
SRC_DIR		=	src/
CC			=	gcc
CCFLAGS		=	-Wall -Wextra -Werror
AR			=	ar rc
RM			=	rm -f



SRC_FILES	=	ft_put/ft_putchar_fd.c ft_put/ft_putnbr_unsigned_fd.c \
				ft_put/ft_putnbr_fd.c ft_put/ft_putstr_fd.c \
				ft_to/ft_atoi.c \
SRC	=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ	=	$(SRC:.c=.o)
# **************************************************************************************** #
all:			$(NAME)

$(NAME):		$(OBJ)
					@$(AR) $(NAME) $(OBJ)
					@echo "libft compiled!"

.c.o:			
				@echo "Compiling"
				@$(CC) $(CCFLAGS) -I$(INCLUDES) -c $< -o $(<:.c=.o)
clean:
				$(RM) $(OBJ)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re bonus