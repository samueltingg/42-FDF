/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_4_view_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:55:04 by sting             #+#    #+#             */
/*   Updated: 2024/03/04 14:10:37 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/fdf.h"


void init_other_grids(t_vars *vars)
{
	vars->gap = WINDOW_WIDTH/2/vars->wc; // init splitview grid size
	int grid_width =vars->wc + (vars->wc -1) * (vars->gap-1);
	printf("grid width: %i\n", grid_width);

	resize(vars);
	bring_center_of_grid_from_topcorner_to_origin(vars);

	vars->cord_back = duplicate_coordinates(vars, vars->cord);
	vars->cord_right = duplicate_coordinates(vars, vars->cord);
	vars->cord_left = duplicate_coordinates(vars, vars->cord);

}

void transform_4_grids(t_vars *vars)
{
	// * ROTATION
	// top
	// rotate_about_x_axis(vars, &vars->cord, 80);
	// back
	// rotate_about_z_axis_2d(vars, &vars->cord_back, 180);
	rotate_about_x_axis(vars, &vars->cord_back, 180);
	// left
	rotate_about_x_axis(vars, &vars->cord_left, 90);
	rotate_about_y_axis(vars, &vars->cord_left, -90);
	// right
	rotate_about_x_axis(vars, &vars->cord_right, 90);
	rotate_about_y_axis(vars, &vars->cord_right, 90);

	
	// TRANSLATION
	translate_2d(vars, &vars->cord, WINDOW_WIDTH * 1/4, WINDOW_HEIGHT * 1/4);
	translate_2d(vars, &vars->cord_back, WINDOW_WIDTH * 3/4, WINDOW_HEIGHT * 1/4);
	translate_2d(vars, &vars->cord_left, WINDOW_WIDTH * 1/4, WINDOW_HEIGHT * 3/4);
	translate_2d(vars, &vars->cord_right, WINDOW_WIDTH * 3/4, WINDOW_HEIGHT * 3/4);

	
	// printf("\n==front==\n");
	// print_grid(vars, vars->cord);
	// printf("\n==back==\n");
	// print_grid(vars, vars->cord_back);
	// printf("\n==right==\n");
	// print_grid(vars, vars->cord_right);
	// printf("\n==left==\n");
	// print_grid(vars, vars->cord_left);
}

void render_bonus_grids(t_vars *vars)
{
	render_grid(vars, &vars->cord); // front
	render_grid(vars, &vars->cord_back);
	render_grid(vars, &vars->cord_left);
	render_grid(vars, &vars->cord_right);
}
