/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:05:50 by yichinos          #+#    #+#             */
/*   Updated: 2023/01/16 17:25:56 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	zoom_in(t_fractol *fra)
{
	fra->zoom *= 1.1;
	fra->maxiter += 5;
}

void	zoom_out(t_fractol *fra)
{
	fra->zoom *= 0.9;
	fra->maxiter -= 5;
	if (fra->maxiter <= 100)
		fra->maxiter = 100;
}

int	mouse_hook(int button, int x, int y, t_fractol *fra)
{
	(void) x;
	(void) y;
	if (button == 4)
	{
		zoom_in(fra);
		fractol(fra);
	}
	if (button == 5)
	{
		zoom_out(fra);
		fractol(fra);
	}
	return (0);
}

int	close_button(t_fractol *fra)
{
	mlx_destroy_window(fra->mlx_ptr, fra->win_ptr);
	system("leaks fractol");
	exit(0);
}
