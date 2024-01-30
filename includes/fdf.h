/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:25:04 by sting             #+#    #+#             */
/*   Updated: 2024/01/30 14:19:13 by sting            ###   ########.fr       */
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
typedef struct	s_img {
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_vars
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}			t_vars;

// x & y : starting coordinates
typedef struct s_rect
{
    int	x;
    int	y;
    int width;
    int height;
    int color;
}	t_rect;

void	render_background(t_img *img, int color);
// Initialise all elements in struct!
int	render(t_vars *vars);

void	img_pix_put(t_img *img, int x, int y, int color);
int close_window(int keycode, void *params);


#endif
