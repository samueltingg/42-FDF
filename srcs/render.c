/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:43:32 by sting             #+#    #+#             */
/*   Updated: 2024/02/13 13:54:45 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/fdf.h"

// works best if pixel_size equot to size of INT
void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= WINDOW_WIDTH || y >= WINDOW_HEIGHT) // * IMPORTANT!
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// void render_horizontal_line(t_img *img, t_line_cord line)
// {
// 	int x;

// 	x = line.x1;
// 	while (x <= line.x2)
// 	{
// 		img_pix_put(img, x, line.y1, line.color);
// 		x++;
// 	}
// }

// void render_vertical_line(t_img *img, t_line_cord line)
// {
// 	int y;

// 	y = line.y1;
// 	while (y <= line.y2)
// 	{
// 		img_pix_put(img, line.x1, y, line.color);
// 		y++;
// 	}
// }

void	render_grid(t_vars *vars)
{
	int y;
	int x;
	int gap;

	gap = 20;
	y = 0;
	while (y < vars->line_count) // horizontal
	{
		x = 0;
		while (x < vars->wc - 1)
		{
			render_line_bresenham(&vars->img, (t_line_cord){x * gap + WINDOW_WIDTH/2, y * gap + WINDOW_HEIGHT/2, (x + 1) * gap + WINDOW_WIDTH/2, y * gap + WINDOW_HEIGHT/2, PURPLE_PIXEL});
			x++;
		}
		y++;
	}
	x = 0;
	while (x < vars->wc) // vertical
	{
		y = 0;
		while (y < vars->line_count - 1)
		{
			render_line_bresenham(&vars->img, (t_line_cord){x * gap + WINDOW_WIDTH/2, y * gap + WINDOW_HEIGHT/2, x * gap + WINDOW_WIDTH/2, (y + 1) * gap + WINDOW_HEIGHT/2, PURPLE_PIXEL});
			y++;
		}
		// ! COLOR not done;
		x++;
	}
}

int	render_rect(t_img *img, t_rect rect) // ! do I need this?
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
	// 	WINDOW_HEIGHT / 2 - 150, 300, 300, 0xF29900FF});
	// render_line_bresenham(&vars->img, (t_line_cord){0, 0, WINDOW_WIDTH, WINDOW_HEIGHT,
	// 	RED_PIXEL});
	// render_line_bresenham(&vars->img, (t_line_cord){0, WINDOW_HEIGHT, WINDOW_WIDTH, 0,
	// 	GREEN_PIXEL});
	// render_line_bresenham(&vars->img, (t_line_cord){0, 0, 100, WINDOW_HEIGHT,
	// 	BLUE_PIXEL});
	// render_line_bresenham(&vars->img, (t_line_cord){WINDOW_WIDTH, 0, WINDOW_WIDTH - 100, WINDOW_HEIGHT,
	// 	GREEN_PIXEL});
	// render_line_bresenham(&vars->img, (t_line_cord){WINDOW_WIDTH - 100, WINDOW_HEIGHT, WINDOW_WIDTH, 0,
	// 	BLUE_PIXEL});


	// * GRID
	render_grid(vars);


	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img.img_ptr, 0,
		0);
	return (0);
}
