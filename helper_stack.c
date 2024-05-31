/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:43:02 by kaykin            #+#    #+#             */
/*   Updated: 2024/05/31 15:03:38 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*new_stacks(void)
{
	t_stacks	*stacks;

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
	stacks->ra = 0;
	stacks->rb = 0;
	stacks->rr = 0;
	stacks->rra = 0;
	stacks->rrb = 0;
	stacks->rrr = 0;
	return (stacks);
}

void	add_args_to_stack(t_stacks *stacks)
{
	int		i;
	char	**args;
	int		*num;

	args = stacks->args;
	i = 0;
	while (args[i])
	{
		num = (int *)malloc(sizeof(int));
		if (num == NULL)
			put_error_and_free("Error: Allocation Failure", stacks);
		*num = ft_atoi(args[i++]);
		ft_lstadd_back(&stacks->stack_a, ft_lstnew(num));
		stacks->count_a++;
	}
}
