/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:01:09 by yichinos          #+#    #+#             */
/*   Updated: 2023/01/30 12:36:01 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_exit(t_fractol *fra)
{
	mlx_destroy_image(fra->mlx_ptr, fra->img.img);
	mlx_destroy_window(fra->mlx_ptr, fra->win_ptr);
	exit(EXIT_SUCCESS);
}

void	ft_error(void)
{
	write(1, "Usage: ./fractol <Fractals>\n", 28);
	write(1, "Available <Fractals>:\n", 23);
	write(1, "---> mandelbrot\n", 17);
	write(1, "---> julia [num] [num]\n", 24);
	write(1, "num > - 2.0 and num < 2.0\n", 26);
	exit(EXIT_FAILURE);
}
