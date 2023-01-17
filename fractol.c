/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:23:28 by yichinos          #+#    #+#             */
/*   Updated: 2023/01/17 12:06:12 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	fractol(t_fractol *fra)
{
	int		num;

	fra->loopy = 0;
	while (fra->loopy < WIN_WIDTH)
	{
		fra->loopx = 0;
		while (fra->loopx < WIN_HEIGHT)
		{
			if (fra->type == 1)
				num = mandelbro(fra);
			else if (fra->type == 2)
				num = julia(fra);
			if (num == 0)
				my_mlx_pixel_put(fra, fra->loopx, fra->loopy, 0x000000);
			else
				black(fra, num);
			fra->loopx++;
		}
		fra->loopy++;
	}
	mlx_put_image_to_window(fra->mlx_ptr, fra->win_ptr, fra->img.img, 0, 0);
}
