/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 11:28:48 by kaykin            #+#    #+#             */
/*   Updated: 2024/05/30 16:32:14 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	*stacks;

	if (ac < 2)
		exit(0);
	stacks = new_stack();
	stacks->args = parse_args(ac, av);
	check_args(stacks);
	add_args_to_stack(stacks);
	action_optimise(stacks);
	t_list * tmp;
		tmp = stacks->stack_a;
	while (tmp)
	{
		ft_printf("%d\n",*(int *)(tmp->content));

		tmp = tmp->next;
	}
		tmp = stacks->stack_b;
	ft_printf("---------\n");
	while (tmp)
	{
		ft_printf("%d\n",*(int *)(tmp->content));
;
		tmp = tmp->next;
	}
	free(stacks);
}

// void	__attribute__((destructor)) a()
// {
// 	system("leaks push_swap");
// }