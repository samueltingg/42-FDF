/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:01:34 by sting             #+#    #+#             */
/*   Updated: 2023/10/26 13:49:14 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	if (!lst)
		return (0);
	count = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

// #include <stdio.h>

// int main(void)
// {
//     t_list node3;
//     node3.next = NULL;

//     t_list node2;
//     node2.next = &node3;

//     t_list node1;
//     node1.next = &node2;

// 	printf ("%i\n", ft_lstsize(&node1));
// }	

/*
- lst => pointer to 1st node
*/