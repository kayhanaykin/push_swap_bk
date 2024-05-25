/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaykin <kaykin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:15:49 by kaykin            #+#    #+#             */
/*   Updated: 2023/12/07 16:48:09 by kaykin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*m_area1;
	const unsigned char	*m_area2;
	size_t				i;

	m_area1 = s1;
	m_area2 = s2;
	i = 0;
	while (i < n)
	{
		if (m_area1[i] != m_area2[i])
		{
			return ((int)(m_area1[i] - m_area2[i]));
		}
		i++;
	}
	return (0);
}
