/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimiser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:47:28 by btanir            #+#    #+#             */
/*   Updated: 2024/05/30 16:51:36 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_to_b(int a_index, t_stacks *stacks);
static void	three_sort(t_stacks *stacks);
static int	largest_smaller_number(t_list *node, t_list *stack_b);
static int	calc_cost(int index, int b_index, t_stacks *stacks);
static int	find_a_index(int b_index, t_stacks *stacks);
static void	advanced_sort(t_stacks *stacks);

void a(t_stacks * stacks)
{
		t_list * tmp;
		tmp = stacks->stack_a;
	while (tmp)
	{
		ft_printf("%d\n",*(int *)(tmp->content));

		tmp = tmp->next;
	}
		tmp = stacks->stack_b;
	ft_printf("---------\n");
	while (tmp)
	{
		ft_printf("%d\n",*(int *)(tmp->content));
;
		tmp = tmp->next;
	}
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
	if (max_stack(stacks->stack_a) == *(int *)stacks->stack_a->content)
		actions(stacks, "ra");
	else if (min_stack(stacks->stack_a) == *(int *)ft_lstlast(stacks->stack_a)->content)
		actions(stacks, "rra");
	if (!is_sort(stacks->stack_a))
		actions(stacks, "sa");
	if (!is_sort(stacks->stack_a))
		actions(stacks, "ra");
}


static void	advanced_sort(t_stacks *stacks)
{
	t_list	*temp;
	t_list	*node;
	int		b_index;

	actions(stacks, "pb");
	actions(stacks, "pb");
	while (stacks->count_a > 3)
	{
		temp = stacks->stack_a;
		b_index = largest_smaller_number(temp, stacks->stack_b);
		ft_printf("b_index_advanced: %d\n", b_index);
		push_to_b(find_a_index(b_index, stacks), stacks);
		ft_printf("b_index_psuhsonrasi: %d\n", b_index);
	}
	if (stacks->count_a == 3)
		three_sort(stacks);
}
static int	largest_smaller_number(t_list *node, t_list *stack_b)
{
	t_list	*temp;
	t_list	*temp2;
	t_list	*value;
	int		b_index;

	temp = stack_b;
	value = node;
	while (temp)
	{
		if (temp->content < node->content && temp->content < value->content)
			value = temp;
		temp = temp->next;
	}
	temp = stack_b;
	b_index = 0;
	while (temp)
	{
		b_index++;
		if (temp == value)
			break ;
		temp = temp->next;
	}
	ft_printf("b_index_larger: %d\n",b_index);
	return (b_index);
}
void	push_to_b(int a_index, t_stacks *stacks)
{
	int temp;
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
		if ((stacks->rr) < (stacks->rrr))
		{
			temp = min(stacks->ra, stacks->rb);
			while ((-1 * stacks->rr + stacks->ra--) >= 0)
				actions(stacks, "ra");
			while ((-1 * stacks->rr + stacks->rb--) >= 0)
				actions(stacks, "rb");
			while (temp-- > 0)
				actions(stacks, "rr");
		}
		else
		{
			temp = min(stacks->rra, stacks->rrb);
			while ((-1 * stacks->rrr + stacks->rra--) >= 0)
				actions(stacks, "rra");
			while ((-1 * stacks->rrr + stacks->rrb--) >= 0)
				actions(stacks, "rrb");
			while (temp-- > 0)
				actions(stacks, "rrr");
		}
	}
	actions(stacks, "pb");
}

static int	find_a_index(int b_index, t_stacks *stacks)
{
	t_list	*temp;
	int		index;
	int		min_index;
	int		min_cost;
	ft_printf("b_index_finda,ndex: %d\n",b_index);
	temp = stacks->stack_a;
	index = 1;
	min_index = 1;
	min_cost = calc_cost(index, b_index, stacks);
	temp = temp->next;
	while (temp)
	{
		index++;
		if (min_cost > calc_cost(index, b_index, stacks))
		{
			min_cost = calc_cost(index, b_index, stacks);
			min_index = index;
		}
		temp = temp->next;
	}
	calc_cost(min_index, b_index, stacks);
	// ft_printf("min_index:%d\n", min_index);
	// ft_printf("b_index:%d\n", b_index);
	// ft_printf("ra:%d\n", stacks->ra);
	// ft_printf("rb:%d\n", stacks->rb);
	// ft_printf("rr:%d\n", stacks->rr);
	// ft_printf("rra:%d\n", stacks->rra);
	// ft_printf("rrb:%d\n", stacks->rrb);
	// ft_printf("rrr:%d\n", stacks->rrr);
	// a(stacks);
	return (min_index);
}

static int	calc_cost(int index, int b_index, t_stacks *stacks)
{
	int	cost;

	stacks->ra = index - 1; //3
	stacks->rb = b_index - 1; //2
	stacks->rr = min(stacks->ra, stacks->rb); //2
	stacks->rr += (stacks->ra - stacks->rr) + (stacks->rb - stacks->rr); //3
	stacks->rra = stacks->count_a - index + 1; // 4
	stacks->rrb = stacks->count_b - b_index + 1; // 6
	stacks->rrr = min(stacks->rra, stacks->rrb); // 4
	stacks->rrr += (stacks->rra - stacks->rrr) + (stacks->rrb - stacks->rrr); // 6
	cost = min(min((stacks->ra + stacks->rrb), (stacks->rra + stacks->rb)),
			min(stacks->rr, stacks->rrr));
	return (cost);
}



