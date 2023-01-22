/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:21:00 by yichinos          #+#    #+#             */
/*   Updated: 2023/01/22 12:22:00 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_esc(int keycode, t_fractol *fra)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(fra->mlx_ptr, fra->win_ptr);
		free(fra->mlx_ptr);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	key_hook(int keycode, t_fractol *fra)
{
	mlx_clear_window(fra->mlx_ptr, fra->win_ptr);
	if (keycode == LEFT)
	{
		fra->l_move += 0.1 / fra->zoom;
		draw_fractol(fra);
	}
	else if (keycode == RIGHT)
	{
		fra->l_move -= 0.1 / fra->zoom;
		draw_fractol(fra);
	}
	else if (keycode == DOWN)
	{
		fra->v_move += 0.1 / fra->zoom;
		draw_fractol(fra);
	}
	else if (keycode == UP)
	{
		fra->v_move -= 0.1 / fra->zoom;
		draw_fractol(fra);
	}
	return (0);
}
