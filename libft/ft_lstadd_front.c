/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:04:33 by sting             #+#    #+#             */
/*   Updated: 2023/10/26 11:59:45 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

/*
PLAN
	1. set new->next = ori 1st node
	2. set ptr to current 1st node

line 20: why "lst = &new" is wrong
    - lst is diff variable from the variable declared in main.
    - changing what it points to doesn't change 
        what the variable in main points to.
*/