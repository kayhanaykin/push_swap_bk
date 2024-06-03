/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adv_sort_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaykin <kaykin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:57:41 by kaykin            #+#    #+#             */
/*   Updated: 2024/06/03 17:57:43 by kaykin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a(t_stacks *stacks)
{
	int		min_index;
	t_list	*min_node;
	t_list	*stack_a_temp;

	min_index = 0;
	stack_a_temp = stacks->stack_a;
	if (!is_sort(stacks->stack_a))
	{
		min_node = min_stack(stacks->stack_a);
		while (stack_a_temp)
		{
			min_index++;
			if (stack_a_temp == min_node)
				break ;
			stack_a_temp = stack_a_temp->next;
		}
		if ((stacks->count_a / 2 + 1) >= min_index)
			while (--min_index > 0)
				actions(stacks, "ra");
		else
			while (min_index++ <= stacks->count_a)
				actions(stacks, "rra");
	}
}

static void	double_action(t_stacks *stacks)
{
	int	temp;

	if ((stacks->rr) < (stacks->rrr))
	{
		temp = min(stacks->ra, stacks->rb);
		while (temp-- > 0)
			actions(stacks, "rr");
		while (stacks->rr > stacks->ra++)
			actions(stacks, "rb");
		while (stacks->rr > stacks->rb++)
			actions(stacks, "ra");
	}
	else
	{
		temp = min(stacks->rra, stacks->rrb);
		while (temp-- > 0)
			actions(stacks, "rrr");
		while (stacks->rrr > stacks->rra++)
			actions(stacks, "rrb");
		while (stacks->rrr > stacks->rrb++)
			actions(stacks, "rra");
	}
}

void	push_to_b(t_stacks *stacks)
{
	if (min((stacks->ra + stacks->rrb), (stacks->rra
				+ stacks->rb)) < min(stacks->rr, stacks->rrr))
	{
		if ((stacks->ra + stacks->rrb) < (stacks->rra + stacks->rb))
		{
			while (stacks->ra-- > 0)
				actions(stacks, "ra");
			while (stacks->rrb-- > 0)
				actions(stacks, "rrb");
		}
		else
		{
			while (stacks->rb-- > 0)
				actions(stacks, "rb");
			while (stacks->rra-- > 0)
				actions(stacks, "rra");
		}
	}
	else
		double_action(stacks);
	actions(stacks, "pb");
}

void	sort_b(t_stacks *stacks)
{
	int	index;

	index = node_to_index(max_stack(stacks->stack_b), stacks->stack_b);
	if ((stacks->count_b / 2 + 1) >= index)
	{
		while (--index > 0)
			actions(stacks, "rb");
	}
	else
	{
		while (index++ <= stacks->count_b)
			actions(stacks, "rrb");
	}
}

void	push_to_a(t_stacks *stacks)
{
	int	index_a;

	while (stacks->count_b)
	{
		index_a = smallest_large_number(stacks->stack_b, stacks->stack_a);
		if ((stacks->count_a / 2 + 1) >= index_a)
		{
			while (--index_a > 0)
				actions(stacks, "ra");
		}
		else
		{
			while (index_a++ <= stacks->count_a)
				actions(stacks, "rra");
		}
		actions(stacks, "pa");
	}
}
