/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:27:56 by yichinos          #+#    #+#             */
/*   Updated: 2023/01/12 18:16:55 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	my_mlx_pixel_put(t_fractol *fra, int x, int y, int color)
{
	char	*dst;

	dst = fra->img.addr + (y * fra->img.line_length + x * (fra->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	close(int keycode, t_fractol *fra)
{
	if (keycode == ESC)
		mlx_destroy_window(fra->mlx_ptr, fra->win_ptr);
	return (0);
}

int	key_hook(int keycode, t_fractol *fra)
{
	printf("key -> %d\n", keycode);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractol *fra)
{
	if (button == 5)
	{
		mlx_clear_window(fra->mlx_ptr, fra->win_ptr);
		fra->zoom -= ;
		fractol(fra);
	}
	if (button == 4)
	{
		mlx_clear_window(fra->mlx_ptr, fra->win_ptr);
		fra->zoom += 8.0;
		fractol(fra);
	}
	return (0);
}
