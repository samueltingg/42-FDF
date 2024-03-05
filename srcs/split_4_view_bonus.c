/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_4_view_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:55:04 by sting             #+#    #+#             */
/*   Updated: 2024/03/05 13:46:52 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/fdf.h"

void	init_other_grids(t_vars *vars)
{
	vars->gap = 0;
	if (((vars->wc + (vars->wc - 1) * (vars->gap - 1)) < 400))
	{
		while ((vars->wc + (vars->wc - 1) * (vars->gap - 1)) < 400)
			vars->gap++;
	}
	else
		vars->gap = 1;
	resize(vars);
	bring_center_of_grid_from_topcorner_to_origin(vars);
	vars->cord_bottom = duplicate_coordinates(vars, vars->cord);
	vars->cord_right = duplicate_coordinates(vars, vars->cord);
	vars->cord_left = duplicate_coordinates(vars, vars->cord);
}

void	transform_4_grids(t_vars *vars)
{
	rotate_about_x_axis(vars, &vars->cord_bottom, 180);
	rotate_about_x_axis(vars, &vars->cord_left, 90);
	rotate_about_y_axis(vars, &vars->cord_left, -90);
	rotate_about_x_axis(vars, &vars->cord_right, 90);
	rotate_about_y_axis(vars, &vars->cord_right, 90);
	translate_2d(vars, &vars->cord, WINDOW_WIDTH * 1 / 4, WINDOW_HEIGHT * 1
		/ 4);
	translate_2d(vars, &vars->cord_bottom, WINDOW_WIDTH * 3 / 4, WINDOW_HEIGHT
		* 1 / 4);
	translate_2d(vars, &vars->cord_left, WINDOW_WIDTH * 1 / 4, WINDOW_HEIGHT * 7
		/ 8);
	translate_2d(vars, &vars->cord_right, WINDOW_WIDTH * 3 / 4, WINDOW_HEIGHT
		* 7 / 8);
}

void	render_splitview_grids(t_vars *vars)
{
	render_grid(vars, &vars->cord);
	render_grid(vars, &vars->cord_bottom);
	render_grid(vars, &vars->cord_left);
	render_grid(vars, &vars->cord_right);
}
