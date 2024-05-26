/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 11:29:06 by kaykin            #+#    #+#             */
/*   Updated: 2024/05/26 10:54:13 by btanir           ###   ########.fr       */
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
t_stacks	*new_stack(void);
void		add_args_to_stack(t_stacks *stacks);
void		put_error_and_free(char *msg, t_stacks *stacks);
void		check_args(t_stacks *stacks);
int			is_sort(t_list *stack);
#endif