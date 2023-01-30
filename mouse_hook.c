/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:05:50 by yichinos          #+#    #+#             */
/*   Updated: 2023/01/29 14:09:16 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int button, int x, int y, t_fractol *fra)
{
	(void) x;
	(void) y;
	if (button == ZOOM_IN)
	{
		mlx_clear_window(fra->mlx_ptr, fra->win_ptr);
		fra->zoom *= 1.1;
		fra->maxiter += 4;
		draw_fractol(fra);
	}
	if (button == ZOOM_OUT)
	{
		mlx_clear_window(fra->mlx_ptr, fra->win_ptr);
		fra->zoom *= 0.9;
		fra->maxiter -= 4;
		if (fra->maxiter <= 80)
			fra->maxiter = 80;
		draw_fractol(fra);
	}
	return (0);
}

int	close_button(t_fractol *fra)
{
	ft_exit(fra);
	return (0);
}
