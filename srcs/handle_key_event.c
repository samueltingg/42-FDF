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

int handle_key_event(int keycode, void *param)
{
    t_vars *vars = (t_vars *)param;

	// printf("\nkey = %i\n", keycode);

	if (keycode == KEY_ESC)
        close_window(vars);
	// Translation
    else if (keycode == KEY_RIGHT)
    	translate_2d(vars, &vars->cord, 10, 0);
	else if (keycode == KEY_LEFT)
		translate_2d(vars, &vars->cord, -10, 0);
	else if (keycode == KEY_UP)
		translate_2d(vars, &vars->cord, 0, -10);
	else if (keycode == KEY_DOWN)
		translate_2d(vars, &vars->cord, 0, 10);
	// Enlarge
	else if (keycode == KEY_PLUS)
		resize(vars, 2);
	else if (keycode == KEY_MINUS)
		resize(vars, -2);
	else if (keycode == KEY_D)
	{
		// bring_grid_center_to_origin(vars);
		rotate(vars, 45);
	}
	else if (keycode == KEY_A)
	{
		// bring_grid_center_to_origin(vars);
		rotate(vars, -45);
	}
	else if (keycode == KEY_R)
		init_grid(vars);
	else if (keycode == KEY_I)
	{
		multiply_matrix(vars, (t_matrix){1/sqrt(2),-1/sqrt(2),0},
							(t_matrix){1/sqrt(6),1/sqrt(6),-2/sqrt(6)},
							(t_matrix){0, 0, 0});
	}
    return (0);
}