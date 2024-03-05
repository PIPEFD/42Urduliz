# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 15:32:25 by dbonilla          #+#    #+#              #
#    Updated: 2023/11/21 00:47:30 by dbonilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME		=	libft.a
INCLUDES	=	inc/
SRC_DIR		=	src/
CC			=	gcc -fsanitize=address -g3
CCFLAGS		=	-Wall -Wextra -Werror
AR			=	ar rc
RM			=	rm -f



SRC_FILES	=	ft_is/ft_ssign.c ft_is/ft_int.c  ft_is/ft_digit.c\
				ft_put/ft_putchar.c ft_put/ft_putnbr.c \
				ft_put/ft_putstr.c ft_str/ft_strlen.c\
				ft_str/ft_split.c  ft_str/ft_strcat.c \
				ft_str/ft_strlcpy.c \
				ft_to/ft_vabs.c ft_to/ft_atoi.c ft_to/ft_max.c \
				ft_intlst/ft_free.c ft_intlst/ft_last.c \
				ft_intlst/ft_new.c ft_intlst/ft_insert_before.c \
				ft_intlst/ft_insert_back.c\
				ft_intlst/ft_sorted.c ft_intlst/ft_minval.c\
				ft_intlst/ft_maxval.c ft_intlst/ft_size.c \
				ft_intlst/ft_sortedr.c \
				ft_intlst/ft_insert_args.c \

SRC	=	$(addprefix $(SRC_DIR),$(SRC_FILES))
OBJ	=	$(SRC:.c=.o)
# **************************************************************************************** #
all:			$(NAME)

$(NAME):		$(OBJ)
					@$(AR) $(NAME) $(OBJ)
					@echo "libft compiled!"

.c.o:			
				@echo "compiled"
				@$(CC) $(CCFLAGS) -I$(INCLUDES) -c $< -o $(<:.c=.o)
clean:
				$(RM) $(OBJ)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re bonus