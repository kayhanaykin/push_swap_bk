/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaykin <kaykin@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:03:00 by kaykin            #+#    #+#             */
/*   Updated: 2023/12/08 13:03:00 by kaykin           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memory;

	if (nmemb * size > (size_t)(-1))
	{
		return (NULL);
	}
	memory = (void *)malloc (nmemb * size);
	if (memory == NULL)
	{
		return (NULL);
	}
	return (ft_memset (memory, '\0', (nmemb * size)));
}
