/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:00:59 by kaykin            #+#    #+#             */
/*   Updated: 2024/05/26 14:42:47 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**parse_args(int ac, char **av)
{
	int		i;
	char	*str;
	char	*temp;
	char	**result;

	i = 0;
	str = ft_strdup("");
	if (ac == 2)
		str = ft_strdup(av[1]);
	else if (ac > 2)
		while (++i < ac)
		{
			temp = ft_strjoin(str, " ");
			free(str);
			str = ft_strjoin(temp, av[i]);
			free(temp);
		}
	if (ft_strlen(str) < 2)
	{
		free(str);
		exit(0);
	}
	result = ft_split(str, ' ');
	free(str);
	return (result);
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

void	check_args(t_stacks *stacks)
{
	check_args_is_number(stacks);
	check_args_is_duplicate(stacks);
}