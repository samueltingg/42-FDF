/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:26:14 by sting             #+#    #+#             */
/*   Updated: 2025/01/06 15:31:30 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include "../libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// typedef struct s_list
// {
// 	char			*content;
// 	struct s_list	*next;
// }					t_list;

// t_list				*ft_lstnew(void *content);
// t_list				*ft_lstlast(t_list *lst);
// void				ft_lstadd_back(t_list **lst, t_list *new);
// int					ft_lstsize(t_list *list);

/**

* @brief (ft_lstsize combined)
counts no. of characters across many nodes until newline is found
 * | newline not included in count
 */
int		count_to_nl(t_list *list);
char	*get_next_line(int fd);
void	delete_list(t_list **list);

#endif