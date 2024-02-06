/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:43:32 by sting             #+#    #+#             */
/*   Updated: 2024/02/06 15:57:07 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/fdf.h"

int	render_rect(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	j = rect.y;
	while (j < rect.y + rect.height)
	{
		i = rect.x;
		while (i < rect.x + rect.width)
			img_pix_put(img, i++, j, rect.color);
		j++;
	}
	return (0);
}

int	render_hollow_rect(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.x;
	j = rect.y;
	while (i < rect.x + rect.width)
	{
		img_pix_put(img, i, rect.y, rect.color);
			// top horizontal line
		img_pix_put(img, i, rect.y + rect.height, rect.color);
			// bottom horizontal line
		i++;
	}
	while (j < rect.y + rect.height)
	{
		img_pix_put(img, rect.x, j, rect.color);
			// left vertical line
		img_pix_put(img, rect.x + rect.width, j, rect.color);
			// right vertical line
		j++;
	}
	return (0);
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

int	render(void *param)
{
	t_vars *vars;
	
	vars = (t_vars *)param;
	if (vars->win_ptr == NULL)
		return (1);
	render_background(&vars->img, 0x0);
	// render_rect(&vars->img, (t_rect){0, 0, 300, 300, RED_PIXEL});
	// render_rect(&vars->img, (t_rect){WINDOW_WIDTH - 300, WINDOW_HEIGHT - 300,
		// 300, 300, GREEN_PIXEL});
	// render_hollow_rect(&vars->img, (t_rect){WINDOW_WIDTH / 2 - 150,
		// WINDOW_HEIGHT / 2 - 150, 300, 300, 0xF29900FF});
	render_diagonal_line(&vars->img, (t_line_cord){0, 0, WINDOW_WIDTH, WINDOW_HEIGHT,
		RED_PIXEL});
	render_diagonal_line(&vars->img, (t_line_cord){0, WINDOW_HEIGHT, WINDOW_WIDTH, 0,
		GREEN_PIXEL}); // ! heap buffer overflow
	render_diagonal_line(&vars->img, (t_line_cord){0, 0, 100, WINDOW_HEIGHT,
		BLUE_PIXEL}); // ! heap buffer overflow
	render_diagonal_line(&vars->img, (t_line_cord){WINDOW_WIDTH, 0, WINDOW_WIDTH - 100, WINDOW_HEIGHT,
		GREEN_PIXEL});
	render_diagonal_line(&vars->img, (t_line_cord){WINDOW_WIDTH - 100, WINDOW_HEIGHT, WINDOW_WIDTH, 0,
		BLUE_PIXEL});

	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img.img_ptr, 0,
		0);

	return (0);
}
