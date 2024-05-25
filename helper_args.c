/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaykin <kaykin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:00:59 by kaykin            #+#    #+#             */
/*   Updated: 2024/05/25 16:40:20 by kaykin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**parse_args(int ac, char **av)
{
	int		i;
	char	*str;

	str = "";
	i = 0;
	if (ac == 2)
		str = av[1];
	else if (ac > 2)
		while (++i < ac)
			str = ft_strjoin(str, ft_strjoin(" ", av[i]));
	return (ft_split(str, ' '));
}

void	check_args(t_stacks *stacks)
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
