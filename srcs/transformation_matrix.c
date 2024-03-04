/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_matrix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:19:42 by sting             #+#    #+#             */
/*   Updated: 2024/03/04 10:31:58 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/fdf.h"

void multiply_matrix(t_vars *vars, t_cord ***cord, double matrix[3][3])
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
            // x_new = row1.a * vars->cord[y][x].x + row1.b * vars->cord[y][x].y + row1.c * vars->cord[y][x].z;
            // y_new = row2.a * vars->cord[y][x].x + row2.b * vars->cord[y][x].y + row2.c * vars->cord[y][x].z;
            // z_new = row3.a * vars->cord[y][x].x + row3.b * vars->cord[y][x].y + row3.c * vars->cord[y][x].z;
            x_new = (*cord)[y][x].x * matrix[0][0] +
                     (*cord)[y][x].y * matrix[0][1] +
                     (*cord)[y][x].z * matrix[0][2];
            y_new = (*cord)[y][x].x * matrix[1][0] +
                     (*cord)[y][x].y * matrix[1][1] +
                     (*cord)[y][x].z * matrix[1][2];
            z_new = (*cord)[y][x].x * matrix[2][0] +
                     (*cord)[y][x].y * matrix[2][1] +
                     (*cord)[y][x].z * matrix[2][2];

            // Update the coordinates of the point with the new values
            (*cord)[y][x].x = x_new;
            (*cord)[y][x].y = y_new;
            (*cord)[y][x].z = z_new;
            x++;
            // printf("%f,%f,%f  ", x_new,y_new,z_new); // remove
        }
        y++;
        // printf("\n"); // remove
    }
}


void rotate_about_z_axis_2D(t_vars *vars, t_cord ***cord, double angle)
{
    
    // printf("\n ----Rotation----\n");
    // double angle;
    double radian;

    radian = angle * (PI / 180); // convert to radians 
    // printf("\nradian: %f\n", radian);
    // printf("cos(angle): %f\n", cos(radian));

    double matrix[3][3] = {
        {cos(radian), -sin(radian), 0},
        {sin(radian), cos(radian), 0},
        {0, 0, 1}
    };
    multiply_matrix(vars, cord, matrix);
    
    // PRINT OUT GRID
    // printf("\nAFTER matrix multiplication ~~\n");
    // print_grid(vars, vars->cord);
}

void rotate_about_x_axis(t_vars *vars, t_cord ***cord, double angle)
{
    
    // printf("\n ----Rotation about x-axis----\n");
    // double angle;
    double radian;

    radian = angle * (PI / 180); // convert to radians 
    // printf("\nradian: %f\n", radian);
    // printf("cos(angle): %f\n", cos(radian));
    double matrix[3][3] = {
        {1, 0, 0},
        {0, cos(radian), -sin(radian)},
        {0, sin(radian), cos(radian)}
    };
    multiply_matrix(vars, cord, matrix);
    
    
    // PRINT OUT GRID
    // printf("\nAFTER matrix multiplication ~~\n");
    // print_grid(vars, vars->cord);
}


void rotate_about_y_axis(t_vars *vars, t_cord ***cord, double angle)
{
    // printf("\n ----Rotation about y-axis----\n");
    // double angle;
    double radian;

    radian = angle * (PI / 180); // convert to radians 
    // printf("\nradian: %f\n", radian);
    // printf("cos(angle): %f\n", cos(radian));
    double matrix[3][3] = {
        {cos(radian), 0, sin(radian)},
        {0, 1, 0},
        {-sin(radian), 0, cos(radian)}
    };
    multiply_matrix(vars, cord, matrix);


        
    // PRINT OUT GRID
    // printf("\nAFTER matrix multiplication ~~\n");
    // print_grid(vars, vars->cord);
}