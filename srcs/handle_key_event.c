/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:25:58 by sting             #+#    #+#             */
/*   Updated: 2024/03/05 13:42:59 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/fdf.h"

void	handle_translation(int keycode, t_vars *vars)
{
	int	tx;
	int	ty;

	ty = 0;
	tx = 0;
	if (keycode == KEY_RIGHT)
		tx = 10;
	else if (keycode == KEY_LEFT)
		tx = -10;
	else if (keycode == KEY_UP)
		ty = -10;
	else if (keycode == KEY_DOWN)
		ty = 10;
	else
		return ;
	vars->offset_x += tx;
	vars->offset_y += ty;
}

void	turn_on_flag_based_on_keycode(int keycode, t_vars *vars)
{
	if (keycode == KEY_D || keycode == KEY_A || keycode == KEY_W
		|| keycode == KEY_S || keycode == KEY_L || keycode == KEY_J)
	{
		vars->flags.rotate_x = FALSE;
		vars->flags.rotate_y = FALSE;
		vars->flags.rotate_z = FALSE;
	}
	if (keycode == KEY_D || keycode == KEY_A)
		vars->flags.rotate_z = TRUE;
	else if (keycode == KEY_W || keycode == KEY_S)
		vars->flags.rotate_x = TRUE;
	else if (keycode == KEY_L || keycode == KEY_J)
		vars->flags.rotate_y = TRUE;
}

void	handle_rotate(int keycode, t_vars *vars)
{
	double	rotate_amt;

	turn_on_flag_based_on_keycode(keycode, vars);
	rotate_amt = 10;
	if (keycode == KEY_D)
		vars->angle_z_axis += rotate_amt;
	else if (keycode == KEY_A)
		vars->angle_z_axis += -rotate_amt;
	else if (keycode == KEY_W)
		vars->angle_x_axis += rotate_amt;
	else if (keycode == KEY_S)
		vars->angle_x_axis += -rotate_amt;
	else if (keycode == KEY_L)
		vars->angle_y_axis += rotate_amt;
	else if (keycode == KEY_J)
		vars->angle_y_axis += -rotate_amt;
	else
		return ;
}

/*
-  //if ((vars->z_factor - 0.100000) < 0.000001)
		^same as if (z_factor == 0.1)
*/
void	if_other_key_pressed(int keycode, t_vars *vars)
{
	if (keycode == KEY_Z)
	{
		if ((vars->z_factor - 0.100000) < 0.000001)
			vars->z_factor = 5;
		else if (vars->z_factor > 0.1)
			vars->z_factor = vars->z_factor - 0.1;
	}
	else if (keycode == KEY_DOT)
		vars->flags.default_colors = TRUE;
	else if (keycode == KEY_4)
	{
		vars->flags.split_4_view = TRUE;
		init_other_grids(vars);
		transform_4_grids(vars);
	}
}

	// if (keycode == KEY_I)
	// {
	// 	if (vars->flags.iso == FALSE)
	// 	{
	// 		vars->angle_z_axis = 30;
	// 		vars->angle_x_axis = 50;
	// 		vars->angle_y_axis = 0;
	// 		vars->flags.iso = TRUE;
	// 	}
	// }
/*
- KEY_R -> RESET
*/
int	handle_key_event(int keycode, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if (keycode == KEY_ESC)
		close_window(vars);
	else if (keycode == KEY_R)
	{
		reset_grid(vars);
		if (vars->flags.split_4_view == TRUE)
			free_all_splitview_cord(vars);
		vars->flags.split_4_view = FALSE;
	}
	else if (vars->flags.split_4_view == TRUE)
		return (0);
	else if (keycode == KEY_PLUS)
		vars->gap++;
	else if (keycode == KEY_MINUS && vars->gap - 1 > 0)
		vars->gap--;
	handle_translation(keycode, vars);
	handle_rotate(keycode, vars);
	if_other_key_pressed(keycode, vars);
	return (0);
}

	// printf("\nkey = %i\n", keycode);
	// printf("x: %f, y: %f, z: %f\n", vars->angle_x_axis, vars->angle_y_axis,
	// vars->angle_z_axis);
