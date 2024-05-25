# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaykin <kaykin@student.42istanbul.com.t    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 17:12:04 by kaykin            #+#    #+#              #
#    Updated: 2024/05/25 11:27:50 by kaykin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= push_swap
CC			= gcc
FLAGS 		= -Wall -Wextra -Werror -s
SRCS		= 

OBJS		:= $(SRCS:.c=.o)

AR_LIBFT	= libft/libft.a
DIR_LIBFT	= libft

all: $(NAME)

$(NAME): $(OBJS)
	make bonus -C $(DIR_LIBFT) -s
	$(CC) $(FLAGS) $(OBJS) $(AR_LIBFT) -o $(NAME)

clean:
			rm -f $(OBJS)
			make -s -C $(DIR_LIBFT) clean

fclean: clean
			rm -f $(NAME)
			make -s -C $(DIR_LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re