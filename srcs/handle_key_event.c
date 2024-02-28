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

void handle_translation(int keycode, t_vars *vars)
{
    // if (keycode == KEY_RIGHT)
    // 	translate_2d(vars, &vars->cord, 10, 0);
	// else if (keycode == KEY_LEFT)
	// 	translate_2d(vars, &vars->cord, -10, 0);
	// else if (keycode == KEY_UP)
	// 	translate_2d(vars, &vars->cord, 0, -10);
	// else if (keycode == KEY_DOWN)
	// 	translate_2d(vars, &vars->cord, 0, 10);
	// else
	// 	return ;

	// -----------
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
	translate_2d(vars, &vars->cord, tx, ty);
	vars->offset_x += tx;
	vars->offset_y += ty;
}

void handle_resize(int keycode, t_vars *vars)
{
	if (keycode == KEY_PLUS)
		resize(vars, 1);
	else if (keycode == KEY_MINUS)
		resize(vars, -1);
	else
		return ;
	// adjustments

	// for resize after rotation: rotatate back to original(0 rotation)
	// rotate_about_x_axis(vars, vars->angle_x_axis);
	// rotate_about_y_axis(vars, vars->angle_y_axis);
	// rotate_about_z_axis_2D(vars, vars->angle_z_axis);
	// vars->flags.resize = 1;
	bring_grid_center_to_origin(vars);

	// translate_2d(vars, &vars->cord, vars->offset_x, vars->offset_y);
	translate_2d(vars, &vars->cord, (WINDOW_WIDTH / 2) + vars->offset_x, (WINDOW_HEIGHT / 2) + vars->offset_y);

}

void handle_rotate(int keycode, t_vars *vars)
{
	if (keycode == KEY_D || keycode == KEY_A || keycode == KEY_W || keycode == KEY_S || keycode == KEY_L || keycode == KEY_J)
	{
		// bring_grid_center_to_origin(vars);
		// translate_2d(vars, &vars->cord, -WINDOW_WIDTH / 2, -WINDOW_HEIGHT / 2);

		// try out: bring back to origin
		translate_2d(vars, &vars->cord, (-WINDOW_WIDTH / 2) + -vars->offset_x, (-WINDOW_HEIGHT / 2) + -vars->offset_y);

	}
	if (keycode == KEY_D)
		rotate_about_z_axis_2D(vars, 20);
	else if (keycode == KEY_A)
		rotate_about_z_axis_2D(vars, -20);
	else if (keycode == KEY_W)
		rotate_about_x_axis(vars, 20);
	else if (keycode == KEY_S)
		rotate_about_x_axis(vars, -20);
	else if (keycode == KEY_L)
		rotate_about_y_axis(vars, 20);
	else if (keycode == KEY_J)
		rotate_about_y_axis(vars, -20);
	else
		return ;
	// adjustment
	// center_grid_from_origin(vars);

	// try out:
	translate_2d(vars, &vars->cord, (WINDOW_WIDTH / 2) + vars->offset_x, (WINDOW_HEIGHT / 2) + vars->offset_y);

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
		init_grid(vars);
	// iso
	else if (keycode == KEY_I)
	{
		// multiply_matrix(vars, (t_matrix){1/sqrt(2),-1/sqrt(2),0},
		// 					(t_matrix){1/sqrt(6),1/sqrt(6),-2/sqrt(6)},
		// 					(t_matrix){0, 0, 0});
		if (vars->flags.iso == FALSE)
		{
			translate_2d(vars, &vars->cord, (-WINDOW_WIDTH / 2) + -vars->offset_x, (-WINDOW_HEIGHT / 2) + -vars->offset_y);
			rotate_about_z_axis_2D(vars, 45);
			rotate_about_x_axis(vars, 45);
			translate_2d(vars, &vars->cord, (WINDOW_WIDTH / 2) + vars->offset_x, (WINDOW_HEIGHT / 2) + vars->offset_y);

			vars->flags.iso = TRUE;
		}
		// else
		// {
		// 	rotate_about_z_axis_2D(vars, -45);
		// 	rotate_about_x_axis(vars, -45);
		// }
	}
    return (0);
}
