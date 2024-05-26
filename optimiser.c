/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimiser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:47:28 by btanir            #+#    #+#             */
/*   Updated: 2024/05/26 16:40:14 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	action_optimise(t_stacks *stacks)
{
	if (is_sort(stacks->stack_a))
		exit(0);
	if (stacks->count_a == 2)
		actions(stacks, RA);
	else if (stacks->count_a == 3)
	{
		//üçlü sort
	}
	else
	{
	}
}