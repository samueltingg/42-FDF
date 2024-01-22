/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:05:23 by sting             #+#    #+#             */
/*   Updated: 2024/01/16 16:32:04 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*new_node;

// 	new_node = (t_list *)malloc(sizeof(t_list));
// 	if (new_node == NULL)
// 		return (NULL);
// 	new_node->content = content;
// 	new_node->next = NULL;
// 	return (new_node);
// }

// t_list	*ft_lstlast(t_list *lst)
// {
// 	if (!lst)
// 		return (NULL);
// 	while (lst->next != NULL)
// 	{
// 		lst = lst->next;
// 	}
// 	return (lst);
// }

// void	ft_lstadd_back(t_list **lst, t_list *new)
// {
// 	if (!lst)
// 		return ;
// 	if (!(*lst))
// 	{
// 		*lst = new;
// 		return ;
// 	}
// 	(ft_lstlast(*lst))->next = new;
// }

int	count_to_nl(t_list *list)
{
	int		i;
	t_list	*last_node;
	t_list	*lst;
	int		lstsize;

	last_node = ft_lstlast(list);
	if (!list || !last_node)
		return (0);
	lst = list;
	lstsize = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		lstsize++;
	}
	i = 0;
	while (last_node && ((char *)last_node->content)[i]
		&& ((char *)last_node->content)[i] != '\n')
		i++;
	return (((lstsize - 1) * BUFFER_SIZE) + i);
}

void	delete_list(t_list **list)
{
	t_list	*next_node;

	while (*list)
	{
		next_node = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = next_node;
	}
}
