/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_4_view_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:55:04 by sting             #+#    #+#             */
/*   Updated: 2024/03/04 10:26:09 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/fdf.h"


void init_other_grids(t_vars *vars)
{
	vars->gap = 33;
	resize(vars);
	bring_center_of_grid_from_topcorner_to_origin(vars);

	vars->cord_back = duplicate_coordinates(vars, vars->cord);
	vars->cord_right = duplicate_coordinates(vars, vars->cord);
	vars->cord_left = duplicate_coordinates(vars, vars->cord);
	printf("\n==back==\n");
	print_grid(vars, vars->cord_back);
	printf("\n==right==\n");
	print_grid(vars, vars->cord_right);
	printf("\n==left==\n");
	print_grid(vars, vars->cord_left);

}

void transform_4_grids(t_vars *vars)
{
	// TRANSLATION
	translate_2d(vars, &vars->cord, WINDOW_WIDTH * (1/4), WINDOW_HEIGHT * (1/4));
	translate_2d(vars, &vars->cord_back, WINDOW_WIDTH * (3/4), WINDOW_HEIGHT * (1/4));
	translate_2d(vars, &vars->cord_left, WINDOW_WIDTH * (1/4), WINDOW_HEIGHT * (3/4));
	translate_2d(vars, &vars->cord_right, WINDOW_WIDTH * (3/4), WINDOW_HEIGHT * (3/4));

}

// void render_bonus_grids(t_vars *vars)
// {
	
// }
