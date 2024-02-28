// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/01/22 12:00:19 by sting             #+#    #+#             */
// /*   Updated: 2024/01/23 15:11:28 by sting            ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include ".././includes/fdf.h"

// void increase_z_value(t_vars *vars, int increase_amt)
// {
// 	int x;
// 	int y;

// 	y = 0;
// 	while (y < vars->line_count)
// 	{
// 		x = 0;
// 		while (x < vars->wc)
// 		{
// 			vars->cord[y][x].z += increase_amt;
// 			x++;
// 		}
// 		y++;
// 	}
// }

void center_grid_from_origin(t_vars *vars)
{
	// printf("\n~~Center Grid~~");
	translate_2d(vars, &vars->cord, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
}

void bring_center_of_grid_from_topcorner_to_origin(t_vars *vars)
{
	int grid_width;
	int grid_height;

	// printf("\n~~Bring Grid to Center~~");

	translate_2d(vars, &vars->cord, -vars->cord[0][0].x, -vars->cord[0][0].y); // bring top left corner of grid to frame origin (0,0)
	grid_width = vars->wc + (vars->wc -1) * (vars->gap-1);
	grid_height = vars->line_count + (vars->line_count -1) * (vars->gap-1);
	translate_2d(vars, &vars->cord, -(grid_width / 2), -(grid_height / 2));

}

void init_vars(t_vars *vars)
{
	vars->line_count = 0;
	vars->wc = 0;
	vars->gap = 0;
	vars->offset_x = 0;
	vars->offset_y = 0;
	vars->angle_x_axis = 0;
	vars->angle_y_axis = 0;
	vars->angle_z_axis = 0;
	vars->flags.iso = FALSE;
}

// center & enlarge grid to default setting
void init_grid(t_vars *vars)
{
	// printf("\n====init grid====\n");
	// init variables
	vars->flags.iso = FALSE;
	// vars->flags.resize = FALSE;
	vars->angle_x_axis = 0;
	vars->angle_y_axis = 0;
	vars->angle_z_axis = 0;
	// init_vars(vars);

	vars->gap = 20; // ? init size of grid to 20
	resize(vars);

	// below 2 function only used in this func (except "handle_resize" for now)
	bring_center_of_grid_from_topcorner_to_origin(vars);
	// center_grid_from_origin(vars);
	vars->offset_x = WINDOW_WIDTH/2;
	vars->offset_y = WINDOW_HEIGHT/2;

	// init to 0 so that offset will be based from center of frame
	// vars->offset_x = 0;
	// vars->offset_y = 0;

    // PRINT OUT GRID
    // printf("\n ----Start----\n");
	// print_grid(vars, vars->cord);
}

void create_original_cord_copy(t_vars *vars)
{
	int x;
	int y;

	vars->cord_ori = malloc(vars->line_count * sizeof(t_cord *)); // malloc
    y = 0;
	while (y < vars->line_count)
	{
		vars->cord_ori[y] = malloc(vars->wc * sizeof(t_cord));
		x = 0;
		while (x < vars->wc)
		{
			vars->cord_ori[y][x].x = vars->cord[y][x].x;
			vars->cord_ori[y][x].y = vars->cord[y][x].y;
			vars->cord_ori[y][x].z = vars->cord[y][x].z;
			x++;
		}
		y++;
	}

	// printf("\n====ORIGINAL Grid Copy====");
	translate_2d(vars, &vars->cord_ori, -vars->wc / 2, -vars->line_count /2);

	// if (vars->wc % 2 == 0)
	// 	translate_2d(vars, &vars->cord_ori, 1, 1);

	// print_grid(vars, vars->cord_ori);
}
