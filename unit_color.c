/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:13:39 by yichinos          #+#    #+#             */
/*   Updated: 2023/01/15 14:54:49 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	color(t_fractol *fra, int num)
{
	if (num <= 5)
		my_mlx_pixel_put(fra, fra->loopx, fra->loopy, 0x000e0000);
	else if (num <= 10)
		my_mlx_pixel_put(fra, fra->loopx, fra->loopy, 0x001c0000);
	else if (num <= 15)
		my_mlx_pixel_put(fra, fra->loopx, fra->loopy, 0x002a0000);
	else if (num <= 20)
		my_mlx_pixel_put(fra, fra->loopx, fra->loopy, 0x00460000);
	else if (num <= 25)
		my_mlx_pixel_put(fra, fra->loopx, fra->loopy, 0x00610000);
	else if (num <= 30)
		my_mlx_pixel_put(fra, fra->loopx, fra->loopy, 0x007d0000);
	else if (num <= 35)
		my_mlx_pixel_put(fra, fra->loopx, fra->loopy, 0x008b0000);
	else if (num <= 40)
		my_mlx_pixel_put(fra, fra->loopx, fra->loopy, 0x00ff0000);
	else
		color2(fra, num);
}

void	color2(t_fractol *fra, int num)
{
	if (num <= 45)
		my_mlx_pixel_put(fra, fra->loopx, fra->loopy, 0x00df2c14);
	else if (num <= 50)
		my_mlx_pixel_put(fra, fra->loopx, fra->loopy, 0x00ed3419);
	else if (num <= 55)
		my_mlx_pixel_put(fra, fra->loopx, fra->loopy, 0x00fb3b1e);
	else if (num <= 60)
		my_mlx_pixel_put(fra, fra->loopx, fra->loopy, 0x00ff4122);
	else if (num <= 65)
		my_mlx_pixel_put(fra, fra->loopx, fra->loopy, 0x00ff6242);
	else if (num <= 70)
		my_mlx_pixel_put(fra, fra->loopx, fra->loopy, 0x00ff8164);
	else if (num <= 75)
		my_mlx_pixel_put(fra, fra->loopx, fra->loopy, 0x00ffa590);
	else
		my_mlx_pixel_put(fra, fra->loopx, fra->loopy, 0x00ffc9bb);
}

void hsv(t_fractol *fra, int num)
{
	my_mlx_pixel_put(fra, fra->loopx, fra->loopy, num * fra->loopx * fra->loopy);
}
