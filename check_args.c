/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaykin <kaykin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:57:55 by kaykin            #+#    #+#             */
/*   Updated: 2024/06/03 17:57:57 by kaykin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		check_args_is_number(t_stacks *stacks);
static void		check_args_is_duplicate(t_stacks *stacks);
static void		check_is_int(t_stacks *stacks);
static long int	ft_atol(const char *str);

void	check_args(t_stacks *stacks)
{
	check_args_is_number(stacks);
	check_is_int(stacks);
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
				put_error_and_free(stacks);
			j++;
		}
		i++;
	}
}

static void	check_is_int(t_stacks *stacks)
{
	int			i;
	char		**args;

	i = 0;
	args = stacks->args;
	while (args[i])
	{
		if (ft_atol(args[i]) > INTMAX || ft_atol(args[i]) < INTMIN)
			put_error_and_free(stacks);
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
				put_error_and_free(stacks);
			j++;
		}
		i++;
	}
}

static long int	ft_atol(const char *str)
{
	int			i;
	int			mult;
	long int	nb;

	mult = 1;
	nb = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mult *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	nb *= mult;
	return (nb);
}
