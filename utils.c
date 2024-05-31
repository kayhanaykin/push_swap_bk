/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaykin <kaykin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:43:18 by btanir            #+#    #+#             */
/*   Updated: 2024/05/31 10:11:39 by kaykin           ###   ########.fr       */
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