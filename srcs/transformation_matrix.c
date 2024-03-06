/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_matrix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:19:42 by sting             #+#    #+#             */
/*   Updated: 2024/03/06 09:42:07 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/fdf.h"

void	multiply_matrix_to_grid(t_vars *vars, t_cord ***cord,
		double matrix[3][3])
{
	int		x;
	int		y;
	double	x_new;
	double	y_new;
	double	z_new;

	y = -1;
	while (++y < vars->line_count)
	{
		x = -1;
		while (++x < vars->wc)
		{
			x_new = (*cord)[y][x].x * matrix[0][0] + (*cord)[y][x].y
				* matrix[0][1] + (*cord)[y][x].z * matrix[0][2];
			y_new = (*cord)[y][x].x * matrix[1][0] + (*cord)[y][x].y
				* matrix[1][1] + (*cord)[y][x].z * matrix[1][2];
			z_new = (*cord)[y][x].x * matrix[2][0] + (*cord)[y][x].y
				* matrix[2][1] + (*cord)[y][x].z * matrix[2][2];
			(*cord)[y][x].x = x_new;
			(*cord)[y][x].y = y_new;
			(*cord)[y][x].z = z_new;
		}
	}
}

void	rotate_about_z_axis_2d(t_vars *vars, t_cord ***cord, double angle)
{
	double	matrix[3][3];

	matrix[0][0] = cos(RADIAN(angle));
	matrix[0][1] = -sin(RADIAN(angle));
	matrix[0][2] = 0;
	matrix[1][0] = sin(RADIAN(angle));
	matrix[1][1] = cos(RADIAN(angle));
	matrix[1][2] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 1;
	multiply_matrix_to_grid(vars, cord, matrix);
}

// PRINT OUT GRID
// printf("\n ----Rotation----\n");
// printf("\nAFTER matrix multiplication ~~\n");
// print_grid(vars, vars->cord);
void	rotate_about_x_axis(t_vars *vars, t_cord ***cord, double angle)
{
	double	matrix[3][3];

	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = cos(RADIAN(angle));
	matrix[1][2] = -sin(RADIAN(angle));
	matrix[2][0] = 0;
	matrix[2][1] = sin(RADIAN(angle));
	matrix[2][2] = cos(RADIAN(angle));
	multiply_matrix_to_grid(vars, cord, matrix);
}

// printf("\n ----Rotation about x-axis----\n");
// PRINT OUT GRID
// printf("\nAFTER matrix multiplication ~~\n");
// print_grid(vars, vars->cord);
void	rotate_about_y_axis(t_vars *vars, t_cord ***cord, double angle)
{
	double	matrix[3][3];

	matrix[0][0] = cos(RADIAN(angle));
	matrix[0][1] = 0;
	matrix[0][2] = sin(RADIAN(angle));
	matrix[1][0] = 0;
	matrix[1][1] = 1;
	matrix[1][2] = 0;
	matrix[2][0] = -sin(RADIAN(angle));
	matrix[2][1] = 0;
	matrix[2][2] = cos(RADIAN(angle));
	multiply_matrix_to_grid(vars, cord, matrix);
}

// PRINT OUT GRID
// printf("\n ----Rotation about y-axis----\n");
// printf("\nAFTER matrix multiplication ~~\n");
// print_grid(vars, vars->cord);

// ===========Method 2: Combined all 3 rotation matrices==============
// void multiply_matrices(double result[3][3], double matrix2[3][3])
// {
//     double temp_result[3][3];
//     int i, j, k;
//     double temp;

//     // Initialize temporary result matrix to zeros
//     for (i = 0; i < 3; i++)
// 	{
//         for (j = 0; j < 3; j++) {

//             temp_result[i][j] = 0;
//         }
//     }

//     // Perform matrix multiplication
//     i = 0;
//     while (i < 3)
// 	{
//         j = 0;
//         while (j < 3)
// 		{
//             temp = 0; // Initialize temporary variable to 0
//             k = 0;
//             while (k < 3)
// 			{
//                 temp += result[i][k] * matrix2[k][j];
//                 k++;
//             }
//             temp_result[i][j] = temp;
	// Store the result in the temporary array
//             j++;
//         }
//         i++;
//     }

//     // Copy the temporary result back to the original result matrix
//     i = 0;
//     while (i < 3)
// 	{
//         j = 0;
//         while (j < 3)
// 		{
//             result[i][j] = temp_result[i][j];
//             j++;
//         }
//         i++;
//     }
// }

// void multiply_3_matrices_tgt(double result[3][3], double matrix_1[3][3],
	// double matrix_2[3][3], double matrix_3[3][3])
// {
//     // Initialize the composite matrix with the identity matrix
// 	// int result[3][3];

//     result[0][0] = 1.0;
//     result[0][1] = 0.0;
//     result[0][2] = 0.0;
//     result[1][0] = 0.0;
//     result[1][1] = 1.0;
//     result[1][2] = 0.0;
//     result[2][0] = 0.0;
//     result[2][1] = 0.0;
//     result[2][2] = 1.0;

//    
//     multiply_matrices(result, matrix_1); // Multiply matrix3 first
//     multiply_matrices(result, matrix_2); // Then multiply matrix2
//     multiply_matrices(result, matrix_3); // Finally multiply matrix1
// }

// void rotate_about_all_axis(t_vars *vars, t_cord ***cord, t_angle angle)
// {
// 	double matrix_x[3][3];
// 	double matrix_y[3][3];
// 	double matrix_z[3][3];
// 	double result[3][3];

// 	matrix_x[0][0] = 1;
// 	matrix_x[0][1] = 0;
// 	matrix_x[0][2] = 0;
// 	matrix_x[1][0] = 0;
// 	matrix_x[1][1] = cos(RADIAN(angle.x));
// 	matrix_x[1][2] = -sin(RADIAN(angle.x));
// 	matrix_x[2][0] = 0;
// 	matrix_x[2][1] = sin(RADIAN(angle.x));
// 	matrix_x[2][2] = cos(RADIAN(angle.x));

// 	matrix_y[0][0] = cos(RADIAN(angle.y));
// 	matrix_y[0][1] = 0;
// 	matrix_y[0][2] = sin(RADIAN(angle.y));
// 	matrix_y[1][0] = 0;
// 	matrix_y[1][1] = 1;
// 	matrix_y[1][2] = 0;
// 	matrix_y[2][0] = -sin(RADIAN(angle.y));
// 	matrix_y[2][1] = 0;
// 	matrix_y[2][2] = cos(RADIAN(angle.y));

// 	matrix_z[0][0] = cos(RADIAN(angle.z));
// 	matrix_z[0][1] = -sin(RADIAN(angle.z));
// 	matrix_z[0][2] = 0;
// 	matrix_z[1][0] = sin(RADIAN(angle.z));
// 	matrix_z[1][1] = cos(RADIAN(angle.z));
// 	matrix_z[1][2] = 0;
// 	matrix_z[2][0] = 0;
// 	matrix_z[2][1] = 0;
// 	matrix_z[2][2] = 1;

// 	if (vars->flags.rotate_x == TRUE)
// 		multiply_3_matrices_tgt(result, matrix_x, matrix_y, matrix_z);
// 	else if (vars->flags.rotate_y == TRUE)
// 		multiply_3_matrices_tgt(result, matrix_y, matrix_x, matrix_z);
// 	else if (vars->flags.rotate_z == TRUE)
// 		multiply_3_matrices_tgt(result, matrix_z, matrix_y, matrix_x);
// 	multiply_matrix_to_grid(vars, cord, result);
// }
