/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaykin <kaykin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 11:28:48 by kaykin            #+#    #+#             */
/*   Updated: 2024/05/25 16:30:24 by kaykin           ###   ########.fr       */
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
	// add_args_to_stack(args, stacks);
}

// void	__attribute__((destructor)) a()
// {
// 	system("leaks push_swap");
// }