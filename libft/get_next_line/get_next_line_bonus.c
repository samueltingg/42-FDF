/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:30:12 by sting             #+#    #+#             */
/*   Updated: 2024/01/16 16:54:40 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Repeated calls (e.g. using a loop) to get_next_line() function
	should read text file pointed to by the file descriptor,
	one line at a time.
• function returns the line that was read.
If there is nothing else to read or if an error occurred, it should return NULL.
*/
#include "get_next_line_bonus.h"

int	find_newline(t_list *list)
{
	int	i;

	while (list != NULL)
	{
		i = 0;
		while (((char *)list->content)[i] != '\0')
		{
			if (((char *)list->content)[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

void	create_list(int fd, t_list **list)
{
	char	*buf;
	int		char_read;
	t_list	*new_node;

	while (!find_newline(*list))
	{
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return ;
		char_read = read(fd, buf, BUFFER_SIZE);
		if (!char_read)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		new_node = ft_lstnew(buf);
		ft_lstadd_back(list, new_node);
	}
}

char	*return_proper_str(t_list *list)
{
	char	*proper_str;
	int		i;
	int		j;

	proper_str = (char *)malloc(sizeof(char) * (count_to_nl(list) + 2));
	if (proper_str == NULL)
		return (NULL);
	i = 0;
	while (list != NULL)
	{
		j = 0;
		while (((char *)list->content)[j])
		{
			if (((char *)list->content)[j] == '\n')
			{
				proper_str[i] = '\n';
				proper_str[i + 1] = '\0';
				return (proper_str);
			}
			proper_str[i++] = ((char *)list->content)[j++];
		}
		list = list->next;
	}
	proper_str[i] = '\0';
	return (proper_str);
}

void	store_leftover_str(t_list **list)
{
	char	*leftover;
	int		i;
	int		j;
	t_list	*last_node;

	leftover = NULL;
	last_node = ft_lstlast(*list);
	i = count_to_nl(last_node);
	if (!(((char *)last_node->content)[i] == '\0'
		|| (((char *)last_node->content)[i] == '\n'
		&& ((char *)last_node->content)[i + 1] == '\0')))
	{
		leftover = (char *)malloc(BUFFER_SIZE + 1);
		if (!leftover)
			return ;
		j = 0;
		while (((char *)last_node->content)[i] != '\0'
			&& ((char *)last_node->content)[++i])
			(leftover)[j++] = ((char *)last_node->content)[i];
		leftover[j] = '\0';
	}
	delete_list(list);
	if (leftover)
		*list = ft_lstnew(leftover);
}

char	*get_next_line(int fd)
{
	static t_list	*list[FOPEN_MAX];
	char			*proper_str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &proper_str, 0) < 0)
		return (NULL);
	create_list(fd, &list[fd]);
	if (list[fd] == NULL)
		return (NULL);
	proper_str = return_proper_str(list[fd]);
	store_leftover_str(&list[fd]);
	return (proper_str);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int	fd;

// 	fd = open("test", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	printf("gnl: |%s|\n", get_next_line(fd));
// 	printf("---------------------\n");
// 	printf("gnl: |%s|\n", get_next_line(fd));
// 	printf("---------------------\n");
// 	printf("gnl: |%s|\n", get_next_line(fd));
// 	printf("---------------------\n");
// 	printf("gnl: |%s|\n", get_next_line(fd));
// 	close(fd);
// 	return (0);
// }
