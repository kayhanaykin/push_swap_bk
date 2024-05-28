/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimiser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:47:28 by btanir            #+#    #+#             */
/*   Updated: 2024/05/28 18:32:28 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	three_sort(t_stacks *stacks)
{
	if (max(stacks->stack_a) == *(int *)stacks->stack_a->content)
		actions(stacks, RA);
	else if (min(stacks->stack_a) == *(int *)ft_lstlast(stacks->stack_a)->content)
		actions(stacks, RRA);
	if (!is_sort(stacks->stack_a))
		actions(stacks, SA);
	if (!is_sort(stacks->stack_a))
		actions(stacks, RA);
}

static t_list	*largest_smaller_number(t_list *node, t_list *stack_b)
{
	t_list	*temp;
	t_list	*value;

	temp = stack_b;
	value = node;
	while (temp)
	{
		if (temp->content < node->content && temp->content < value->content)
			value = temp;
		temp = temp->next;
	}
	return (value);
}

static int	calc_cost(t_list *node, t_list *stack_b)
{
	int	step;

	step = 0;
	// cost calculate
	return (step);
}

static void	advanced_sort(t_stacks *stacks)
{
	t_list	*temp;
	t_list	*node;

	actions(stacks, PB);
	actions(stacks, PB);
	temp = stacks->stack_a;
	while (temp)
	{
		node = largest_smaller_number(temp, stacks->stack_b);
		calc_cost(node, stacks->stack_b);
		temp = temp->next;
	}
	if (stacks->count_a == 3)
		three_sort(stacks);
}

void	action_optimise(t_stacks *stacks)
{
	if (is_sort(stacks->stack_a))
		exit(0);
	if (stacks->count_a == 2)
		actions(stacks, SA);
	else if (stacks->count_a == 3)
		three_sort(stacks);
	else
		advanced_sort(stacks);
}