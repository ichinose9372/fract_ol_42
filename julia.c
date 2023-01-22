/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:26:33 by yichinos          #+#    #+#             */
/*   Updated: 2023/01/22 15:59:21 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_fractol	*fra)
{
	double	c_re;
	double	c_im;
	double	tmp_re;
	double	tmp_im;
	int		count;

	c_re = (fra->loopx - WIN_WIDTH / fra->x_fin)
		/ (WIN_WIDTH * fra->zoom) - fra->l_move;
	c_im = (fra->loopy - WIN_HEIGHT / fra->y_fin)
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
