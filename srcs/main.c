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

int	closee(t_vars *vars)
{
	// if (keycode == )
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	return (0);
}

// int	main(void)
// {
// 	t_vars vars;

// 	vars.mlx_ptr = mlx_init();
// 	if (vars.mlx_ptr == NULL)
// 		return (MLX_ERROR);
// 	vars.win_ptr = mlx_new_window(vars.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "first window");
// 	if (vars.win_ptr == NULL)
// 	{
// 		free(vars.win_ptr);
// 		return (MLX_ERROR);
// 	}

// 	// mlx_key_hook(vars.win_ptr, &handle_input, &vars);

// 	mlx_hook(vars.win_ptr, ON_KEYDOWN, 0, closee, &vars);

// 	mlx_loop(vars.mlx_ptr);
// 	mlx_destroy_window(vars.mlx_ptr, vars.win_ptr);
//     free(vars.mlx_ptr);
// }

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
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
		free(vars.win_ptr);
		return (MLX_ERROR);
	}
	// void	*mlx;
	// void	*mlx_win;

	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
	img.img = mlx_new_image(vars.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);

	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, img.img, 100, 0);
	mlx_hook(vars.win_ptr, ON_KEYDOWN, 0, closee, &vars);
	mlx_loop(vars.mlx_ptr);

	mlx_loop(vars.mlx_ptr);
	mlx_destroy_window(vars.mlx_ptr, vars.win_ptr);
//     free(vars.mlx_ptr);
}
