/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:43:02 by kaykin            #+#    #+#             */
/*   Updated: 2024/05/26 12:20:08 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*new_stack(void)
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
		num = malloc(sizeof(int));
		if (!num)
        {
            put_error_and_free("Memory allocation failed", stacks);
            return;
        }
		*num = ft_atoi(args[i++]);
		// ft_printf("%d\n", *num);
		// ft_printf("%p\n", stacks->stack_a);
		ft_lstadd_back(&stacks->stack_a, ft_lstnew((num)));
		ft_printf("%d\n", *(int *)stacks->stack_a->content);
		free(num);
		// stacks->count_a++;
	}
	// if (!is_sort(stacks->stack_a))
	// 	put_error_and_free("the numbers are already in order", stacks);
}
