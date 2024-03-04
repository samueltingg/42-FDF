/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_4_view_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:55:04 by sting             #+#    #+#             */
/*   Updated: 2024/03/01 10:24:42 by sting            ###   ########.fr       */
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

}

void transform_4_grids(t_vars *vars)
{
	
}

void render_bonus_grids(t_vars *vars)
{

}
