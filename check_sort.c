/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaykin <kaykin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 10:11:47 by btanir            #+#    #+#             */
/*   Updated: 2024/05/31 11:23:52 by kaykin           ###   ########.fr       */
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
