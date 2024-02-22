/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:19:42 by sting             #+#    #+#             */
/*   Updated: 2024/02/22 10:02:55 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/fdf.h"

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
	var.D = (2 * var.dy) - var.dx;
	var.x = cord.x1;
	var.y = cord.y1;
	var.yi = 1;
	if (var.dy < 0)
	{
		var.yi = -1;
		var.dy = -var.dy;
	}
	while (var.x <= cord.x2)
	{
		img_pix_put(img, round(var.x), round(var.y), cord.color);
		if (var.D > 0)
		{
			var.y = var.y + var.yi;
			var.D = var.D + (2 * (var.dy - var.dx));
		}
		else
			var.D = var.D + (2 * var.dy);
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

	var.dx = cord.x2 - cord.x1;
	var.dy = cord.y2 - cord.y1;
	var.D = (2 * var.dy) - var.dx;
	var.x = cord.x1;
	var.y = cord.y1;
	var.xi = 1;
	if (var.dx < 0)
	{
		var.xi = -1;
		var.dx = -var.dx;
	}
	// printf("(%i,%i)\n", var.x, var.y);
	while (var.y <= cord.y2)
	{
		img_pix_put(img, round(var.x), round(var.y), cord.color);
		if (var.D > 0 && var.dx != 0)
		{
			var.x = var.x + var.xi;
			var.D = var.D + (2 * (var.dx - var.dy));
		}
		else
			var.D = var.D + (2 * var.dx);
		var.y++;
	}
}

void swap_coordinates(t_line_cord *cord)
{
    int tmp;

    tmp = cord->x1;
    cord->x1 = cord->x2;
    cord->x2 = tmp;

    tmp = cord->y1;
    cord->y1 = cord->y2;
    cord->y2 = tmp;
}

void	render_line_bresenham(t_img *img, t_line_cord cord)
{
	if (abs(cord.x2 - cord.x1) > abs(cord.y2 - cord.y1)) // Less STEEP
	{
		if (cord.x1 > cord.x2)
		{
            swap_coordinates(&cord);
			render_line_low(img, cord);
		}
		else
			render_line_low(img, cord);
	}
	else // STEEP
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
