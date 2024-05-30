/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:43:18 by btanir            #+#    #+#             */
/*   Updated: 2024/05/30 11:58:10 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_stack(t_list *stack)
{
	t_list	*temp;
	int		max_stack;

	temp = stack;
	max_stack = 0;
	while (temp)
	{
		if (*(int *)(temp->content) > max_stack)
			max_stack = *(int *)(temp->content);
		temp = temp->next;
	}
	return (max_stack);
}

int	min_stack(t_list	*stack)
{
	t_list	*temp;
	int		min_stack;

	temp = stack;
	min_stack = *(int *)(temp->content);
	while (temp)
	{
		if (*(int *)(temp->content) < min_stack)
			min_stack = *(int *)(temp->content);
		temp = temp->next;
	}
	return (min_stack);
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