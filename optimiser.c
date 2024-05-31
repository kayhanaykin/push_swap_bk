/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimiser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaykin <kaykin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:47:28 by btanir            #+#    #+#             */
/*   Updated: 2024/05/31 13:59:33 by kaykin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_to_b(t_stacks *stacks);
static void	three_sort(t_stacks *stacks);
static int	largest_smaller_number(t_list *node, t_list *stack_b);
static int	calc_cost(int index, int b_index, t_stacks *stacks);
static void	find_a_index(t_stacks *stacks);
static void	advanced_sort(t_stacks *stacks);
static void sort_b(t_stacks *stacks);
static int	node_to_index(t_list *node, t_list *stack);
static void	push_to_a(t_stacks *stacks);
static int	smallest_large_number(t_list *b_node, t_list *stack_a);

void	a(t_stacks *stacks)
{
	t_list	*tmp;

	tmp = stacks->stack_a;
	ft_printf("\n---STACK A-----\n");
	while (tmp)
	{
		ft_printf("%d\n", *(int *)(tmp->content));
		tmp = tmp->next;
	}
	tmp = stacks->stack_b;
	ft_printf("\n---STACK B-----\n");
	while (tmp)
	{
		ft_printf("%d\n", *(int *)(tmp->content));
		;
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void	action_optimise(t_stacks *stacks)
{
	if (is_sort(stacks->stack_a))
		exit(0);
	if (stacks->count_a == 2)
		actions(stacks, "sa");
	else if (stacks->count_a == 3)
		three_sort(stacks);
	else
		advanced_sort(stacks);
}
static void	three_sort(t_stacks *stacks)
{
	if (max_stack(stacks->stack_a) == (t_list*)stacks->stack_a)
		actions(stacks, "ra");
	else if (min_stack(stacks->stack_a) == ft_lstlast(stacks->stack_a))
		actions(stacks, "rra");
	if (!is_sort(stacks->stack_a))
		actions(stacks, "sa");
	if (!is_sort(stacks->stack_a))
		actions(stacks, "ra");
}

static void	advanced_sort(t_stacks *stacks)
{
	actions(stacks, "pb");
	actions(stacks, "pb");
	while (stacks->count_a > 3)
	{
		find_a_index(stacks);
		push_to_b(stacks);
	}
	if (stacks->count_a == 3)
		three_sort(stacks);
	sort_b(stacks);
	push_to_a(stacks);
	// sort_a(stacks);
}
static int	largest_smaller_number(t_list *a_node, t_list *stack_b)
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

void	push_to_b(t_stacks *stacks)
{
	int	temp;
	int	i;

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
	{
		i = 0;
		if ((stacks->rr) < (stacks->rrr))
		{
			temp = min(stacks->ra, stacks->rb);
			while (temp-- > 0)
				actions(stacks, "rr");
			while (stacks->rb > stacks->ra + i++)
				actions(stacks, "rb");
			i = 0;
			while (stacks->ra > stacks->rb + i++)
				actions(stacks, "ra");
		}
		else
		{
			temp = min(stacks->rra, stacks->rrb);
			while (temp-- > 0)
				actions(stacks, "rrr");
			while (stacks->rrb > stacks->rra + i++)
				actions(stacks, "rrb");
			i = 0;
			while (stacks->rra > stacks->rrb + i++)
				actions(stacks, "rra");
		}
	}
	actions(stacks, "pb");
}

static void	find_a_index(t_stacks *stacks)
{
	t_list	*temp;
	int		a_index;
	int		b_index;
	int		min_a_index;
	int		min_b_index;
	int		min_cost;

	a_index = 1;
	b_index = 1;
	min_a_index = 1;
	temp = stacks->stack_a;
	b_index = largest_smaller_number(temp, stacks->stack_b);
	min_b_index = b_index;
	min_cost = calc_cost(a_index, b_index, stacks);
	temp = temp->next;
	while (temp)
	{
		a_index++;
		b_index = largest_smaller_number(temp, stacks->stack_b);
		// ft_printf("b_index: %d\n", b_index);
		if (calc_cost(a_index, b_index, stacks) < min_cost)
		{
			min_cost = calc_cost(a_index, b_index, stacks);
			min_a_index = a_index;
			min_b_index = b_index;
		}
		temp = temp->next;
	}
	calc_cost(min_a_index, min_b_index, stacks);
	// ft_printf("\n");
	// ft_printf("min_a_index %d\n", min_a_index);
	// ft_printf("min_b_index: %d\n", min_b_index);
	// ft_printf("ra:%d\n", stacks->ra);
	// ft_printf("rb:%d\n", stacks->rb);
	// ft_printf("rr:%d\n", stacks->rr);
	// ft_printf("rra:%d\n", stacks->rra);
	// ft_printf("rrb:%d\n", stacks->rrb);
	// ft_printf("rrr:%d\n", stacks->rrr);
	// a(stacks);
}

static int	calc_cost(int a_index, int b_index, t_stacks *stacks)
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

static void sort_b(t_stacks *stacks)
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

static int	node_to_index(t_list *node, t_list *stack)
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

static void	push_to_a(t_stacks *stacks)
{
	int	index_a;
	
	while(stacks->count_b)
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

static int	smallest_large_number(t_list *b_node, t_list *stack_a)
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
