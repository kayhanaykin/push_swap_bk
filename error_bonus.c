/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:51:52 by kaykin            #+#    #+#             */
/*   Updated: 2024/05/31 19:53:25 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	put_error();
static void	free_stack(t_list *stack, int count);

void	put_error_and_free(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (stacks->args[i])
		free(stacks->args[i++]);
	free(stacks->args);
	free_stack(stacks->stack_a, stacks->count_a);
	free_stack(stacks->stack_b, stacks->count_b);
	free(stacks);
	put_error();
}

static void	put_error()
{
	ft_printf("Error\n");
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
