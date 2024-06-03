/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaykin <kaykin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:58:00 by kaykin            #+#    #+#             */
/*   Updated: 2024/06/03 17:58:03 by kaykin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(t_list *stack)
{
	t_list	*temp;

	if (!stack)
		return (0);
	temp = stack;
	while (temp->next != NULL)
	{
		if (*(int *)temp->content > *(int *)temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	is_reverse_sort(t_list *stack)
{
	t_list	*temp;

	if (!stack)
		return (0);
	temp = stack;
	while (temp->next != NULL)
	{
		if (*(int *)temp->content < *(int *)temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}
