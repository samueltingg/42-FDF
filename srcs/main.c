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
	translate_2d(vars, &vars->cord, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
}

void bring_grid_center_to_origin(t_vars *vars)
{
	int grid_width;
	int grid_height;

	printf("\n~~Bring Grid to Center~~");

	translate_2d(vars, &vars->cord, -vars->cord[0][0].x, -vars->cord[0][0].y); // bring top left corner of grid to frame origin (0,0)
	grid_width = vars->wc + (vars->wc -1) * (vars->gap-1);
	grid_height = vars->line_count + (vars->line_count -1) * (vars->gap-1);
	translate_2d(vars, &vars->cord, -(grid_width / 2), -(grid_height / 2));

}

// center & enlarge grid to default setting
void init_grid(t_vars *vars)
{
	// init variables
	vars->gap = 0;

	resize(vars, 20);
	bring_grid_center_to_origin(vars);
	center_grid(vars);

	// init to 0 so that offset will be based from center of frame
	vars->offset_x = 0;
	vars->offset_y = 0;

    // PRINT OUT GRID
    printf("\n ----Start----\n");
	print_grid(vars, vars->cord);
}

void create_original_cord_copy(t_vars *vars)
{
	int x;
	int y;

	// resize()
	vars->cord_ori = malloc(vars->line_count * sizeof(t_cord *)); // malloc
    y = 0;
	while (y < vars->line_count)
	{
		vars->cord_ori[y] = malloc(vars->wc * sizeof(t_cord));
		x = 0;
		while (x < vars->wc)
		{
			vars->cord_ori[y][x].x = vars->cord[y][x].x;
			vars->cord_ori[y][x].y = vars->cord[y][x].y;
			vars->cord_ori[y][x].z = vars->cord[y][x].z;
			x++;
		}
		y++;
	}
	int grid_width = vars->wc + (vars->wc -1) * (vars->gap-1);
	int grid_height = vars->line_count + (vars->line_count -1) * (vars->gap-1);
	printf("grid_width: %i | grid_height: %i\n", grid_width, grid_height);

	printf("\n---ORIGINAL Grid Copy---");
	translate_2d(vars, &vars->cord_ori, -vars->wc / 2, -vars->line_count /2);

	// if (vars->wc % 2 == 0)
	// 	translate_2d(vars, &vars->cord_ori, 1, 1);

	// print_grid(vars, vars->cord_ori);
}

int close_window(void *params)
{
	t_vars *vars = (t_vars *)params;

	mlx_destroy_image(vars->mlx_ptr, vars->img.img_ptr);
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	free_cord(vars); // not needed as exit helps to free
	exit(0);
}

void init_vars(t_vars *vars)
{
	vars->line_count = 0;
	vars->wc = 0;
	vars->gap = 1;
	vars->offset_x = 0;
	vars->offset_y = 0;
	vars->flags.iso = FALSE;
}
int	main(int argc, char **argv)
{
	t_vars vars;

	if (argc != 2)
	{
		ft_putstr_fd("Usage : ./fdf <filename>\n", 2);
		exit (1);
	}
	init_vars(&vars);
	vars.line_count = get_line_count(argv[1]);
	parsing(argv[1], &vars); // PARSING

	// create_original_cord_copy(&vars);
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


