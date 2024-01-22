/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:42:58 by sting             #+#    #+#             */
/*   Updated: 2023/10/27 08:01:13 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*tmp;
	t_list	*new_lst;

	if (!lst || !f || !del)
		return (NULL);
	new_node = ft_lstnew(f(lst->content));
	new_lst = new_node;
	tmp = new_node;
	lst = lst->next;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (new_node == NULL)
			ft_lstclear(&new_lst, del);
		tmp->next = new_node;
		tmp = new_node;
		lst = lst->next;
	}
	return (new_lst);
}

/*
- return copy of existing list but modified by func f

APPROACH
1. Create new node with content of lst but changed by f
2. new_lst is set to 1st new_node (to return address of 1st node)
3. tmp stores the address of previous node.
4. if malloc fails, clear all previous nodes created.

problem
	- how many times to malloc , idk no. of nodes
		- use while loop?

*/