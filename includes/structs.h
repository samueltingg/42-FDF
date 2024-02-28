/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:02:32 by sting             #+#    #+#             */
/*   Updated: 2024/02/28 16:36:11 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_cord
{
	double	x;
	double	y;
	double	z;
	int		color;
}			t_cord;

/**
 * @param line_len amount of bytes taken by one row of our image
 * @param img_ptr pointer to the image structure created by mlx_new_image
 * @param addr pointer to the raw pixel data of the image
 */
typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_flag
{
	int iso;
	int done_once;
}				t_flag;

/*
Elements:
	- void	*mlx_ptr;
	- void	*win_ptr;
	- t_img	img;
	- t_cord	**cord;
	- int		line_count;
	- int		wc;
*/
typedef struct s_vars
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	// PARSING
	t_cord	**cord; // coordinates here will be updated for each transformation
    t_cord  **cord_ori; // original copy of coordinates | grid center translated to frame origin(0,0)
	int		line_count;
	int		wc;
	int		gap;
	int		offset_x;
	int		offset_y;

	// to keep track of rotated angle about each axis
	double	angle_x_axis;
	double 	angle_y_axis;
	double  angle_z_axis;
	t_flag flags;
}			t_vars;

// x & y : starting coordinates
// typedef struct s_rect
// {
// 	int		x;
// 	int		y;
// 	int		width;
// 	int		height;
// 	int		color;
// }			t_rect;

/*
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		color;
*/
typedef struct s_line_cord
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		color;
}			t_line_cord;

typedef struct s_line_var
{
	int		dx;
	int		dy;
	int		D;
	int		x;
	int		y;
	int		xi;
	int		yi;
}			t_line_var;

/*
	int a;
	int b;
	int c;
*/
typedef struct s_matrix
{
	double	a;
	double	b;
	double	c;
}			t_matrix;

#endif
