/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaykin <kaykin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 11:29:06 by kaykin            #+#    #+#             */
/*   Updated: 2024/05/25 16:29:33 by kaykin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>

typedef struct s_stacks
{
	char	**args;
	t_list	*stack_a;
	t_list	*stack_b;
	int		count_a;
	int		count_b;
}			t_stacks;

char		**parse_args(int ac, char **av);
t_stacks	*new_stack();
void		add_args_to_stack(char **args, t_stacks *stacks);
void		put_error_and_free(char *msg, t_stacks *stacks);
void		check_args(t_stacks *stacks);
#endif