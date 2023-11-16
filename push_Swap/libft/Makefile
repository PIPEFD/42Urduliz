# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 15:32:25 by dbonilla          #+#    #+#              #
#    Updated: 2023/10/19 14:40:44 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME		=	libft.a
INCLUDES	=	inc/
SRC_DIR		=	src/
CC			=	gcc
CCFLAGS		=	-Wall -Wextra -Werror
AR			=	ar rc
RM			=	rm -f



SRC_FILES	=	ft_is/ft_is_samesign.c ft_is/ft_isint.c  ft_is/ft_isdigit.c\
				ft_put/ft_putchar_fd.c ft_put/ft_putnbr_fd.c \
				ft_put/ft_putstr_fd.c \
				ft_str/ft_split.c  ft_str/ft_strlen.c ft_str/ft_strcat.c \
				ft_str/ft_strlcpy.c \
				ft_to/ft_abs.c ft_to/ft_atoi.c ft_to/ft_max.c \
				ft_intlst/ft_intlst_free.c ft_intlst/ft_intlst_last.c \
				ft_intlst/ft_intlst_new.c ft_intlst/ft_intlst_print.c \
				ft_intlst/ft_intlst_before_last.c ft_intlst/ft_intlst_addback.c\
				ft_intlst/ft_intlst_issorted.c ft_intlst/ft_intlst_minval.c\
				ft_intlst/ft_intlst_maxval.c ft_intlst/ft_intlst_size.c \
				ft_intlst/ft_intlst_isrevsorted.c \
				ft_intlst/ft_args_to_intlst.c \

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