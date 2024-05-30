/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 11:29:06 by kaykin            #+#    #+#             */
/*   Updated: 2024/05/30 15:34:14 by btanir           ###   ########.fr       */
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
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}			t_stacks;

char		**parse_args(int ac, char **av);
t_stacks	*new_stack(void);
void		add_args_to_stack(t_stacks *stacks);
void		put_error_and_free(char *msg, t_stacks *stacks);
void		check_args(t_stacks *stacks);
int			is_sort(t_list *stack);
void		action_optimise(t_stacks *stacks);
void		actions(t_stacks *stacks, char *str);
int			min_stack(t_list *stack);
int			max_stack(t_list *stack);
int			min(int a, int b);
int			max(int a, int b);
#endif