/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:54:27 by yichinos          #+#    #+#             */
/*   Updated: 2023/01/20 14:04:30 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbro(t_fractol	*fra)
{
	double	c_re;
	double	c_im;
	double	tmp_re;
	double	tmp_im;
	int		count;

	c_re = 0;
	c_im = 0;
	fra->dx = (fra->loopx - WIN_WIDTH / fra->x_fin)
		/ (WIN_WIDTH * fra->zoom) - fra->l_move;
	fra->dy = (fra->loopy - WIN_HEIGHT / fra->y_fin)
		/ (WIN_HEIGHT * fra->zoom) - fra->v_move;
	count = 0;
	while (count < fra->maxiter)
	{
		tmp_re = c_re * c_re - c_im * c_im + fra->dx;
		tmp_im = 2 * c_re * c_im + fra->dy;
		c_re = tmp_re;
		c_im = tmp_im;
		if (c_re * c_re + c_im * c_im > 4)
			return (count);
		count++;
	}
	return (count);
}
