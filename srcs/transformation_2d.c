/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_2d.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:19:42 by sting             #+#    #+#             */
/*   Updated: 2024/02/20 09:19:25 by sting            ###   ########.fr       */
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

void resize(t_vars *vars, int increase_amt)
{
    // if (increase_amt < 1) // 2nd condition -> to prevent 1 * 0.5
    //     return ;
    int y;
    int x;

	vars->gap += increase_amt;
    y = 0;
    // if (vars->cord[0][1].x * factor < 1)
    //     return ; // check if cord(other than most top left) would reach 0,0 after enlarge
                // when reach 0,0 , size can't increase as anything*0 = 0
	while (y < vars->line_count)
	{
		x = 0;
		while (x < vars->wc)
		{
			// vars->cord[y][x].x = (double)vars->cord[y][x].x * factor;
			// vars->cord[y][x].y = (double)vars->cord[y][x].y * factor;
			vars->cord[y][x].x = x * vars->gap;
			vars->cord[y][x].y = y * vars->gap;
			x++;
		}
		y++;
	}

	center_grid(vars);
    printf("\ngap: %d\n", vars->gap);
    // PRINT OUT GRID
    y = 0;
    printf("\n----Enlarge-----\n");
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
