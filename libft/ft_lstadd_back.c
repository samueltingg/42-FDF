/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:59:50 by sting             #+#    #+#             */
/*   Updated: 2023/10/27 08:06:38 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* adds node 'new' at end of list. */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	(ft_lstlast(*lst))->next = new;
}

/*
- line 21: if there's no node, add 'new' as the first node.
*/