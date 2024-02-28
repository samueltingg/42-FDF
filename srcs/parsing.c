/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:55:04 by sting             #+#    #+#             */
/*   Updated: 2024/02/28 16:29:54 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/fdf.h"

void	free_str_arr(char **str_arr)
{
	int	i;

	i = 0;
	while (str_arr[i] != NULL)
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
}

// void	free_cord(t_vars *vars) // ! NOT CHECKED
// {
// 	int y = 0;
// 	while (y < vars->line_count)
// 	{
// 		free(vars->cord[y]);
// 		y++;
// 	}
// 	free(vars->cord);
// }

int	count_words(char *str, char c)
{
	int	count;
	int	flag;

	count = 0;
	flag = 1;
	while (*str)
	{
		if (*str != c && flag == 1)
		{
			count++;
			flag = 0;
		}
		if (*str == c)
		{
			flag = 1;
		}
		str++;
	}
	return (count);
}

/**
 * returns line_count of an open file.
 * - run gnl until it return NULL, to get number of lines in file
 */
int	get_line_count(char *input)
{
	int	line_count;
	int	fd;

	fd = open(input, O_RDONLY);
	if (fd == -1)
	{
		perror("Unable to open the file");
		return (1);
	}
	line_count = 0;
	while (1)
	{
		input = get_next_line(fd);
		if (input == NULL)
			break ;
		line_count++;
		free(input);
	}
	close(fd);
	return (line_count);
}

void parsing(char *input, t_vars *vars)
{
	int		y;
	int		x;
	int		i;
	// store below variables in vars struct (norm)
	int		fd;
	char	*line;
	char	**str_arr;

	fd = open(input, O_RDONLY);
	if (fd == -1)
	{
		perror("Unable to open the file");
		exit(1);
	}
	vars->cord = malloc(vars->line_count * sizeof(t_cord *)); // malloc
	y = 0;
	while (y < vars->line_count)
	{
		line = get_next_line(fd);
		str_arr = ft_split(line, ' ');
		int flag = 0;
		if (!flag)
		{
			vars->wc = count_words(line, ' ');
			flag = 1;
		}
		// printf("wc: %i\n", vars->wc);
		vars->cord[y] = malloc(vars->wc * sizeof(t_cord));
		x = 0;
		// while (str_arr[x])
		while (x < vars->wc)
		{
			vars->cord[y][x].x = x;
			vars->cord[y][x].y = y;
			vars->cord[y][x].z = ft_atoi(str_arr[x]);
			if (ft_strchr((const char *)str_arr[x], ',') != NULL)
			{
				i = 0;
				while (str_arr[x][i] != 'x')
					i++;
				vars->cord[y][x].color = ft_atoi_base((&str_arr[x][++i]),
						"0123456789ABCDEF");
			}
			else
				vars->cord[y][x].color = 0xFFFFFF; // Set a default color if none is provided
			x++;
		}
		free(line);
		free_str_arr(str_arr);
		y++;
	}

}

