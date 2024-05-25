/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaykin <kaykin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:11:43 by kaykin            #+#    #+#             */
/*   Updated: 2024/05/21 07:27:03 by kaykin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strlen_gnl(char *stock)
{
	int	i;

	i = 0;
	if (!stock)
		return (0);
	while (stock[i])
		i++;
	return (i);
}

char	*ft_strdup_gnl(char *stock, int len)
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

char	*ft_strjoin_gnl(char *stock, char *buff)
{
	size_t	i;
	int		len;
	char	*temp;

	i = 0;
	len = ft_strlen_gnl(buff);
	if (!stock)
		return (ft_strdup_gnl(buff, len));
	len = len + ft_strlen_gnl(stock);
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (NULL);
	len = 0;
	while (stock[i])
		temp[len++] = stock[i++];
	i = 0;
	while (buff[i])
		temp[len++] = buff[i++];
	temp[len] = '\0';
	free(stock);
	return (temp);
}

int	ft_find_nl(char	*stock)
{
	int		i;

	if (!stock)
		return (0);
	i = 0;
	while (stock[i])
		if (stock[i++] == '\n')
			return (1);
	return (0);
}

char	*extract_line(char **stock)
{
	int		n_loc;
	char	*next_line;
	char	*ptr;

	if (!*stock)
		return (NULL);
	ptr = *stock;
	n_loc = 0;
	while (ptr[n_loc] && ptr[n_loc] != '\n')
		n_loc++;
	if (ptr[n_loc] == '\n')
		n_loc++;
	next_line = ft_strdup_gnl(ptr, n_loc);
	*stock = ft_strdup_gnl(ptr + n_loc, ft_strlen_gnl(ptr + n_loc));
	if (ptr)
		free(ptr);
	ptr = NULL;
	return (next_line);
}
