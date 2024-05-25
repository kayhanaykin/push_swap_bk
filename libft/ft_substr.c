/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaykin <kaykin@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:44:54 by kaykin            #+#    #+#             */
/*   Updated: 2023/12/08 15:44:54 by kaykin           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;

	if (start >= ft_strlen(s))
	{
		len = 0;
	}
	if (len > ft_strlen(s) - start)
	{
		len = ft_strlen(s) - start;
	}
	sub_s = (char *)malloc ((len + 1) * sizeof(char));
	if (sub_s == NULL)
	{
		return (NULL);
	}
	ft_memcpy (sub_s, (s + start), len);
	*(sub_s + len) = '\0';
	return (sub_s);
}
