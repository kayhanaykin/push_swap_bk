/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaykin <kaykin@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 08:37:38 by kaykin            #+#    #+#             */
/*   Updated: 2023/12/06 08:37:38 by kaykin           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((char *)s + i) == (char)c)
		{
			return (((char *)s + i));
		}
		i++;
	}
	return (NULL);
}
