/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:55:04 by sting             #+#    #+#             */
/*   Updated: 2024/02/05 13:23:07 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/fdf.h"

void free_str_arr(char **str_arr)
{
	int i;
	
	i = 0;
	while (str_arr[i] != NULL)
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
}


/**
 * returns line_count of an open file.
 * - run gnl until it return NULL, to get number of lines in file
 */
int	get_line_count(int fd)
{
	char	*input;
	int		line_count;

	line_count = 0;
	while (1)
	{
		input = get_next_line(fd);
		if (input == NULL)
			break ;
		line_count++;
	}
	close(fd);
	return (line_count);
}

t_cord	**parsing(int fd)
{
	t_cord	**cord;
	int		y;
	int		x;
	char	*line;
	int		line_count;
	char	**str_arr;
	int		wc;
	int		i;

	line_count = get_line_count(fd);
	cord = malloc(line_count * sizeof(t_cord *));
	y = 0;
	while (y < line_count)
	{
		line = gnl();
		str_arr = ft_split(line, ' ');
		wc = count_words(line, ' ');
		cord[y] = malloc(wc * sizeof(t_cord));
		x = 0;
		while (str_arr[x])
		{
			cord[y][x].z = ft_atoi(str_arr[x]);
			if (ft_strchr((const char *)str_arr[x], ',') != NULL)
			{
				i = 0;
				while (str_arr[x][i] != ',')
					i++;
				i++;
				cord[y][x].color = ft_atoi((const char *)(&str_arr[x][i]));
			}
			else
			{
				cord[y][x].color = BLUE_PIXEL;
					// Set a default color if none is provided
			}
			x++;
		}
		free_str_arr(str_arr);
		y++;
	}

	return (cord);
}
