# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 17:05:29 by dbonilla          #+#    #+#              #
#    Updated: 2022/12/26 21:12:40 by dbonilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

 .SILENT:
SRC =	ft_puthex.c ft_printf.c \
		ft_put.c ft_putnbr.c

OBJS = $(SRC:%.c=%.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra
NORMI= norminette *c *h

# ************************** REGLAS INTERNAS MAKE *********************** #
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	echo "Library compiled"

clean:
	rm -f $(OBJS)
	echo ".o files removed"

fclean: clean
	rm -f $(NAME)
	echo "Library removed"
normi:

	$(NORMI) $(SRC)	
	echo "---> Norminette Completed <---"

re: fclean $(NAME)

.PHONY: all clean fclean re normi