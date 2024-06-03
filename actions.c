/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaykin <kaykin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:57:24 by kaykin            #+#    #+#             */
/*   Updated: 2024/06/03 17:57:29 by kaykin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stacks *stacks, char *str);
static void	r_rotate(t_stacks *stacks, char *str);
static void	push(t_stacks *stacks, char *str);
static void	swap(t_stacks *stacks, char *str);

void	actions(t_stacks *stacks, char *str)
{
	if (ft_strncmp(str, "sa", 3) == 0 || ft_strncmp(str, "sb", 3) == 0
		|| ft_strncmp(str, "ss", 3) == 0)
		swap(stacks, str);
	else if (ft_strncmp(str, "ra", 3) == 0 || ft_strncmp(str, "rb", 3) == 0
		|| ft_strncmp(str, "rr", 3) == 0)
		rotate(stacks, str);
	else if (ft_strncmp(str, "rra", 4) == 0 || ft_strncmp(str, "rrb", 4) == 0
		|| ft_strncmp(str, "rrr", 4) == 0)
		r_rotate(stacks, str);
	else if (ft_strncmp(str, "pa", 3) == 0 || ft_strncmp(str, "pb", 3) == 0)
		push(stacks, str);
	ft_printf("%s\n", str);
}

static void	rotate(t_stacks *stacks, char *str)
{
	t_list	*temp;

	if (ft_strncmp(str, "ra", 3) == 0 || ft_strncmp(str, "rr", 3) == 0)
	{
		temp = stacks->stack_a;
		stacks->stack_a = stacks->stack_a->next;
		ft_lstlast(stacks->stack_a)->next = temp;
		temp->next = NULL;
	}
	if (ft_strncmp(str, "rb", 3) == 0 || ft_strncmp(str, "rr", 3) == 0)
	{
		temp = stacks->stack_b;
		stacks->stack_b = stacks->stack_b->next;
		ft_lstlast(stacks->stack_b)->next = temp;
		temp->next = NULL;
	}
}

static void	r_rotate(t_stacks *stacks, char *str)
{
	t_list	*temp;
	t_list	*new_last;

	if (ft_strncmp(str, "rra", 4) == 0 || ft_strncmp(str, "rrr", 4) == 0)
	{
		new_last = ft_lst_new_last(stacks->stack_a);
		temp = ft_lstlast(stacks->stack_a);
		temp->next = stacks->stack_a;
		new_last->next = NULL;
		stacks->stack_a = temp;
	}
	if (ft_strncmp(str, "rrb", 4) == 0 || ft_strncmp(str, "rrr", 4) == 0)
	{
		new_last = ft_lst_new_last(stacks->stack_b);
		temp = ft_lstlast(stacks->stack_b);
		temp->next = stacks->stack_b;
		new_last->next = NULL;
		stacks->stack_b = temp;
	}
}

static void	push(t_stacks *stacks, char *str)
{
	t_list	*temp;
	t_list	*temp2;

	if (ft_strncmp(str, "pa", 3) == 0)
	{
		temp = stacks->stack_a;
		stacks->stack_a = stacks->stack_b;
		temp2 = stacks->stack_b->next;
		stacks->stack_b->next = temp;
		stacks->stack_b = temp2;
		stacks->count_a++;
		stacks->count_b--;
	}
	if (ft_strncmp(str, "pb", 3) == 0)
	{
		temp = stacks->stack_b;
		stacks->stack_b = stacks->stack_a;
		temp2 = stacks->stack_a->next;
		stacks->stack_a->next = temp;
		stacks->stack_a = temp2;
		stacks->count_b++;
		stacks->count_a--;
	}
}

static void	swap(t_stacks *stacks, char *str)
{
	t_list	*temp;
	t_list	*temp1;
	t_list	*temp2;

	if (ft_strncmp(str, "sa", 3) == 0 || ft_strncmp(str, "ss", 3) == 0)
	{
		temp = stacks->stack_a;
		temp1 = stacks->stack_a->next;
		temp2 = stacks->stack_a->next->next;
		stacks->stack_a = temp1;
		stacks->stack_a->next = temp;
		stacks->stack_a->next->next = temp2;
	}
	if (ft_strncmp(str, "sb", 3) == 0 || ft_strncmp(str, "ss", 3) == 0)
	{
		temp = stacks->stack_b;
		temp1 = stacks->stack_b->next;
		temp2 = stacks->stack_b->next->next;
		stacks->stack_b = temp1;
		stacks->stack_b->next = temp;
		stacks->stack_b->next->next = temp2;
	}
}
