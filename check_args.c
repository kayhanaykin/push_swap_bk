/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:29:20 by btanir            #+#    #+#             */
/*   Updated: 2024/05/31 16:54:17 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_args_is_number(t_stacks *stacks);
static void	check_args_is_duplicate(t_stacks *stacks);

void	check_args(t_stacks *stacks)
{
	check_args_is_number(stacks);
	check_args_is_duplicate(stacks);
}

static void	check_args_is_number(t_stacks *stacks)
{
	int		i;
	int		j;
	char	**args;

	i = 0;
	args = stacks->args;
	while (args[i])
	{
		j = 0;
		if ((args[i][j] == '+' || args[i][j] == '-') && args[i][j + 1]
			&& args[i][j + 1] != '0')
			j++;
		while (args[i][j])
		{
			if (!(args[i][j] >= '0' && args[i][j] <= '9'))
				put_error_and_free("Non-numerical data", stacks);
			j++;
		}
		i++;
	}
}

static void	check_args_is_duplicate(t_stacks *stacks)
{
	int		i;
	int		j;
	char	**args;

	i = 0;
	args = stacks->args;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_atoi(args[j]) == ft_atoi(args[i]))
				put_error_and_free("Duplicate data", stacks);
			j++;
		}
		i++;
	}
}
