/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:51:52 by kaykin            #+#    #+#             */
/*   Updated: 2024/05/26 10:48:00 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_error(char *msg)
{
	ft_printf("Error: %s\n", msg);
	exit(-1);
}

static void	free_stack(t_list *stack, int count)
{
	t_list	*temp;

	temp = stack;
	while (temp)
	{
		free(temp->content);
		temp = temp->next;
	}
	if (count != 0)
		free(temp);
}

void	put_error_and_free(char *msg, t_stacks *stacks)
{
	int	i;

	i = 0;
	while (stacks->args[i])
		free(stacks->args[i++]);
	free(stacks->args);
	free_stack(stacks->stack_a, stacks->count_a);
	free_stack(stacks->stack_b, stacks->count_b);
	put_error(msg);
}
