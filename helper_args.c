/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:00:59 by kaykin            #+#    #+#             */
/*   Updated: 2024/05/26 11:28:37 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**parse_args(int ac, char **av)
{
	int		i;
	char	*str;
	char	*temp;
	char	**result;

	str = ft_strdup("");
	i = 0;
	if (ac == 2)
		str = av[1];
	else if (ac > 2)
		while (++i < ac)
		{
			temp = ft_strjoin(str, " ");
			free(str);
			str = ft_strjoin(temp, av[i]);
			free(temp);
		}
	result = ft_split(str, ' ');
	free(str);
	return (result);
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
