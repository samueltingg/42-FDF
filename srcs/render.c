/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:43:32 by sting             #+#    #+#             */
/*   Updated: 2024/01/30 13:51:22 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/fdf.h"

void	render_background(t_img *img, int color)
{
    int	i;
    int	j;

    i = 0;
    while (i < WINDOW_HEIGHT)
    {
        j = 0;
        while (j < WINDOW_WIDTH)
            img_pix_put(img, j++, i, color);
        ++i;
    }
}

int render_rect(t_img *img, t_rect rect)
{
    int	i;
    int j;

    i = rect.y;
    while (i < rect.y + rect.height)
    {
        j = rect.x;
        while (j < rect.x + rect.width)
            img_pix_put(img, j++, i, rect.color);
        i++;
    }
    return (0);
}

int render_hollow_rect(t_img *img, t_rect rect)
{
    
    return (0);
}

int	render(t_vars *vars)
{
	if (vars->win_ptr == NULL)
		return (1);
	render_background(&vars->img, 0x0);
	render_rect(&vars->img, (t_rect){0, 0, 300, 300, RED_PIXEL});
	render_rect(&vars->img, (t_rect){WINDOW_WIDTH - 300, WINDOW_HEIGHT - 300, 300, 300, GREEN_PIXEL});

	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img.img_ptr, 0, 0);

    return (0);
}