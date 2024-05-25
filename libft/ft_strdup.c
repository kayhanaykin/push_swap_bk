/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaykin <kaykin@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:18:10 by kaykin            #+#    #+#             */
/*   Updated: 2023/12/08 14:18:10 by kaykin           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	void		*d;
	size_t		size;

	size = ft_strlen (s) + 1;
	d = malloc (size * sizeof(char));
	if (d == NULL)
	{
		return (NULL);
	}
	return ((char *)ft_memcpy (d, (const void *)s, size));
}
