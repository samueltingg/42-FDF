/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:43:32 by sting             #+#    #+#             */
/*   Updated: 2024/03/05 09:36:19 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/fdf.h"

// works best if pixel_size equot to size of INT

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= WINDOW_WIDTH || y >= WINDOW_HEIGHT || x < 0 || y < 0 ) // * IMPORTANT!
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	render_grid(t_vars *vars, t_cord ***grid)
{
	int	j;
	int	i;
	t_line_cord line;

	j = 0;
	while (j < vars->line_count) // horizontal
	{
		i = 0;
		while (i < vars->wc - 1)
		{
			line.x1 = round((*grid)[j][i].x);
			line.y1 = round((*grid)[j][i].y);
			line.x2 = round((*grid)[j][i + 1].x);
			line.y2 = round((*grid)[j][i + 1].y);
			line.color1 = (*grid)[j][i].color;
			line.color2 = (*grid)[j][i + 1].color;
			render_line_bresenham(&vars->img, (t_line_cord){line.x1, line.y1, line.x2, line.y2, line.color1, line.color2});

			i++;
		}
		j++;
	}
	i = 0;
	while (i < vars->wc) // vertical
	{
		j = 0;
		while (j < vars->line_count - 1)
		{
			line.x1 = round((*grid)[j][i].x);
			line.y1 = round((*grid)[j][i].y);
			line.x2 = round((*grid)[j + 1][i].x);
			line.y2 = round((*grid)[j + 1][i].y);
			line.color1 = (*grid)[j][i].color;
			line.color2 = (*grid)[j + 1][i].color;
			render_line_bresenham(&vars->img, (t_line_cord){line.x1, line.y1, line.x2, line.y2, line.color1, line.color2});
			j++;
		}
		i++;
	}
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

// void test_bresenham_line(t_vars *vars)
// {
//     t_line_cord a1;
//     t_line_cord a2;
//     t_line_cord a3;
//     t_line_cord a4;
//     t_line_cord a5;
//     t_line_cord a6;
//     t_line_cord a7;
//     t_line_cord a8;
//     t_line_cord a12;
//     t_line_cord a11;
//     t_line_cord a10;
//     t_line_cord a9;
		//
//     a1.color = RED_PIXEL;
//     a2.color = BLUE_PIXEL;
//     a3.color = RED_PIXEL;
//     a4.color = PURPLE_PIXEL;
//     a5.color = GREEN_PIXEL;
//     a6.color = BLUE_PIXEL;
//     a7.color = GREEN_PIXEL;
//     a8.color = PURPLE_PIXEL;
//     a9.color = RED_PIXEL;
//     a10.color = PURPLE_PIXEL;
//     a11.color = GREEN_PIXEL;
//     a12.color = PURPLE_PIXEL;
		//
//     a1.x1 = 500;
//     a1.y1 = 500;
//     a2.x1 = 500;
//     a2.y1 = 500;
//     a3.x1 = 500;
//     a3.y1 = 500;
//     a4.x1 = 500;
//     a4.y1 = 500;
//     a5.x1 = 500;
//     a5.y1 = 500;
//     a6.x1 = 500;
//     a6.y1 = 500;
//     a7.x1 = 500;
//     a7.y1 = 500;
//     a8.x1 = 500;
//     a8.y1 = 500;
//     a9.x1 = 500;
//     a9.y1 = 500;
//     a10.x1 = 500;
//     a10.y1 = 500;
//     a11.x1 = 500;
//     a11.y1 = 500;
//     a12.x1 = 500;
//     a12.y1 = 500;
		//
//     a1.x2 = 100;
//     a1.y2 =100;
//     a2.x2 = 500; // y axis
//     a2.y2 = 100;
		//
//     a3.x2 = 1000; // ! issue
//     a3.y2 = 100;
		//
//     a4.x2 = 100; // x-axis
//     a4.y2 = 500;
		//
//     a5.x2 = 1000; // x-axis
//     a5.y2 = 500;
		//
//     a6.x2 = 100;
//     a6.y2 = 1000;
//     a7.x2 = 500; // y-axis
//     a7.y2 = 1000;
		//
//     a8.x2 = 1000;
//     a8.y2 = 1000;
//     a9.x2 = 250;
//     a9.y2 = 100;
//     a10.x2 = 750; // ! issue
//     a10.y2 = 100;
//     a11.x2 = 250;
//     a11.y2 = 1000;
//     a12.x2 = 750;
//     a12.y2 = 1000;
		//
// 	// render_line_bresenham(&vars->img, a1);
// 	render_line_bresenham(&vars->img, a2); // y-axis
// 	render_line_bresenham(&vars->img, a4); // x-axis
// 	render_line_bresenham(&vars->img, a5); // x-axis
// 	render_line_bresenham(&vars->img, a3); // ! issue
// 	// render_line_bresenham(&vars->img, a6);
// 	// render_line_bresenham(&vars->img, a7); // y-axis
// 	// render_line_bresenham(&vars->img, a8);
// 	// render_line_bresenham(&vars->img, a9);
// 	render_line_bresenham(&vars->img, a10); // ! issue
// 	// render_line_bresenham(&vars->img, a11);
// 	// render_line_bresenham(&vars->img, a12);
// }

int	render(void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if (vars->win_ptr == NULL)
		return (1);
	render_background(&vars->img, 0x0);

	// * DIAGONAL LINE TEST
	// test_bresenham_line(vars);

	if (vars->flags.split_4_view == TRUE)
		render_bonus_grids(vars);
	else
	{
		// *idea from meng
		resize(vars);
		if (vars->flags.default_colors == TRUE)
			init_default_colors(vars);
		bring_center_of_grid_from_topcorner_to_origin(vars);
		// rotate_about_x_axis(vars, &vars->cord, vars->angle_x_axis);
		// rotate_about_z_axis_2d(vars, &vars->cord, vars->angle_z_axis);
		// rotate_about_y_axis(vars, &vars->cord, vars->angle_y_axis);
		
		// rotate_about_all_axis(vars, &vars->cord, (t_angle){vars->angle_x_axis, vars->angle_y_axis, vars->angle_z_axis});
		rotate_about_all_axis(vars, &vars->cord, (t_angle){vars->angle_x_axis, vars->angle_y_axis, vars->angle_z_axis});


		translate_2d(vars, &vars->cord, vars->offset_x, vars->offset_y);
		render_grid(vars, &vars->cord);
	}


	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img.img_ptr, 0,
		0);
	return (0);
}
