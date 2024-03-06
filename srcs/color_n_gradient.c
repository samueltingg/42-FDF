/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_n_gradient.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:50:13 by sting             #+#    #+#             */
/*   Updated: 2024/03/06 09:31:19 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/fdf.h"

/*
NOT REQUIRED
- presets color or pixes with z height > 0,
	and pixels surrounding it
	(code checks for top/bottom/left/right neighbour)
*/
void	init_default_colors(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	while (y < vars->line_count)
	{
		x = 0;
		while (x < vars->wc)
		{
			if (vars->cord[y][x].z > 0)
			{
				vars->cord[y][x].color = RED_PIXEL;
				if (y > 0 && (int)vars->cord[y - 1][x].z == 0)
					vars->cord[y - 1][x].color = BLUE_PIXEL;
				if (y < vars->line_count - 1 && vars->cord[y + 1][x].z == 0)
					vars->cord[y + 1][x].color = BLUE_PIXEL;
				if (x > 0 && (int)vars->cord[y][x - 1].z == 0)
					vars->cord[y][x - 1].color = BLUE_PIXEL;
				if (x < vars->wc - 1 && (int)(vars->cord[y][x + 1].z) == 0)
					vars->cord[y][x + 1].color = BLUE_PIXEL;
			}
			x++;
		}
		y++;
	}
}

int	gradient(int startcolor, int endcolor, int len, int position)
{
	double	increment[3];
	int		new[3];
	int		newcolor;

	increment[0] = (double)((R(endcolor)) - (R(startcolor)))
		/ (double)len;
	increment[1] = (double)((G(endcolor)) - (G(startcolor)))
		/ (double)len;
	increment[2] = (double)((B(endcolor)) - B((startcolor)))
		/ (double)len;
	new[0] = (R(startcolor)) + round(position * increment[0]);
	new[1] = (G(startcolor)) + round(position * increment[1]);
	new[2] = (B(startcolor)) + round(position * increment[2]);
	newcolor = RGB(new[0], new[1], new[2]);
	return (newcolor);
}
