/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:01:58 by btanir            #+#    #+#             */
/*   Updated: 2024/05/31 19:46:27 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <stdlib.h>
#include <unistd.h>

void	a(t_stacks *stacks)
{
	t_list	*tmp;

	tmp = stacks->stack_a;
	ft_printf("\n---STACK A-----\n");
	while (tmp)
	{
		ft_printf("%d\n", *(int *)(tmp->content));
		tmp = tmp->next;
	}
	tmp = stacks->stack_b;
	ft_printf("\n---STACK B-----\n");
	while (tmp)
	{
		ft_printf("%d\n", *(int *)(tmp->content));
		;
		tmp = tmp->next;
	}
	ft_printf("\n");
}

char	*get_next_line(int fd);

int	main(int ac, char **av)
{
	t_stacks *stacks;
	char *line;

	stacks = new_stacks();
	if (ac < 2)
	{
		free(stacks);
		exit(0);
	}
	stacks->args = parse_args(ac, av, stacks);
	check_args(stacks);
	add_args_to_stack(stacks);

	while ((line = get_next_line(0)) != NULL)
	{
		line[ft_strlen(line) - 1] = '\0';
		actions(stacks, line);
		free(line);
	}
	// a(stacks);
	if (is_sort(stacks->stack_a) && stacks->count_b == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);

	return (0);
}