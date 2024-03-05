/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:55:04 by sting             #+#    #+#             */
/*   Updated: 2024/03/05 16:46:15 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/fdf.h"

// void	free_str_arr(char **str_arr)
// {
// 	int	i;

// 	i = 0;
// 	while (str_arr[i] != NULL)
// 	{
// 		free(str_arr[i]);
// 		i++;
// 	}
// 	free(str_arr);
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

/*
	* Set a default color if none is provided
		// else
			// vars->cord[y][x].color = 0xFFFFFF;
*/
void	store_coordinates_n_color_by_line(t_vars *vars, char **str_arr, int y)
{
	int	i;
	int	x;

	x = 0;
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
			vars->cord[y][x].color = ft_atoi_base_fdf((&str_arr[x][++i]),
					"0123456789ABCDEF");
		}
		else
			vars->cord[y][x].color = 0xFFFFFF;
		x++;
	}
}

void	parse_lines(t_vars *vars, int fd)
{
	int		y;
	char	*line;
	char	**str_arr;

	y = 0;
	while (y < vars->line_count)
	{
		line = get_next_line(fd);
		str_arr = ft_split(line, ' ');
		if (vars->flags.done_once == FALSE)
		{
			vars->wc = count_words(line, ' ');
			vars->flags.done_once = TRUE;
		}
		vars->cord[y] = malloc(vars->wc * sizeof(t_cord));
		store_coordinates_n_color_by_line(vars, str_arr, y);
		free(line);
		free_str_arr(str_arr);
		y++;
	}
}

void	parsing(char *input, t_vars *vars)
{
	int	fd;

	fd = open(input, O_RDONLY);
	if (fd == -1)
	{
		perror("Unable to open the file");
		exit(1);
	}
	vars->cord = malloc(vars->line_count * sizeof(t_cord *));
	parse_lines(vars, fd);
}

// y = 0;
// while (y < vars->line_count)
// {
// 	line = get_next_line(fd);
// 	str_arr = ft_split(line, ' ');
// 	if (vars->flags.done_once == FALSE)
// 	{
// 		vars->wc = count_words(line, ' ');
// 		vars->flags.done_once = TRUE;
// 	}
// 	vars->cord[y] = malloc(vars->wc * sizeof(t_cord));
// 	x = 0;
// 	while (x < vars->wc)
// 	{
// 		vars->cord[y][x].x = x;
// 		vars->cord[y][x].y = y;
// 		vars->cord[y][x].z = ft_atoi(str_arr[x]);
// 		if (ft_strchr((const char *)str_arr[x], ',') != NULL)
// 		{
// 			i = 0;
// 			while (str_arr[x][i] != 'x')
// 				i++;
// 			vars->cord[y][x].color = ft_atoi_base_fdf((&str_arr[x][++i]),
// 					"0123456789ABCDEF");
// 		}
// 		else
// 			vars->cord[y][x].color = 0xFFFFFF;
// 				// Set a default color if none is provided
// 		x++;
// 	}
// 	free(line);
// 	free_str_arr(str_arr);
// 	y++;
// }