/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaykin <kaykin@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:15:40 by kaykin            #+#    #+#             */
/*   Updated: 2023/12/06 22:15:40 by kaykin           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_length;
	size_t	src_length;

	dst_length = ft_strlen(dst);
	src_length = ft_strlen(src);
	i = 0;
	while (*(src + i) != '\0' && dst_length + i + 1 < dstsize)
	{
		*(dst + dst_length + i) = *(src + i);
		i++;
	}
	if (dstsize != 0 && dst_length <= dstsize)
	{
		*(dst + dst_length + i) = '\0';
	}
	if (dstsize > dst_length)
	{
		return (dst_length + src_length);
	}
	else
	{
		return (dstsize + src_length);
	}
}
