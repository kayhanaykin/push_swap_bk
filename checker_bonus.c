/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:01:58 by btanir            #+#    #+#             */
/*   Updated: 2024/06/03 11:09:10 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <stdlib.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	t_stacks	*stacks;
	char		*line;
	char		*temp;
	char		*temp2;
	char		**action_list;

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
	while (1)
	{
		temp2 = get_next_line(0);
		temp = ft_strjoin(line, temp2);
		if (temp2 == NULL)
		{
			free(temp2);
			free(line);
			break ;
		}
		free(temp2);
		free(line);
		line = temp;
	}
	action_list = ft_split(line, '\n');
	ft_printf("%s\n", action_list[1]);
	while (*action_list)
	{
		actions(stacks, *action_list);
		action_list++;
	}
	if (is_sort(stacks->stack_a) && stacks->count_b == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	// system("leaks checker");
	return (0);
}
