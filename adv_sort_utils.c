/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adv_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:34:20 by btanir            #+#    #+#             */
/*   Updated: 2024/05/31 17:41:02 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_a_index(t_stacks *stacks)
{
	t_list	*temp;
	int		index[2];
	int		min_index[2];
	int		min_cost;

	index[0] = 1;
	index[1] = 1;
	min_index[0] = 1;
	temp = stacks->stack_a;
	index[1] = largest_smaller_number(temp, stacks->stack_b);
	min_index[1] = index[1];
	min_cost = calc_cost(index[0], index[1], stacks);
	temp = temp->next;
	while (temp)
	{
		index[1] = largest_smaller_number(temp, stacks->stack_b);
		if (calc_cost(++index[0], index[1], stacks) < min_cost)
		{
			min_cost = calc_cost(index[0], index[1], stacks);
			min_index[0] = index[0];
			min_index[1] = index[1];
		}
		temp = temp->next;
	}
	calc_cost(min_index[0], min_index[1], stacks);
}

int	node_to_index(t_list *node, t_list *stack)
{
	t_list	*temp;
	int		index;

	temp = stack;
	index = 0;
	while (temp)
	{
		index++;
		if (temp == node)
			break ;
		temp = temp->next;
	}
	return (index);
}

int	largest_smaller_number(t_list *a_node, t_list *stack_b)
{
	t_list	*b_node;
	t_list	*value;

	b_node = stack_b;
	value = min_stack(stack_b);
	if (*(int *)a_node->content > *(int *)value->content)
	{
		while (b_node)
		{
			if (*(int *)b_node->content < *(int *)a_node->content
				&& *(int *)value->content < *(int *)b_node->content)
				value = b_node;
			b_node = b_node->next;
		}
	}
	else
		value = max_stack(stack_b);
	return (node_to_index(value, stack_b));
}

int	smallest_large_number(t_list *b_node, t_list *stack_a)
{
	t_list	*a_node;
	t_list	*value;

	a_node = stack_a;
	value = max_stack(stack_a);
	if (*(int *)b_node->content < *(int *)value->content)
	{
		while (a_node)
		{
			if (*(int *)a_node->content > *(int *)b_node->content
				&& *(int *)value->content > *(int *)a_node->content)
				value = a_node;
			a_node = a_node->next;
		}
	}
	else
		value = min_stack(stack_a);
	return (node_to_index(value, stack_a));
}

int	calc_cost(int a_index, int b_index, t_stacks *stacks)
{
	int	cost;

	stacks->ra = a_index - 1;
	stacks->rb = b_index - 1;
	stacks->rr = min(stacks->ra, stacks->rb);
	stacks->rr += (stacks->ra - stacks->rr) + (stacks->rb - stacks->rr);
	stacks->rra = stacks->count_a - a_index + 1;
	stacks->rrb = stacks->count_b - b_index + 1;
	stacks->rrr = min(stacks->rra, stacks->rrb);
	stacks->rrr += (stacks->rra - stacks->rrr) + (stacks->rrb - stacks->rrr);
	cost = min(min((stacks->ra + stacks->rrb), (stacks->rra + stacks->rb)),
			min(stacks->rr, stacks->rrr));
	return (cost);
}
