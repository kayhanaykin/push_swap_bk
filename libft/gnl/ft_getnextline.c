/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnextline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaykin <kaykin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:11:33 by kaykin            #+#    #+#             */
/*   Updated: 2024/05/21 07:27:20 by kaykin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_read(int fd, char *buff, char **stock)
{
	int	read_size;

	read_size = 1;
	while (read_size > 0)
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		buff[read_size] = '\0';
		*stock = ft_strjoin_gnl(*stock, buff);
		if (ft_find_nl(*stock))
			break ;
	}
	if (buff)
		free(buff);
	buff = NULL;
}

char	*get_next_line(int fd)
{
	static char		*stock;
	char			*buff;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(stock);
		stock = NULL;
		return (NULL);
	}
	if (ft_find_nl(stock))
		return (extract_line(&stock));
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	ft_read (fd, buff, &stock);
	return (extract_line(&stock));
}
