/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaykin <kaykin@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:30:03 by kaykin            #+#    #+#             */
/*   Updated: 2023/12/08 18:30:03 by kaykin           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_prefix(char const *s1, char const *set, size_t *prefix);
static void	ft_suffix(char const *s1, char const *set, size_t *suffix);
static char	*ft_trimmer(char const *s1, char	**trimmed,
				size_t *prefix, size_t *suffix);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	prefix;
	size_t	suffix;
	char	*trimmed;

	if (s1 == NULL || set == NULL)
	{
		return (NULL);
	}
	ft_prefix (s1, set, &prefix);
	ft_suffix (s1, set, &suffix);
	return (ft_trimmer(s1, &trimmed, &prefix, &suffix));
}

static void	ft_prefix(char const *s1, char const *set, size_t *prefix)
{
	size_t	i;

	*prefix = 0;
	i = 0;
	while (i < ft_strlen(set))
	{
		if (s1[*prefix] == set[i])
		{
			(*prefix)++;
			i = 0;
			continue ;
		}
		i++;
	}
}

static void	ft_suffix(char const *s1, char const *set, size_t *suffix)
{
	size_t	i;
	size_t	len;

	*suffix = 0;
	i = 0;
	len = ft_strlen(s1);
	while (i < ft_strlen(set))
	{
		if (s1[len - 1 - *suffix] == set[i])
		{
			(*suffix)++;
			i = 0;
			continue ;
		}
		i++;
	}
}

static char	*ft_trimmer(char const *s1, char **trimmed,
				size_t *prefix, size_t *suffix)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	if (*prefix + *suffix > len || len == 0)
	{
		*trimmed = (char *)ft_calloc (1, sizeof(char));
		return (*trimmed);
	}
	*trimmed = (char *)ft_calloc (len - *prefix - *suffix + 1, 1);
	if (*trimmed == NULL)
	{
		return (NULL);
	}
	i = 0;
	while ((*prefix + 1) <= (len - *suffix))
	{
		(*trimmed)[i] = s1[*prefix];
		(*prefix)++;
		i++;
	}
	(*trimmed)[i] = '\0';
	return (*trimmed);
}
