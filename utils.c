/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaykin <kaykin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:59:08 by kaykin            #+#    #+#             */
/*   Updated: 2024/06/03 17:59:12 by kaykin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*max_stack(t_list *stack)
{
	t_list	*temp;
	t_list	*ret;

	temp = stack;
	ret = stack;
	while (temp)
	{
		if (*(int *)(temp->content) > *(int *)(ret->content))
			ret = temp;
		temp = temp->next;
	}
	return (ret);
}

t_list	*min_stack(t_list *stack)
{
	t_list	*temp;
	t_list	*ret;

	temp = stack;
	ret = temp;
	while (temp)
	{
		if (*(int *)(temp->content) < *(int *)(ret->content))
			ret = temp;
		temp = temp->next;
	}
	return (ret);
}

int	min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

t_list	*ft_lst_new_last(t_list *lst)
{
	t_list	*new_last;

	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		new_last = lst;
		lst = lst->next;
	}
	return (new_last);
}
