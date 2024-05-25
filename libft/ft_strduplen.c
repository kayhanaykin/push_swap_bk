/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strduplen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaykin <kaykin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:18:06 by kaykin            #+#    #+#             */
/*   Updated: 2024/05/03 13:20:33 by kaykin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strduplen(char *stock, int len)
{
	char	*temp;
	int		i;

	if (!stock || !len)
		return (NULL);
	i = 0;
	temp = (char *)malloc((len + 1) * sizeof(char));
	while (i < len)
	{
		temp[i] = stock[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
