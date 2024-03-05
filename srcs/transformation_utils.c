/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:31:54 by sting             #+#    #+#             */
/*   Updated: 2024/03/05 13:42:10 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/fdf.h"

/*
- // translate_2d(vars, &vars->cord, -vars->cord[0][0].x, -vars->cord[0][0].y);
	^bring top left corner of grid to frame origin (0,0)
*/
void	bring_center_of_grid_from_topcorner_to_origin(t_vars *vars)
{
	int	grid_width;
	int	grid_height;

	translate_2d(vars, &vars->cord, -vars->cord[0][0].x, -vars->cord[0][0].y);
	grid_width = vars->wc + (vars->wc - 1) * (vars->gap - 1);
	grid_height = vars->line_count + (vars->line_count - 1) * (vars->gap - 1);
	translate_2d(vars, &vars->cord, -(grid_width / 2), -(grid_height / 2));
}

/*
- init size, center grid
- run when KEY_R pressed
*/
// center & enlarge grid to default setting
void	reset_grid(t_vars *vars)
{
	vars->angle_z_axis = 30;
	vars->angle_x_axis = 50;
	vars->angle_y_axis = -30;
	vars->flags.iso = FALSE;
	vars->flags.done_once = FALSE;
	vars->gap = 20;
	resize(vars);
	bring_center_of_grid_from_topcorner_to_origin(vars);
	vars->offset_x = WINDOW_WIDTH / 2;
	vars->offset_y = WINDOW_HEIGHT / 2;
}

t_cord	**duplicate_coordinates(t_vars *vars, t_cord **cord)
{
	int		y;
	t_cord	**dup;

	dup = ft_calloc(vars->line_count, sizeof(t_cord *));
	y = 0;
	while (y < vars->line_count)
	{
		dup[y] = ft_calloc(vars->wc, sizeof(t_cord));
		ft_memcpy(dup[y], cord[y], vars->wc * sizeof(t_cord));
		y++;
	}
	return (dup);
}

void	create_original_cord_copy(t_vars *vars)
{
	vars->cord_ori = duplicate_coordinates(vars, vars->cord);
	translate_2d(vars, &vars->cord_ori, -vars->wc / 2, -vars->line_count / 2);
}
