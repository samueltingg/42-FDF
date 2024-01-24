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

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (MLX_ERROR);
	win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
	if (win_ptr == NULL)
	{
		free(win_ptr);
		return (MLX_ERROR);
	}
	mlx_loop(mlx_ptr);
	mlx_destroy_window(mlx_ptr, win_ptr);
    free(mlx_ptr);
}