/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:19:42 by sting             #+#    #+#             */
/*   Updated: 2024/02/13 16:47:23 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/fdf.h"

void mutiply_matrix(t_vars *vars, t_matrix row1, t_matrix row2, t_matrix row3)
{
    int x;
    int y;
    int x_new;
    int y_new;
    int z_new;

    y = 0;
    while (y < vars->line_count)
    {
        x = 0;
        while (x < vars->wc)
        {
            // Multiply the coordinates of each point with the transformation matrix
            x_new = row1.a * vars->cord[y][x].x + row1.b * vars->cord[y][x].y + row1.c * vars->cord[y][x].z;
            y_new = row2.a * vars->cord[y][x].x + row2.b * vars->cord[y][x].y + row2.c * vars->cord[y][x].z;
            z_new = row3.a * vars->cord[y][x].x + row3.b * vars->cord[y][x].y + row3.c * vars->cord[y][x].z;

            // Update the coordinates of the point with the new values
            vars->cord[y][x].x = x_new;
            vars->cord[y][x].y = y_new;
            vars->cord[y][x].z = z_new;

            x++;
        }
        y++;
    }
}

			// vars->cord[y][x].x;
			// vars->cord[y][x].y = ;
			// vars->cord[y][x].z = ;