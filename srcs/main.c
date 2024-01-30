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

/*
- works best if pixel_size equot to size of INT
*/
void	img_pix_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	render_background(t_img *img, int color)
{
    int	i;
    int	j;

    i = 0;
    while (i < WINDOW_HEIGHT)
    {
        j = 0;
        while (j < WINDOW_WIDTH)
            img_pix_put(img, j++, i, color);
        ++i;
    }
}

/*
- Puts pixel row by row
*/
int render_rect(t_img *img, t_rect rect)
{
    int	i;
    int j;

    i = rect.y;
    while (i < rect.y + rect.height)
    {
        j = rect.x;
        while (j < rect.x + rect.width)
            img_pix_put(img, j++, i, rect.color);
        i++;
    }
    return (0);
}

int	render(t_vars *vars)
{
	if (vars->win_ptr == NULL)
		return (1);
	render_background(&vars->img, 0x0);
	render_rect(&vars->img, (t_rect){0, 0, 300, 300, RED_PIXEL});
	render_rect(&vars->img, (t_rect){WINDOW_WIDTH - 300, WINDOW_HEIGHT - 300, 300, 300, GREEN_PIXEL});

	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img.img_ptr, 0, 0);

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
	// t_img	img;

	vars.mlx_ptr = mlx_init();
	if (vars.mlx_ptr == NULL)
		return (MLX_ERROR);
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "first window");
	if (vars.win_ptr == NULL)
	{
		mlx_destroy_window(vars.mlx_ptr, vars.win_ptr);
		return (MLX_ERROR);
	}
	// what's the diff betwen img_ptr & addr ??
	vars.img.img_ptr = mlx_new_image(vars.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	vars.img.addr = mlx_get_data_addr(vars.img.img_ptr, &vars.img.bits_per_pixel, &vars.img.line_length,
								&vars.img.endian);
	printf("bpb: %i\n", vars.img.bits_per_pixel);
	printf("size_line: %i\n", vars.img.line_length);
	printf("endian: %i\n", vars.img.endian);
	printf("img.addr: %s\n", vars.img.addr);

	mlx_loop_hook(vars.mlx_ptr, &render, &vars);

	mlx_key_hook(vars.win_ptr, &close_window, &vars);
	// mlx_loop_hook(vars.mlx_ptr, &handle_no_event, &vars);
	// mlx_hook(vars.win_ptr, KEY_ESC, 2, &print_keys, &vars);
	mlx_loop(vars.mlx_ptr);
}
