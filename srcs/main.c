/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:24:55 by sting             #+#    #+#             */
/*   Updated: 2024/03/06 10:56:45 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/fdf.h"

int	close_window(void *params)
{
	t_vars	*vars;

	vars = (t_vars *)params;
	mlx_destroy_image(vars->mlx_ptr, vars->img.img_ptr);
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	free_all_cord(vars);
	exit(0);
}

void	init_vars(t_vars *vars)
{
	vars->line_count = 0;
	vars->wc = 0;
	vars->gap = 20;
	vars->z_factor = 5;
	vars->offset_x = 0;
	vars->offset_y = 0;
	vars->angle_x_axis = 0;
	vars->angle_y_axis = 0;
	vars->angle_z_axis = 0;
	vars->flags.iso = FALSE;
	vars->flags.done_once = FALSE;
	vars->flags.default_colors = FALSE;
	vars->flags.split_4_view = FALSE;
	vars->flags.rotate_x = TRUE;
	vars->flags.rotate_y = FALSE;
	vars->flags.rotate_z = FALSE;
}

int	mlx(t_vars *vars)
{
	vars->mlx_ptr = mlx_init();
	if (vars->mlx_ptr == NULL)
		return (MLX_ERROR);
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"FDF");
	if (vars->win_ptr == NULL)
	{
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		return (MLX_ERROR);
	}
	vars->img.img_ptr = mlx_new_image(vars->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	vars->img.addr = mlx_get_data_addr(vars->img.img_ptr,
			&vars->img.bits_per_pixel, &vars->img.line_len, &vars->img.endian);
	mlx_loop_hook(vars->mlx_ptr, &render, vars);
	mlx_hook(vars->win_ptr, ON_KEYDOWN, 1L << 0, &handle_key_event, vars);
	mlx_hook(vars->win_ptr, ON_DESTROY, 0, &close_window, vars);
	mlx_loop(vars->mlx_ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
	{
		ft_putstr_fd("Error: Invalid usage. ",
			2);
		ft_putstr_fd("Provide exactly one filename as argument.\n", 2);
		ft_putstr_fd("Correct Usage : ./fdf filename\n", 2);
		exit(1);
	}
	init_vars(&vars);
	vars.line_count = get_line_count(argv[1]);
	parsing(argv[1], &vars);
	create_original_cord_copy(&vars);
	reset_grid(&vars);
	mlx(&vars);
	return (0);
}

// vars.mlx_ptr = mlx_init();
// if (vars.mlx_ptr == NULL)
// 	return (MLX_ERROR);
// vars.win_ptr = mlx_new_window(vars.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
// 		"FDF");
// if (vars.win_ptr == NULL)
// {
// 	mlx_destroy_window(vars.mlx_ptr, vars.win_ptr);
// 	return (MLX_ERROR);
// }
// vars.img.img_ptr = mlx_new_image(vars.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
// vars.img.addr = mlx_get_data_addr(vars.img.img_ptr,
// 		&vars.img.bits_per_pixel, &vars.img.line_len, &vars.img.endian);
// mlx_loop_hook(vars.mlx_ptr, &render, &vars);
// mlx_hook(vars.win_ptr, ON_KEYDOWN, 1L << 0, &handle_key_event, &vars);
// mlx_hook(vars.win_ptr, ON_DESTROY, 0, &close_window, &vars);
// mlx_loop(vars.mlx_ptr);