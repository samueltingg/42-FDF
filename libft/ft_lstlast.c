/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:44:52 by sting             #+#    #+#             */
/*   Updated: 2023/10/27 08:07:08 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Returns last node of list. */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

// #include <stdio.h>

// int main(void)
// {

//     t_list *node3 = (t_list *)malloc(sizeof(t_list));
//     t_list *node2 = (t_list *)malloc(sizeof(t_list));
//     t_list *node1 = (t_list *)malloc(sizeof(t_list));

//     node1->next = node2;

//     node2->next = node3;

//     node3->content = "last node";
//     node3->next = NULL;

// 	printf ("%s\n", ft_lstlast(node1)->content);
// }