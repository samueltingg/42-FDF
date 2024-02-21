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

void translate_2d(t_vars *vars, double tx, double ty)
{
    int y;
    int x;
	// printf("\ntx: %f, ty: %f", tx, ty);
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

    // // PRINT OUT GRID
    // y = 0;
    // printf("\n ---Translation-----\n");
	// for (y = 0; y < vars->line_count; y++)
	// {
	// 	for (x = 0; x < vars->wc; x++)
	// 	{
	// 		printf("%d,%d,", vars->cord[y][x].x, vars->cord[y][x].y);
	// 		printf("%d  ", vars->cord[y][x].z); // z
	// 		// printf("%d,%d  ", cord[y][x].z, cord[y][x].color); // z & color
	// 		// printf("%3d ", cord[y][x].z);
	// 	}
	// 	printf("\n");
	// }
    // // ----------

}

void resize(t_vars *vars, int increase_amt)
{
    // if (increase_amt < 1) // 2nd condition -> to prevent 1 * 0.5
    //     return ;
    int y;
    int x;

	if (vars->gap + increase_amt <= 0) // gap cannot be <0
		return ;
	
	int grid_width;
	int grid_height;

	if (vars->gap != 0)
	{
		grid_width = vars->wc + (vars->wc -1) * (vars->gap-1);
		grid_height = vars->line_count + (vars->line_count -1) * (vars->gap-1);
		printf("\ngrid_width: %i\ngrid_height: %i\n", grid_width, grid_height);

		vars->offset_x = vars->cord[0][0].x + grid_width / 2 ;
		vars->offset_y = vars->cord[0][0].y + grid_height / 2;
	}

	// printf("\noffset_x: %i\noffset_y: %i\n", vars->offset_x, vars->offset_y);
	vars->gap += increase_amt;
    y = 0;
	while (y < vars->line_count)
	{
		x = 0;
		while (x < vars->wc)
		{
			vars->cord[y][x].x = x * vars->gap;
			vars->cord[y][x].y = y * vars->gap;
			// vars->cord[y][x].x = (x - (vars->wc / 2)) * vars->gap;
			// vars->cord[y][x].y = (y - (vars->line_count/2)) * vars->gap;
			x++;
		}
		y++;
	}

	bring_grid_center_to_origin(vars);
	translate_2d(vars, vars->offset_x, vars->offset_y);

	// center_grid(vars);
    // printf("\ngap: %d\n", vars->gap);
    // // PRINT OUT GRID
    // y = 0;
    // printf("\n----Enlarge-----\n");
	// for (y = 0; y < vars->line_count; y++)
	// {
	// 	for (x = 0; x < vars->wc; x++)
	// 	{
	// 		printf("%d,%d,", vars->cord[y][x].x, vars->cord[y][x].y);
	// 		printf("%d  ", vars->cord[y][x].z); // z
	// 		// printf("%d,%d  ", cord[y][x].z, cord[y][x].color); // z & color
	// 		// printf("%3d ", cord[y][x].z);
	// 	}
	// 	printf("\n");
	// }
    // // ----------
}

