/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaykin <kaykin@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:21:46 by kaykin            #+#    #+#             */
/*   Updated: 2023/12/08 17:21:46 by kaykin           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_str_fill(char *joined_str, char const *s1, char const *s2);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;

	if (s1 == NULL && s2 == NULL)
	{
		return (NULL);
	}
	joined_str = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), 1);
	if (joined_str == NULL)
	{
		return (NULL);
	}
	ft_str_fill(joined_str, s1, s2);
	if (joined_str == NULL)
	{
		return (NULL);
	}
	return (joined_str);
}

static void	ft_str_fill(char *joined_str, char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < ft_strlen(s1))
	{
		joined_str[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		joined_str[i + j] = s2[j];
		j++;
	}
}
