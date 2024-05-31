# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 17:12:04 by kaykin            #+#    #+#              #
#    Updated: 2024/05/31 19:52:32 by btanir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= push_swap
CC			= gcc
FLAGS 		= -Wall -Wextra -Werror 
SRCS		= optimiser.c adv_sort_utils.c error.c\
			adv_sort_utils2.c push_swap.c actions.c check_args.c
SRCS_SHARED	= parse_args.c helper_stack.c \
			check_sort.c utils.c 
SRCS_BNS	= checker_bonus.c actions_bonus.c check_args_bonus.c \
			error_bonus.c

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
	rm -f $(OBJS) $(OBJS_SHARED) $(BNS_OBJS)
	make -s -C $(DIR_LIBFT) clean

fclean: clean
	rm -f $(NAME) checker
	make -s -C $(DIR_LIBFT) fclean

bonus:	$(OBJS_SHARED) $(OBJS_BNS)
	make bonus -C $(DIR_LIBFT) -s
	$(CC) $(FLAGS) $(OBJS_SHARED) $(OBJS_BNS) $(AR_LIBFT) -o checker
	
re: fclean all

.PHONY: all clean fclean bonus re