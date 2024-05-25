/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaykin <kaykin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:31:54 by kaykin            #+#    #+#             */
/*   Updated: 2023/12/14 17:31:54 by kaykin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*header;

	if (lst == NULL || new == NULL)
		return ;
	header = *lst;
	if (header == NULL)
	{
		*lst = new;
	}
	else
	{
		header = ft_lstlast (header);
		header -> next = new;
	}
}
