/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:21:00 by yichinos          #+#    #+#             */
/*   Updated: 2023/01/26 16:53:43 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_esc(int keycode, t_fractol *fra)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(fra->mlx_ptr, fra->img.img);
		mlx_destroy_window(fra->mlx_ptr, fra->win_ptr);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	key_hook(int keycode, t_fractol *fra)
{
	if (keycode == LEFT)
	{
		mlx_clear_window(fra->mlx_ptr, fra->win_ptr);
		fra->l_move += 0.1 / fra->zoom;
		draw_fractol(fra);
	}
	else if (keycode == RIGHT)
	{
		mlx_clear_window(fra->mlx_ptr, fra->win_ptr);
		fra->l_move -= 0.1 / fra->zoom;
		draw_fractol(fra);
	}
	else if (keycode == DOWN)
	{
		mlx_clear_window(fra->mlx_ptr, fra->win_ptr);
		fra->v_move += 0.1 / fra->zoom;
		draw_fractol(fra);
	}
	else if (keycode == UP)
	{
		mlx_clear_window(fra->mlx_ptr, fra->win_ptr);
		fra->v_move -= 0.1 / fra->zoom;
		draw_fractol(fra);
	}
	return (0);
}
