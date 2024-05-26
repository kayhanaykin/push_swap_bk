# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 17:12:04 by kaykin            #+#    #+#              #
#    Updated: 2024/05/26 17:44:07 by btanir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= push_swap
CC			= gcc
FLAGS 		= -Wall -Wextra -Werror -s
SRCS		= helper_args.c push_swap.c helper_stack.c error.c check_sort.c actions.c optimiser.c utils.c

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