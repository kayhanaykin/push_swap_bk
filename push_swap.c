/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaykin <kaykin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 11:28:48 by kaykin            #+#    #+#             */
/*   Updated: 2024/05/31 14:42:54 by kaykin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	*stacks;

	stacks = new_stacks();
	if (ac < 2)
	{
		free(stacks);
		exit(0);
	}
	stacks->args = parse_args(ac, av, stacks);
	check_args(stacks);
	add_args_to_stack(stacks);
	action_optimise(stacks);
}
// void	__attribute__((destructor)) b()
// {
// 	system("leaks push_swap");
// }