/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaykin <kaykin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:37:04 by kaykin            #+#    #+#             */
/*   Updated: 2023/12/23 15:07:01 by kaykin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	digit_count(long int *n_temp, int *sign, int *digit_counter);
static void	to_ascii(char **result, long int *n_temp, int *sign,
				int *digit_counter);

char	*ft_itoa(int n)
{
	long int	n_temp;
	int			sign;
	int			digit_counter;
	char		*result;

	n_temp = n;
	digit_count (&n_temp, &sign, &digit_counter);
	result = (char *)ft_calloc (digit_counter + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	n_temp = n;
	to_ascii(&result, &n_temp, &sign, &digit_counter);
	return (result);
}

static void	digit_count(long int *n_temp, int *sign, int *digit_counter)
{
	*digit_counter = 1;
	*sign = 1;
	if (*n_temp < 0)
	{
		*sign *= -1;
		*n_temp *= -1;
		(*digit_counter)++;
	}
	while (*n_temp > 9)
	{
		*n_temp = *n_temp / 10;
		(*digit_counter)++;
	}
}

static void	to_ascii(char **result, long int *n_temp,
				int *sign, int *digit_counter)
{
	int	i;

	i = *digit_counter;
	if (*sign == -1)
	{
		*n_temp *= -1;
		(*result)[0] = '-';
	}
	while (*n_temp > 9)
	{
		(*result)[i - 1] = '0' + (*n_temp % 10);
		*n_temp = *n_temp / 10;
		i--;
	}
	(*result)[i - 1] = '0' + (*n_temp % 10);
	(*result)[*digit_counter] = '\0';
}
