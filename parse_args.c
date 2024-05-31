/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:00:59 by kaykin            #+#    #+#             */
/*   Updated: 2024/05/31 17:05:27 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*convert_to_one_str(int ac, char **av);

char	**parse_args(int ac, char **av, t_stacks *stacks)
{
	char	*str;
	char	**result;

	str = convert_to_one_str(ac, av);
	result = ft_split(str, ' ');
	if (result[0] == NULL)
	{
		free(result[0]);
		free(result);
		free(stacks);
		exit(0);
	}
	return (free(str), result);
}

static char	*convert_to_one_str(int ac, char **av)
{
	int		i;
	char	*str;
	char	*temp;

	i = 0;
	if (ac == 2)
		str = ft_strdup(av[1]);
	else if (ac > 2)
	{
		str = ft_strdup("");
		while (++i < ac)
		{
			temp = ft_strjoin(str, " ");
			free(str);
			str = ft_strjoin(temp, av[i]);
			free(temp);
		}
	}
	return (str);
}
