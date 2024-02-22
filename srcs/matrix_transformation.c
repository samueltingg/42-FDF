/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:19:42 by sting             #+#    #+#             */
/*   Updated: 2024/02/22 14:08:38 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/fdf.h"

void multiply_matrix(t_vars *vars, t_matrix row1, t_matrix row2, t_matrix row3)
{
    // printf("\nRow 1: %f, %f, %f\n", row1.a, row1.b, row1.c);
    // printf("Row 2: %f, %f, %f\n", row2.a, row2.b, row2.c);
    // printf("Row 3: %f, %f, %f\n", row3.a, row3.b, row3.c);
    int x;
    int y;
    double x_new;
    double y_new;
    double z_new;

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

            printf("%f,%f,%f  ", x_new,y_new,z_new); // remove
        }
        y++;

        printf("\n"); // remove

    }
}

void rotate(t_vars *vars, double angle)
{
    
    printf("\n ----Rotation----\n");
    // double angle;
    double radian;

    radian = angle * (PI / 180); // convert to radians 
    printf("\nradian: %f\n", radian);
    printf("cos(angle): %f\n", cos(radian));

    // bring_grid_center_to_origin(vars);
	translate_2d(vars, -WINDOW_WIDTH / 2, -WINDOW_HEIGHT / 2);

    multiply_matrix(vars, (t_matrix){cos(radian), -sin(radian), 0},
                          (t_matrix){sin(radian), cos(radian), 0},
                          (t_matrix){0, 0, 1});
    center_grid(vars);

    // PRINT OUT GRID
    printf("\nAFTER matrix multiplication ~~\n");
    print_grid(vars);
}

