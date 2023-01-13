/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:54:27 by yichinos          #+#    #+#             */
/*   Updated: 2023/01/13 13:12:21 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	start_mendelbro(t_fractol *fra)
{
	fra->x_str = -2.0;
	fra->x_fin = 2.0;
	fra->y_str = -2.0;
	fra->y_fin = 2.0;
	fra->maxiter = 80;
	fra->color = 0;
	fra->zoom = 0;
	fra->left = 1.0;
}

int mandelbro(t_fractol	*fra)
{
	double	c_re;
	double	c_im;
	double	tmp_re;
	double	tmp_im;
	int		count;

	c_re = 0;
	c_im = 0;
	fra->dx = (fra->loopx - WIN_WIDTH / fra->x_fin) / (WIN_WIDTH / fra->x_fin - fra-> x_str + fra->zoom) - 1.0;
	fra->dy = (fra->loopy - WIN_HEIGHT / fra->y_fin) / (WIN_HEIGHT / fra->y_fin - fra-> y_str + fra->zoom);
	count = 0;
	while (count < fra->maxiter)
	{
		tmp_re = c_re * c_re - c_im * c_im + fra->dx;
		tmp_im = 2 * c_re * c_im + fra->dy;
		c_re = tmp_re;
		c_im = tmp_im;
		if (c_re * c_re + c_im * c_im >= 8)
			return (count);
		count++;
	}
	return (0);
}

void	fractol(t_fractol *fra)
{
	int	num;

	fra->loopy = 0;
	while (fra->loopy < WIN_WIDTH)
	{
		fra->loopx = 0;
		while (fra->loopx < WIN_HEIGHT)
		{
			num = mandelbro(fra);
			if (num == 0)
				my_mlx_pixel_put(fra, fra->loopx, fra->loopy, 0xFFFFFFF); // 中の色
			else
				my_mlx_pixel_put(fra, fra->loopx, fra->loopy, 0x00005BC9); //外の色
			fra->loopx++;
		}
		fra->loopy++;
	}
	mlx_put_image_to_window(fra->mlx_ptr, fra->win_ptr, fra->img.img, 0, 0);
}
