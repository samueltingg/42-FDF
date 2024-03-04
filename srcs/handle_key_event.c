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

// void handle_translation(int keycode, t_vars *vars)
// {
//     // if (keycode == KEY_RIGHT)
//     // 	translate_2d(vars, &vars->cord, 10, 0);
// 	// else if (keycode == KEY_LEFT)
// 	// 	translate_2d(vars, &vars->cord, -10, 0);
// 	// else if (keycode == KEY_UP)
// 	// 	translate_2d(vars, &vars->cord, 0, -10);
// 	// else if (keycode == KEY_DOWN)
// 	// 	translate_2d(vars, &vars->cord, 0, 10);
// 	// else
// 	// 	return ;

// 	// -----------
// 	int tx;
// 	int ty;
//     if (keycode == KEY_RIGHT)
// 	{
// 		tx = 10;
// 		ty = 0;
// 	}
// 	else if (keycode == KEY_LEFT)
// 	{
// 		tx = -10;
// 		ty = 0;
// 	}
// 	else if (keycode == KEY_UP)
// 	{
// 		tx = 0;
// 		ty = -10;
// 	}
// 	else if (keycode == KEY_DOWN)
// 	{
// 		tx = 0;
// 		ty = 10;
// 	}
// 	else
// 		return ;
// 	translate_2d(vars, &vars->cord, tx, ty);
// 	vars->offset_x += tx;
// 	vars->offset_y += ty;
// }

// void handle_resize(int keycode, t_vars *vars)
// {
// 	if (keycode == KEY_PLUS)
// 		resize(vars, 1);
// 	else if (keycode == KEY_MINUS)
// 		resize(vars, -1);
// 	else
// 		return ;
// 	// adjustments

// 	// for resize after rotation: rotatate back to original(0 rotation)
// 	// rotate_about_x_axis(vars, vars->angle_x_axis);
// 	// rotate_about_y_axis(vars, vars->angle_y_axis);
// 	// rotate_about_z_axis_2d(vars, vars->angle_z_axis);
// 	// vars->flags.resize = 1;
// 	bring_center_of_grid_from_topcorner_to_origin(vars);

// 	// translate_2d(vars, &vars->cord, vars->offset_x, vars->offset_y);
// 	translate_2d(vars, &vars->cord, (WINDOW_WIDTH / 2) + vars->offset_x, (WINDOW_HEIGHT / 2) + vars->offset_y);

// }

// void handle_rotate(int keycode, t_vars *vars)
// {
// 	if (keycode == KEY_D || keycode == KEY_A || keycode == KEY_W || keycode == KEY_S || keycode == KEY_L || keycode == KEY_J)
// 	{
// 		// bring_center_of_grid_from_topcorner_to_origin(vars);
// 		// translate_2d(vars, &vars->cord, -WINDOW_WIDTH / 2, -WINDOW_HEIGHT / 2);

// 		// try out: bring back to origin
// 		translate_2d(vars, &vars->cord, (-WINDOW_WIDTH / 2) + -vars->offset_x, (-WINDOW_HEIGHT / 2) + -vars->offset_y);

// 	}
// 	if (keycode == KEY_D)
// 		rotate_about_z_axis_2d(vars, 20);
// 	else if (keycode == KEY_A)
// 		rotate_about_z_axis_2d(vars, -20);
// 	else if (keycode == KEY_W)
// 		rotate_about_x_axis(vars, 20);
// 	else if (keycode == KEY_S)
// 		rotate_about_x_axis(vars, -20);
// 	else if (keycode == KEY_L)
// 		rotate_about_y_axis(vars, 20);
// 	else if (keycode == KEY_J)
// 		rotate_about_y_axis(vars, -20);
// 	else
// 		return ;
// 	// adjustment
// 	// center_grid_from_origin(vars);

// 	// try out:
// 	translate_2d(vars, &vars->cord, (WINDOW_WIDTH / 2) + vars->offset_x, (WINDOW_HEIGHT / 2) + vars->offset_y);

// }


// int handle_key_event(int keycode, void *param)
// {
//     t_vars *vars = (t_vars *)param;

// 	printf("\nkey = %i\n", keycode);

