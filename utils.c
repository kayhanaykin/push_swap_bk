/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:43:18 by btanir            #+#    #+#             */
/*   Updated: 2024/05/26 17:44:34 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(t_list *stack)
{
	t_list	*temp;
	int		max;

	temp = stack;
	max = 0;
	while (temp)
	{
		if (*(int *)(temp->content) > max)
			max = *(int *)(temp->content);
		temp = temp->next;
	}
	return (max);
}

int	min(t_list	*stack)
{
	t_list	*temp;
	int		min;

	temp = stack;
	min = temp->content;
	while (temp)
	{
		if (*(int *)(temp->content) < min)
			min = *(int *)(temp->content);
		temp = temp->next;
	}
	return (min);
}
