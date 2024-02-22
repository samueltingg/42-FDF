/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_2d.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:19:42 by sting             #+#    #+#             */
/*   Updated: 2024/02/20 13:45:14by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/fdf.h"

void print_grid(t_vars *vars, t_cord **cord)
{
    int y;
	int x;

	y = 0;
	x = 0;
	while (y < vars->line_count)
	{
		x = 0;
		while (x < vars->wc)
		{
			printf("%d,%d,", (int)cord[y][x].x, (int)cord[y][x].y);
			printf("%d  ", (int)cord[y][x].z); // z
			// printf("%d,%d  ", cord[y][x].z, cord[y][x].color); // z & color
			// printf("%3d ", cord[y][x].z);
			x++;
		}
		printf("\n");
		y++;
	}
}