/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_2d.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:19:42 by sting             #+#    #+#             */
/*   Updated: 2024/02/15 11:48:26 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/fdf.h"

void translate_2d(t_vars *vars, double tx, double ty)
{
    int y;
    int x;

    y = 0;
    while (y < vars->line_count)
    {
        x = 0;
        while (x < vars->wc)
        {
            vars->cord[y][x].x += tx;
            vars->cord[y][x].y += ty;
            x++;
        }
        y++;
    }
    // PRINT OUT GRID
    y = 0;
    printf("\n ---Translation-----\n");
	for (y = 0; y < vars->line_count; y++)
	{
		for (x = 0; x < vars->wc; x++)
		{
			printf("%d,%d,", vars->cord[y][x].x, vars->cord[y][x].y);
			printf("%d  ", vars->cord[y][x].z); // z
			// printf("%d,%d  ", cord[y][x].z, cord[y][x].color); // z & color
			// printf("%3d ", cord[y][x].z);
		}
		printf("\n");
	}
    // ----------

}

void enlarge(t_vars *vars, double factor)
{
    vars->gap = (double)vars->gap * factor;
}
