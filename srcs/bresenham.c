/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:19:42 by sting             #+#    #+#             */
/*   Updated: 2024/03/06 14:48:15 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/fdf.h"

/*
! Important check
	- 	if (x >= WINDOW_WIDTH || y >= WINDOW_HEIGHT || x < 0 || y < 0)
		return ;

- "img.addr" obtained from mlx_get_data_addr is a pointer 
	to the start of the image data in memory.
	- It allows you to directly access and manipulate the pixel data of the image.

- code below uses a formula to access the memory location of 
	a specific pixel coordinate(given as input) of the image.
*/
void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= WINDOW_WIDTH || y >= WINDOW_HEIGHT || x < 0 || y < 0)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/*
- For Less steep slope
- gradient < 1 OR gradient > -1
- x always increment by 1
- y either (y++ OR y--) OR (no increment)
*/
void	render_line_low(t_img *img, t_line_cord cord)
{
	t_line_var	var;

	var.dx = cord.x2 - cord.x1;
	var.dy = cord.y2 - cord.y1;
	var.yi = 1;
	if (var.dy < 0)
		var.yi = -1;
	var.d = (2 * abs(var.dy)) - var.dx;
	var.x = cord.x1;
	var.y = cord.y1;
	while (var.x <= cord.x2)
	{
		img_pix_put(img, round(var.x), round(var.y), gradient(cord.color1,
				cord.color2, abs(var.dx), var.x - cord.x1));
		if (var.d > 0)
		{
			var.y = var.y + var.yi;
			var.d = var.d + (2 * (abs(var.dy) - var.dx));
		}
		else
			var.d = var.d + (2 * abs(var.dy));
		var.x++;
	}
}

/*
- For STEEP slope
- gradient > 1 OR gradient < -1
- y always increment by 1
- x either (x++ OR x--) OR (no increment)
*/
void	render_line_high(t_img *img, t_line_cord cord)
{
	t_line_var	var;

	var.dy = cord.y2 - cord.y1;
	var.dx = cord.x2 - cord.x1;
	var.xi = 1;
	if (var.dx < 0)
		var.xi = -1;
	var.d = (2 * var.dy) - abs(var.dx);
	var.x = cord.x1;
	var.y = cord.y1;
	while (var.y <= cord.y2)
	{
		img_pix_put(img, round(var.x), round(var.y), gradient(cord.color1,
				cord.color2, abs(var.dy), var.y - cord.y1));
		if (var.d > 0 && var.dx != 0)
		{
			var.x = var.x + var.xi;
			var.d = var.d + (2 * (abs(var.dx) - var.dy));
		}
		else
			var.d = var.d + (2 * abs(var.dx));
		var.y++;
	}
}

void	swap_coordinates(t_line_cord *cord)
{
	int	tmp;

	tmp = cord->x1;
	cord->x1 = cord->x2;
	cord->x2 = tmp;
	tmp = cord->y1;
	cord->y1 = cord->y2;
	cord->y2 = tmp;
	tmp = cord->color1;
	cord->color1 = cord->color2;
	cord->color2 = tmp;
}

/*
	if (change in x > change in y) "line less steep"
		- render_low
	else "line is steep"
		- render high
	-----------------
	if (cord.x1 > cord.x2)
	^swap cord to maintain consistency of drawing from small to big coordinate

*/
void	render_line_bresenham(t_img *img, t_line_cord cord)
{
	if (abs(cord.x2 - cord.x1) > abs(cord.y2 - cord.y1))
	{
		if (cord.x1 > cord.x2)
		{
			swap_coordinates(&cord);
			render_line_low(img, cord);
		}
		else
			render_line_low(img, cord);
	}
	else
	{
		if (cord.y1 > cord.y2)
		{
			swap_coordinates(&cord);
			render_line_high(img, cord);
		}
		else
			render_line_high(img, cord);
	}
}
