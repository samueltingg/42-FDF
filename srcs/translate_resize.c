/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_2d.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:19:42 by sting             #+#    #+#             */
/*   Updated: 2024/03/05 14:22:46 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/fdf.h"

void	translate_2d(t_vars *vars, t_cord ***cord, double tx, double ty)
{
	int	y;
	int	x;

	y = 0;
	while (y < vars->line_count)
	{
		x = 0;
		while (x < vars->wc)
		{
			(*cord)[y][x].x += tx;
			(*cord)[y][x].y += ty;
			x++;
		}
		y++;
	}
}

void	resize(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	while (y < vars->line_count)
	{
		x = 0;
		while (x < vars->wc)
		{
			vars->cord[y][x].x = vars->cord_ori[y][x].x * vars->gap;
			vars->cord[y][x].y = vars->cord_ori[y][x].y * vars->gap;
			vars->cord[y][x].z = vars->cord_ori[y][x].z * (vars->gap
					/ vars->z_factor);
			x++;
		}
		y++;
	}
}
