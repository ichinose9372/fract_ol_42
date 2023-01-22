/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:13:39 by yichinos          #+#    #+#             */
/*   Updated: 2023/01/22 18:52:24 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_fractol *fra, int x, int y, int color)
{
	char	*dst;

	dst = fra->img.addr + (y * fra->img.line_length + x
			* (fra->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	pixel_put_color(t_fractol *fra, int num)
{
	int	color;

	color = 0;
	if (num == fra->maxiter)
		color = 0x00000000;
	else if (num % 8 == 7)
		color = 0x888888;
	else if (num % 8 == 6)
		color = 0x777777;
	else if (num % 8 == 5)
		color = 0x666666;
	else if (num % 8 == 4)
		color = 0x555555;
	else if (num % 8 == 3)
		color = 0x444444;
	else if (num % 8 == 2)
		color = 0x333333;
	else if (num % 8 == 1)
		color = 0x222222;
	else
		color = 0x111111;
	my_mlx_pixel_put(fra, fra->loopx, fra->loopy, color);
}
