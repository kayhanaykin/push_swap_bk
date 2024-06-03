/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaykin <kaykin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:58:06 by kaykin            #+#    #+#             */
/*   Updated: 2024/06/03 17:58:09 by kaykin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <stdlib.h>
#include <unistd.h>

static void	parse_actions(t_stacks *stacks);
static void	check_line(char *line, t_list *parsed_actions);

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
	parse_actions(stacks);
	if (is_sort(stacks->stack_a) && stacks->count_b == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(stacks->stack_a);
	free(stacks);
	return (0);
}

static void	parse_actions(t_stacks *stacks)
{
	char	*line;
	t_list	*parsed_actions;
	t_list	*head;

	parsed_actions = NULL;
	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
		{
			free(line);
			break ;
		}
		ft_lstadd_back(&parsed_actions, ft_lstnew(ft_strdup(line)));
		check_line(line, parsed_actions);
		free(line);
	}
	head = parsed_actions;
	while (parsed_actions)
	{
		actions(stacks, (char *)parsed_actions->content);
		parsed_actions = parsed_actions->next;
	}
	free_stack(head);
}

static void	check_line(char *line, t_list *parsed_actions)
{
	if (ft_strncmp(line, "sa\n", 4) != 0 && ft_strncmp(line, "sb\n", 4) != 0
		&& ft_strncmp(line, "ss\n", 4) != 0 && ft_strncmp(line, "ra\n", 4) != 0
		&& ft_strncmp(line, "rb\n", 4) != 0 && ft_strncmp(line, "rr\n", 4) != 0
		&& ft_strncmp(line, "rra\n", 5) != 0 && ft_strncmp(line, "rrb\n",
			5) != 0 && ft_strncmp(line, "rrr\n", 5) != 0 && ft_strncmp(line,
			"pa\n", 4) != 0 && ft_strncmp(line, "pb\n", 4) != 0)
	{
		ft_printf("Error\n");
		free_stack(parsed_actions);
		free(line);
		exit(-1);
	}
}
