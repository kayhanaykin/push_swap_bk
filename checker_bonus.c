/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:01:58 by btanir            #+#    #+#             */
/*   Updated: 2024/06/01 14:01:19 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <stdlib.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	t_stacks	*stacks;
	char		*line;

	stacks = new_stacks();
	if (ac < 2)
	{
		free(stacks);
		exit(0);
	}
	stacks->args = parse_args(ac, av, stacks);
	check_args(stacks);
	add_args_to_stack(stacks);
	line = get_next_line(0);
	while (line != NULL)
	{
		line[ft_strlen(line) - 1] = '\0';
		actions(stacks, line);
		free(line);
		line = get_next_line(0);
	}
	if (is_sort(stacks->stack_a) && stacks->count_b == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
