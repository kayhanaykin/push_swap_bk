/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 10:11:47 by btanir            #+#    #+#             */
/*   Updated: 2024/05/26 10:28:35 by btanir           ###   ########.fr       */
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
		if ((int)temp->content < (int )temp->next->content)
			return (0);
		temp = stack->next;
	}
	return (1);
}
