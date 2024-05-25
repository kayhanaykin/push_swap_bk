/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaykin <kaykin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:19:59 by kaykin            #+#    #+#             */
/*   Updated: 2023/12/23 15:07:13 by kaykin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next_node;

	if (lst == NULL )
		return ;
	current = *lst;
	while (current != NULL)
	{
		next_node = current -> next;
		del (current -> content);
		free (current);
		current = next_node;
	}
	*lst = NULL;
}
