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

void center_grid(t_vars *vars)
{
	printf("\n~~Center Grid~~");
	translate_2d(vars, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
}

void bring_grid_center_to_origin(t_vars *vars)
{
	int grid_width;
	int grid_height;

	printf("\n~~Bring Grid to Center~~");

	translate_2d(vars, -vars->cord[0][0].x, -vars->cord[0][0].y); // bring top left corner of grid to frame origin (0,0)
	grid_width = vars->wc + (vars->wc -1) * (vars->gap-1);
	grid_height = vars->line_count + (vars->line_count -1) * (vars->gap-1);
	translate_2d(vars, -(grid_width / 2), -(grid_height / 2));

	vars->at_origin = 1;

}

// center & enlarge grid to default setting
void init_grid(t_vars *vars)
{
	// init variables
	vars->gap = 0;
	vars->offset_x = 0;
	vars->offset_y = 0;
	vars->at_origin = 0;

	resize(vars, 20);
	center_grid(vars);


    // PRINT OUT GRID
    printf("\n ----Start----\n");
	print_grid(vars);
}

int close_window(void *params)
{
	t_vars *vars = (t_vars *)params;

	mlx_destroy_image(vars->mlx_ptr, vars->img.img_ptr);
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	free_cord(vars); // not needed as exit helps to free
	exit(0);
}

int	main(int argc, char **argv)
{
	t_vars vars;

	if (argc != 2)
	{
		ft_putstr_fd("Usage : ./fdf <filename>\n", 2);
		exit (1);
	}
	vars.line_count = get_line_count(argv[1]);
	parsing(argv[1], &vars); // PARSING
	// after_parse(&vars); // meng's advice
	init_grid(&vars);

	vars.mlx_ptr = mlx_init();
	if (vars.mlx_ptr == NULL)
		return (MLX_ERROR);
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	if (vars.win_ptr == NULL)
	{
		mlx_destroy_window(vars.mlx_ptr, vars.win_ptr);
		return (MLX_ERROR);
	}
	vars.img.img_ptr = mlx_new_image(vars.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	vars.img.addr = mlx_get_data_addr(vars.img.img_ptr, &vars.img.bits_per_pixel, &vars.img.line_len,
								&vars.img.endian);

	mlx_loop_hook(vars.mlx_ptr, &render, &vars);
	#ifdef __APPLE__
		mlx_hook(vars.win_ptr, ON_KEYDOWN, 0, &handle_key_event, &vars);
	#elif __linux__
		mlx_key_hook(vars.win_ptr, &handle_key_event, &vars);
	#endif
	mlx_hook(vars.win_ptr, ON_DESTROY, 0, &close_window, &vars);
	mlx_loop(vars.mlx_ptr);
}


