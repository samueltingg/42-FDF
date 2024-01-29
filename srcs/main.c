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

// void	parsing(int fd, t_cord *cord)
// {
// 	int		y;
// 	int		x;
// 	int		i;
// 	char	*input;
// 	char	**arr;

// 	y = 0;
// 	while (1)
// 	{
// 		input = get_next_line(fd); // malloc
// 		if (input == NULL)
// 			break ;
// 		arr = ft_split(input, ' '); // malloc
// 		x = 0;
// 		while (arr[x]) // "x = x-cordinate"
// 		{
// 			cord->x = x;
// 			cord->y = y;
// 			cord->z = ft_atoi(arr[x]);
// 			if (ft_strchr((const char *)arr[x], ',') != NULL) // if there's ',''
// 			{
// 				i = 0;
// 				while (arr[x][i] != ',')
// 					i++;
// 				i++;
// 				cord->color = ft_atoi((const char *)(&arr[x][i]));
// 			}
// 			x++;
// 		}
// 		free(input);
// 		y++;
// 	}
// }

// int	main(int argc, char **argv)
// {
// 	int fd;
// 	t_cord cord;

// 	if (argc < 2)
// 	{
// 		ft_putstr_fd("Usage : ./fdf <filename>\n", 2);
// 		return (1);
// 	}
// 	fd = open((const char *)argv[1], O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	parsing(fd, &cord);
// }

// int	handle_input(int keysym, t_vars *vars)
// {
//     if (keysym == ON_)
//         mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
//     return (0);
// }

// int	close_window(int keycode, void *params)
// {
// 	t_vars *vars;

// 	vars = (t_vars *)params;
// 	if (keycode == KEY_ESC)
// 	{
// 		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
// 		// vars->win_ptr = NULL;
// 	}
// 	return (0);
// }

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

void	render_background(t_vars *vars, int color)
{
    int	i;
    int	j;

    if (vars->win_ptr == NULL)
        return ;
    i = 0;
    while (i < WINDOW_HEIGHT)
    {
        j = 0;
        while (j < WINDOW_WIDTH)
            mlx_pixel_put(vars->mlx_ptr, vars->win_ptr, j++, i, color);
        ++i;
    }
}

/*
- Puts pixel row by row
*/
int render_rect(t_vars *vars, t_rect rect)
{
    int	i;
    int j;

    if (vars->win_ptr == NULL)
        return (1);
    i = rect.y;
    while (i < rect.y + rect.height)
    {
        j = rect.x;
        while (j < rect.x + rect.width)
            mlx_pixel_put(vars->mlx_ptr, vars->win_ptr, j++, i, rect.color);
        i++;
    }
    return (0);
}

int	render(t_vars *vars)
{
    render_background(vars, 0x0); // RESET frame so that new frame doesn't overlap on top of old frame
    render_rect(vars, (t_rect){0, 0, 300, 300, RED_PIXEL});
    render_rect(vars, (t_rect){WINDOW_WIDTH - 300, WINDOW_HEIGHT - 300, 300, 300, GREEN_PIXEL});
	render_rect(vars, (t_rect){WINDOW_WIDTH / 2 - 150, WINDOW_HEIGHT / 2 - 150, 300, 300, 0xAA9900FF});

    return (0);
}

int close_window(int keycode, void *params)
{
	t_vars *vars = (t_vars *)params;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		exit(0);
	}
	return 0;
}

int	main(void)
{
	t_vars vars;
	t_data	img;

	vars.mlx_ptr = mlx_init();
	if (vars.mlx_ptr == NULL)
		return (MLX_ERROR);
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "first window");
	if (vars.win_ptr == NULL)
	{
		mlx_destroy_window(vars.mlx_ptr, vars.win_ptr);
		return (MLX_ERROR);
	}
	img.img = mlx_new_image(vars.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	printf("bpb: %i\n", img.bits_per_pixel);
	printf("size_line: %i\n", img.line_length);
	printf("endian: %i\n", img.endian);
	printf("img.addr: %s\n", img.addr);

	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	// mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, img.img, 100, 0);

	// for (int x = 0; x < WINDOW_WIDTH; x++)
	// 	mlx_pixel_put(vars.mlx_ptr, vars.win_ptr, x, WINDOW_HEIGHT/2, 0x0000FF00);
	// for (int y = 0; y < WINDOW_WIDTH; y++)
	// 	mlx_pixel_put(vars.mlx_ptr, vars.win_ptr, WINDOW_WIDTH/2, y, 0x000000FF);

	// render(&vars);
	mlx_loop_hook(vars.mlx_ptr, &render, &vars);

	mlx_key_hook(vars.win_ptr, &close_window, &vars);
	// mlx_loop_hook(vars.mlx_ptr, &handle_no_event, &vars);
	// mlx_hook(vars.win_ptr, KEY_ESC, 2, &print_keys, &vars);
	mlx_loop(vars.mlx_ptr);
}
