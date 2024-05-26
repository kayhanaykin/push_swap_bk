/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 11:28:48 by kaykin            #+#    #+#             */
/*   Updated: 2024/05/26 12:07:39 by btanir           ###   ########.fr       */
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
	t_list * tmp;
		tmp = stacks->stack_a;
	while (tmp)
	{
		ft_printf("%d\n",*(int *)(tmp->content));
		tmp = tmp->next;
	}
	free(stacks);
}

void	__attribute__((destructor)) a()
{
	system("leaks push_swap");
}