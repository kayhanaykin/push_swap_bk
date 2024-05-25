/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaykin <kaykin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:43:02 by kaykin            #+#    #+#             */
/*   Updated: 2024/05/25 16:29:37 by kaykin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*new_stack()
{
	t_stacks *stacks;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (stacks == NULL)
	{
		ft_printf("Error: Allocation Failure\n");
		exit(-1);
	}
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	stacks->count_a = 0;	
	stacks->count_b = 0;
	stacks->args = NULL;
	return stacks;
}

void	add_args_to_stack(char **args, t_stacks *stacks)
{
	int i;
	stacks->stack_a = ft_lstnew((void *)args[1]);
	i = 2;
	while (args[i])
	{
		ft_lstadd_back(&stacks->stack_a, ft_lstnew(args[i]));
		i++;
	}
}