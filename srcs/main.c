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
	int x;
	int y;

	y = 0;
	while (y < vars->line_count)
	{
		x = 0;
		while (x < vars->wc)
		{
			vars->cord[y][x].x += WINDOW_WIDTH / 2;
			vars->cord[y][x].y += WINDOW_HEIGHT / 2;
			x++;
		}
		y++;
	}
}

// center & enlarge grid to default setting
void init_grid(t_vars *vars)
{
	int grid_width;
	int grid_height;

	vars->gap = 20;
	resize(vars, 0);

	// calculation to translate centre of grid to (0,0) top left
	grid_width = vars->wc + (vars->wc -1) * (vars->gap-1);
	grid_height = vars->line_count + (vars->line_count -1) * (vars->gap-1);
	// printf("wc: %i\nline_count: %i\n", vars->wc, vars->line_count);
	// printf("grid_height: %i\ngrid_width: %i\n", grid_height, grid_width);
	translate_2d(vars, -(grid_width / 2), -(grid_height / 2));
	printf("cord[9][5]: %i,%i\n", vars->cord[1][1].x, vars->cord[1][1].y);
	// printf("cord[18][10]: %i,%i\n", vars->cord[10][18].x, vars->cord[10][18].y);

}

int close_window(void *params)
{
	t_vars *vars = (t_vars *)params;

	mlx_destroy_image(vars->mlx_ptr, vars->img.img_ptr);
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	free_cord(vars); // not needed as exit helps to free
	exit(0);
}

int handle_key_event(int keycode, void *param)
{
    t_vars *vars = (t_vars *)param;


	if (keycode == KEY_ESC)
        close_window(vars);
	// Translation
    else if (keycode == KEY_RIGHT)
    	translate_2d(vars, 10, 0);
	else if (keycode == KEY_LEFT)
		translate_2d(vars, -10, 0);
	else if (keycode == KEY_UP)
		translate_2d(vars, 0, -10);
	else if (keycode == KEY_DOWN)
		translate_2d(vars, 0, 10);
	// Enlarge
	else if (keycode == KEY_PLUS)
		resize(vars, 2);
	else if (keycode == KEY_MINUS)
		resize(vars, -2);

    return (0);
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
	init_grid(&vars);

    // PRINT OUT GRID
    int y = 0;
    printf("\n ----Start----\n");
	for (y = 0; y < vars.line_count; y++)
	{
		for (int x = 0; x < vars.wc; x++)
		{
			printf("%d,%d,", vars.cord[y][x].x, vars.cord[y][x].y);
			printf("%d  ", vars.cord[y][x].z); // z
			// printf("%d,%d  ", cord[y][x].z, cord[y][x].color); // z & color
			// printf("%3d ", cord[y][x].z);
		}
		printf("\n");
	}
    // ----------

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
	mlx_key_hook(vars.win_ptr, &handle_key_event, &vars);
	mlx_hook(vars.win_ptr, ON_DESTROY, 0, &close_window, &vars);
	mlx_loop(vars.mlx_ptr);
}


