/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:10:44 by btanir            #+#    #+#             */
/*   Updated: 2024/05/26 16:35:15 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		rotate(t_stacks *stacks, char *str);
static void		r_rotate(t_stacks *stacks, char *str);
static t_list	*ft_lst_new_last(t_list *lst);
static void		push(t_stacks *stacks, char *str);

void	actions(t_stacks *stacks, char *str)
{
	if (str == RA || str == RB || str == RR)
		rotate(stacks, str);
	if (str == RRA || str == RRB || str == RRR)
		r_rotate(stacks, str);
	if (str == PA || str == PB)
		push(stacks, str);
	ft_printf("%s\n", str);
}

static void	rotate(t_stacks *stacks, char *str)
{
	t_list	*temp;

	if (str == RA || str == RR)
	{
		temp = stacks->stack_a;
		stacks->stack_a = stacks->stack_a->next;
		ft_lstlast(stacks->stack_a)->next = temp;
		temp->next = NULL;
	}
	if (str == RB || str == RR)
	{
		temp = stacks->stack_b;
		stacks->stack_a = stacks->stack_b->next;
		ft_lstlast(stacks->stack_b)->next = temp;
		temp->next = NULL;
	}
}

static void	r_rotate(t_stacks *stacks, char *str)
{
	t_list *temp;
	t_list *new_last;

	if (str == RRA || str == RRR)
	{
		new_last = ft_lst_new_last(stacks->stack_a);
		temp = ft_lstlast(stacks->stack_a);
		temp->next = stacks->stack_a;
		new_last->next = NULL;
		stacks->stack_a = temp;
	}
	if (str == RRB || str == RRR)
	{
		new_last = ft_lst_new_last(stacks->stack_b);
		temp = ft_lstlast(stacks->stack_b);
		temp->next = stacks->stack_b;
		new_last->next = NULL;
		stacks->stack_a = temp;
	}
}

static void	push(t_stacks *stacks, char *str)
{
	t_list	*temp;
	t_list	*temp2;

	if (str == PA)
	{ 
		temp = stacks->stack_a;
		stacks->stack_a = stacks->stack_b;
		temp2 = stacks->stack_b->next;
		stacks->stack_b->next = temp;
		stacks->stack_b = temp2;
		stacks->count_a++;
		stacks->count_b--;
	}
	if (str == PB)
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

static t_list	*ft_lst_new_last(t_list *lst)
{
	t_list	*new_last;
	
	if (lst == NULL)
		return (NULL);
	while (lst -> next != NULL)
	{
		new_last = lst;
		lst = lst -> next;
	}
	return (new_last);
}