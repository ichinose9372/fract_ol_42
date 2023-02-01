/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:23:28 by yichinos          #+#    #+#             */
/*   Updated: 2023/01/22 12:23:16 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractol(t_fractol *fra)
{
	int		num;

	fra->loopy = 0;
	while (fra->loopy < WIN_WIDTH)
	{
		fra->loopx = 0;
		while (fra->loopx < WIN_HEIGHT)
		{
			if (fra->type == 0)
				num = mandelbro(fra);
			else
				num = julia(fra);
			pixel_put_color(fra, num);
			fra->loopx++;
		}
		fra->loopy++;
	}
	mlx_put_image_to_window(fra->mlx_ptr, fra->win_ptr, fra->img.img, 0, 0);
}
