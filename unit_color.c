/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:13:39 by yichinos          #+#    #+#             */
/*   Updated: 2023/01/18 16:00:23 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	rainbow(t_fractol *fra, int num)
{
	int	hue;
	int	sat;
	int	val;

	hue = (255 * num / fra->maxiter);
	sat = 255;
	if (num < fra->maxiter)
		val = 255;
	else
		val = 0;
	my_mlx_pixel_put(fra, fra->loopx, fra->loopy, hue * sat * val);
}
