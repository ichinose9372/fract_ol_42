/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:21:00 by yichinos          #+#    #+#             */
/*   Updated: 2023/01/18 15:27:41 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	close_esc(int keycode, t_fractol *fra)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(fra->mlx_ptr, fra->win_ptr);
		exit(0);
	}
	return (0);
}

int	key_hook(int keycode, t_fractol *fra)
{
	mlx_clear_window(fra->mlx_ptr, fra->win_ptr);
	if (keycode == 123)
	{
		fra->l_move += 0.2 / fra->zoom;
		fractol(fra);
	}
	else if (keycode == 124)
	{
		fra->l_move -= 0.2 / fra->zoom;
		fractol(fra);
	}
	else if (keycode == 125)
	{
		fra->v_move += 0.2 / fra->zoom;
		fractol(fra);
	}
	else if (keycode == 126)
	{
		fra->v_move -= 0.2 / fra->zoom;
		fractol(fra);
	}
	return (0);
}
