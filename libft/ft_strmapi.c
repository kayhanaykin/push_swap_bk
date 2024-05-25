/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaykin <kaykin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:33:41 by kaykin            #+#    #+#             */
/*   Updated: 2023/12/23 15:08:55 by kaykin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*modified_s;
	size_t	length;
	size_t	i;

	length = ft_strlen(s);
	modified_s = (char *)malloc (length * sizeof(char) + 1);
	if (modified_s == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < length)
	{
		modified_s[i] = f (i, s[i]);
		i++;
	}
	modified_s[i] = '\0';
	return (modified_s);
}
