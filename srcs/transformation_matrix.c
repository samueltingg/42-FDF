/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_matrix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:19:42 by sting             #+#    #+#             */
/*   Updated: 2024/03/04 11:18:35 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/fdf.h"

void	multiply_matrix(t_vars *vars, t_cord ***cord, double matrix[3][3])
{
	int		x;
	int		y;
	double	x_new;
	double	y_new;
	double	z_new;

	y = 0;
	while (y < vars->line_count)
	{
		x = 0;
		while (x < vars->wc)
		{
			// Multiply the coordinates of each point with the transformation matrix
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

void	rotate_about_z_axis_2d(t_vars *vars, t_cord ***cord, double angle)
{
	double	radian;
	double	matrix[3][3];

	radian = angle * (PI / 180); // convert to radians
	matrix[0][0] = cos(radian);
	matrix[0][1] = -sin(radian);
	matrix[0][2] = 0;
	matrix[1][0] = sin(radian);
	matrix[1][1] = cos(radian);
	matrix[1][2] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 1;
	// printf("\n ----Rotation----\n");
	// printf("\nradian: %f\n", radian);
	multiply_matrix(vars, cord, matrix);
	// PRINT OUT GRID
	// printf("\nAFTER matrix multiplication ~~\n");
	// print_grid(vars, vars->cord);
}

void	rotate_about_x_axis(t_vars *vars, t_cord ***cord, double angle)
{
	double	radian;
	double	matrix[3][3];

	// printf("\n ----Rotation about x-axis----\n");
	radian = angle * (PI / 180); // convert to radians
	// printf("\nradian: %f\n", radian);
	// printf("cos(angle): %f\n", cos(radian));
	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = cos(radian);
	matrix[1][2] = -sin(radian);
	matrix[2][0] = 0;
	matrix[2][1] = sin(radian);
	matrix[2][2] = cos(radian);
	multiply_matrix(vars, cord, matrix);
	// PRINT OUT GRID
	// printf("\nAFTER matrix multiplication ~~\n");
	// print_grid(vars, vars->cord);
}

void	rotate_about_y_axis(t_vars *vars, t_cord ***cord, double angle)
{
	// printf("\n ----Rotation about y-axis----\n");
	double radian;
    double matrix[3][3];

	radian = angle * (PI / 180); // convert to radians
	// printf("\nradian: %f\n", radian);
	// printf("cos(angle): %f\n", cos(radian));
	matrix[0][0] = cos(radian);
	matrix[0][1] = 0;
	matrix[0][2] = sin(radian);
	matrix[1][0] = 0;
	matrix[1][1] = 1;
	matrix[1][2] = 0;
	matrix[2][0] = -sin(radian);
	matrix[2][1] = 0;
	matrix[2][2] = cos(radian);
	multiply_matrix(vars, cord, matrix);

	// PRINT OUT GRID
	// printf("\nAFTER matrix multiplication ~~\n");
	// print_grid(vars, vars->cord);
}