// 	handle_resize(keycode, vars);
// 	handle_translation(keycode, vars);
// 	handle_rotate(keycode, vars);
// 	// CLOSE WINDOW
// 	if (keycode == KEY_ESC)
//         close_window(vars);
// 	// RESET
// 	else if (keycode == KEY_R)
// 		init_grid(vars);
// 	// iso
// 	else if (keycode == KEY_I)
// 	{
// 		// multiply_matrix_to_grid(vars, (t_matrix){1/sqrt(2),-1/sqrt(2),0},
// 		// 					(t_matrix){1/sqrt(6),1/sqrt(6),-2/sqrt(6)},
// 		// 					(t_matrix){0, 0, 0});
// 		if (vars->flags.iso == FALSE)
// 		{
// 			translate_2d(vars, &vars->cord, (-WINDOW_WIDTH / 2) + -vars->offset_x, (-WINDOW_HEIGHT / 2) + -vars->offset_y);
// 			rotate_about_z_axis_2d(vars, 45);
// 			rotate_about_x_axis(vars, 45);
// 			translate_2d(vars, &vars->cord, (WINDOW_WIDTH / 2) + vars->offset_x, (WINDOW_HEIGHT / 2) + vars->offset_y);

// 			vars->flags.iso = TRUE;
// 		}
// 		// else
// 		// {
// 		// 	rotate_about_z_axis_2d(vars, -45);
// 		// 	rotate_about_x_axis(vars, -45);
// 		// }
// 	}
//     return (0);
// }

// ==========================================================

void handle_translation(int keycode, t_vars *vars)
{
	int tx;
	int ty;
    if (keycode == KEY_RIGHT)
	{
		tx = 10;
		ty = 0;
	}
	else if (keycode == KEY_LEFT)
	{
		tx = -10;
		ty = 0;
	}
	else if (keycode == KEY_UP)
	{
		tx = 0;
		ty = -10;
	}
	else if (keycode == KEY_DOWN)
	{
		tx = 0;
		ty = 10;
	}
	else
		return ;
	// translate_2d(vars, &vars->cord, tx, ty);
	vars->offset_x += tx;
	vars->offset_y += ty;
}

void handle_resize(int keycode, t_vars *vars)
{

	if (keycode == KEY_PLUS)
		vars->gap++;
	else if (keycode == KEY_MINUS && vars->gap - 1 > 0)
		vars->gap--;
	else
		return ;

}

void handle_rotate(int keycode, t_vars *vars)
{
	double rotate_amt;

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


int handle_key_event(int keycode, void *param)
{
    t_vars *vars = (t_vars *)param;

	printf("\nkey = %i\n", keycode);

	handle_resize(keycode, vars);
	handle_translation(keycode, vars);
	handle_rotate(keycode, vars);
	// CLOSE WINDOW
	if (keycode == KEY_ESC)
        close_window(vars);
	// RESET
	else if (keycode == KEY_R)
	{
		init_grid(vars);
		if (vars->flags.split_4_view == TRUE)
			free_all_splitview_cord(vars);
		vars->flags.split_4_view = FALSE;

	}
	else if (vars->flags.split_4_view == TRUE)
		return (0);
	// iso
	else if (keycode == KEY_I)
	{
		if (vars->flags.iso == FALSE)
		{
			// translate_2d(vars, &vars->cord, (-WINDOW_WIDTH / 2) + -vars->offset_x, (-WINDOW_HEIGHT / 2) + -vars->offset_y);
			// rotate_about_z_axis_2d(vars, 45);
			// rotate_about_x_axis(vars, 45);
			// translate_2d(vars, &vars->cord, (WINDOW_WIDTH / 2) + vars->offset_x, (WINDOW_HEIGHT / 2) + vars->offset_y);

			vars->angle_z_axis = 10;
			vars->angle_x_axis = 60;
			vars->angle_y_axis = -30;
			vars->flags.iso = TRUE;
		}
		// else
		// {
		// 	rotate_about_z_axis_2d(vars, -45);
		// 	rotate_about_x_axis(vars, -45);
		// }
	}
	else if (keycode == KEY_Z) // increases & decrease z_factor
	{
		if ((vars->z_factor - 0.100000) < 0.000001)	// same as if (z_factor == 0.1)
			vars->z_factor = 5;
		else if (vars->z_factor > 0.1)
			vars->z_factor = vars->z_factor - 0.1;
	}
	// turn on default colors
	else if (keycode == KEY_DOT)
		vars->flags.default_colors = TRUE;
	// split 4 view
	else if (keycode == KEY_4)
	{
		vars->flags.split_4_view = TRUE;
		init_other_grids(vars);
		transform_4_grids(vars);	
	}

    return (0);
}
