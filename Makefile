# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaykin <kaykin@student.42istanbul.com.t    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 17:58:38 by kaykin            #+#    #+#              #
#    Updated: 2024/06/03 17:58:40 by kaykin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= push_swap
BONUS		= checker
CC			= gcc
FLAGS 		= -Wall -Wextra -Werror 
SRCS		= optimiser.c adv_sort_utils.c parse_args.c \
			adv_sort_utils2.c push_swap.c actions.c check_args.c
SRCS_SHARED	=  helper_stack.c error.c \
			check_sort.c utils.c 
SRCS_BNS	= checker_bonus.c actions_bonus.c check_args_bonus.c \
			parse_args_bonus.c

OBJS		:= $(SRCS:.c=.o)
OBJS_SHARED	:= $(SRCS_SHARED:.c=.o)
OBJS_BNS	:= $(SRCS_BNS:.c=.o)

AR_LIBFT	= libft/libft.a
DIR_LIBFT	= libft

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_SHARED) 
	make bonus -C $(DIR_LIBFT) -s
	$(CC) $(FLAGS) $(OBJS) $(OBJS_SHARED) $(AR_LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS) $(OBJS_SHARED) $(OBJS_BNS)
	make -s -C $(DIR_LIBFT) clean

fclean: clean
	rm -f $(NAME) checker
	make -s -C $(DIR_LIBFT) fclean

bonus: $(BONUS)

$(BONUS): $(OBJS_SHARED) $(OBJS_BNS)
	make bonus -C $(DIR_LIBFT) -s
	$(CC) $(FLAGS) $(OBJS_SHARED) $(OBJS_BNS) $(AR_LIBFT) -o $(BONUS)
	
re: fclean all

.PHONY: all clean fclean bonus re