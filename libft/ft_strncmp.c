/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaykin <kaykin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:44:56 by kaykin            #+#    #+#             */
/*   Updated: 2023/12/07 15:39:10 by kaykin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*word1;
	unsigned char	*word2;

	word1 = (unsigned char *)s1;
	word2 = (unsigned char *)s2;
	i = 0;
	while (i < n && *word1 != '\0' && *word2 != '\0')
	{
		if (*word1 != *word2)
		{
			return (*word1 - *word2);
		}
		word1++;
		word2++;
		i++;
	}
	if (i == n)
	{
		return (0);
	}
	else
	{
		return (*word1 - *word2);
	}
}
