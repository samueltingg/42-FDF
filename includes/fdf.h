/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:25:04 by sting             #+#    #+#             */
/*   Updated: 2024/02/13 17:09:45 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include ".././libft/libft.h"
# include "macros.h"
# include "mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// ^can also use <mlx.h>, but only in 42 macs

typedef struct s_cord
{
	int		x;
	int		y;
	int		z;
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
	t_cord	**cord;
	int		line_count;
	int		wc;
	
	int		gap;
}			t_vars;

// x & y : starting coordinates
typedef struct s_rect
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		color;
}			t_rect;

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
	int a;
	int b;
	int c;
}			t_matrix;

// PARSING
int			ft_atoi_base(char *str, char *base);
int			get_line_count(char *input);
void		parsing(char *input, t_vars *vars);
void		free_cord(t_vars *vars);

void		img_pix_put(t_img *img, int x, int y, int color);
int			close_window(int keycode, void *params);

// RENDERING
// covers previous frame with black (reset)
void		render_background(t_img *img, int color);
int			render(void *param);
// Initialise all elements in struct!

// BRESENHAM'S LINE ALGO
void		render_line_bresenham(t_img *img, t_line_cord cord);
void		render_line_low(t_img *img, t_line_cord line);
/*
- For steep slope
- gradient > 1 OR gradient < -1
*/
void		render_line_high(t_img *img, t_line_cord line);

// MATRIX MULTIPLICATION
void multiply_matrix(t_vars *vars, t_matrix row1, t_matrix row2, t_matrix row3);

// TRANSFORMATION
int rotate(int keycode, t_vars *vars);

#endif
