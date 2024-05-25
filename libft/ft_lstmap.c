/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaykin <kaykin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:13:32 by kaykin            #+#    #+#             */
/*   Updated: 2023/12/15 15:24:13 by kaykin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*copied_lst;
	t_list	*element;

	copied_lst = NULL;
	if (lst == NULL || f == NULL)
		return (NULL);
	while (lst != NULL)
	{
		element = ft_lstnew (f(lst -> content));
		if (element == NULL)
		{
			ft_lstiter (copied_lst, del);
			return (NULL);
		}
		ft_lstadd_back (&copied_lst, element);
		lst = lst -> next;
	}
	return (copied_lst);
}
