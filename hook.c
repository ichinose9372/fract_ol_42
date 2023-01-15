/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:05:50 by yichinos          #+#    #+#             */
/*   Updated: 2023/01/15 19:22:41 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	key_hook(int keycode, t_fractol *fra)
{
	mlx_clear_window(fra->mlx_ptr, fra->win_ptr);
	if (keycode == 123)
	{
		fra->l_move += 0.05;
		fractol(fra);
	}
	else if (keycode == 124)
	{
		fra->l_move -= 0.05;
		fractol(fra);
	}
	else if (keycode == 125)
	{
		fra->v_move += 0.05;
		fractol(fra);
	}
	else if (keycode == 126)
	{
		fra->v_move -= 0.05;
		fractol(fra);
	}
	return (0);
}

void	zoom_in(t_fractol *fra)
{
	fra->zoom *= 1.2;
	fra->maxiter += 10;
}

void	zoom_out(t_fractol *fra)
{
	fra->zoom *= 0.8;
	fra->maxiter -= 4;
}

int	mouse_hook(int button, int x, int y, t_fractol *fra)
{
	if (button == 4)
	{
		mlx_clear_window(fra->mlx_ptr, fra->win_ptr);
		zoom_in(fra);
		fractol(fra);
	}
	if (button == 5)
	{
		mlx_clear_window(fra->mlx_ptr, fra->win_ptr);
		fractol(fra);
	}
	return (0);
}

int	close_esc(int keycode, t_fractol *fra)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(fra->mlx_ptr, fra->win_ptr);
		system("leaks a.out");
		exit(0);
	}
	return (0);
}

int	close_button(t_fractol *fra)
{
	mlx_destroy_window(fra->mlx_ptr, fra->win_ptr);
	system("leaks a.out");
	exit(0);
}
