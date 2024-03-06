/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_side_bar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:46:04 by sting             #+#    #+#             */
/*   Updated: 2024/03/06 10:29:08 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/fdf.h"

void	render_sidebar(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH / 7)
			img_pix_put(img, j++, i, color);
		++i;
	}
}

void	render_text(void *mlx_ptr, void *win_ptr)
{
	int	y;

	y = 30;
	mlx_string_put(mlx_ptr, win_ptr, 15, y += 30, 0xFFFFFF,
		"Close window: ESC");
	mlx_string_put(mlx_ptr, win_ptr, 15, y += 30, 0xFFFFFF, "Reset: R");
	mlx_string_put(mlx_ptr, win_ptr, 15, y += 30, 0xFFFFFF,
		"Rotate abt x-axis: W / S");
	mlx_string_put(mlx_ptr, win_ptr, 15, y += 30, 0xFFFFFF,
		"Rotate abt z-axis: A / D");
	mlx_string_put(mlx_ptr, win_ptr, 15, y += 30, 0xFFFFFF,
		"Rotate abt y-axis: J / L");
	mlx_string_put(mlx_ptr, win_ptr, 15, y += 30, 0xFFFFFF,
		"Translate: arrow keys");
	mlx_string_put(mlx_ptr, win_ptr, 15, y += 30, 0xFFFFFF, "Resize: + / -");
	mlx_string_put(mlx_ptr, win_ptr, 15, y += 30, 0xFFFFFF,
		"z height: Z");
	mlx_string_put(mlx_ptr, win_ptr, 15, y += 30, 0xFFFFFF,
		"Turn on preset colors: .");
	mlx_string_put(mlx_ptr, win_ptr, 15, y += 30, 0xFFFFFF, "Split 4 view: 4");
	mlx_string_put(mlx_ptr, win_ptr, 40, y += 21, 0xFFFFFF, "(turn off: R)");
}
