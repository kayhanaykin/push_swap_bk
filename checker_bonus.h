/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaykin <kaykin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:58:13 by kaykin            #+#    #+#             */
/*   Updated: 2024/06/03 17:58:16 by kaykin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include "./libft/libft.h"
# include <stdlib.h>

# define INTMAX 2147483647 
# define INTMIN -2147483648

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

t_stacks	*new_stacks(void);
char		**parse_args(int ac, char **av, t_stacks *stacks);
void		add_args_to_stack(t_stacks *stacks);
void		put_error_and_free(t_stacks *stacks);
void		free_stack(t_list *stack);
void		check_args(t_stacks *stacks);
int			is_sort(t_list *stack);
int			is_reverse_sort(t_list *stack);
void		action_optimise(t_stacks *stacks);
void		actions(t_stacks *stacks, char *str);
t_list		*min_stack(t_list *stack);
t_list		*max_stack(t_list *stack);
int			min(int a, int b);
int			max(int a, int b);
t_list		*ft_lst_new_last(t_list *lst);
void		find_a_index(t_stacks *stacks);
int			node_to_index(t_list *node, t_list *stack);
int			largest_smaller_number(t_list *node, t_list *stack_b);
int			smallest_large_number(t_list *b_node, t_list *stack_a);
int			calc_cost(int index, int b_index, t_stacks *stacks);
void		sort_a(t_stacks *stacks);
void		sort_b(t_stacks *stacks);
void		push_to_a(t_stacks *stacks);
void		push_to_b(t_stacks *stacks);
#endif