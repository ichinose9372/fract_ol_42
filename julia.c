/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:26:33 by yichinos          #+#    #+#             */
/*   Updated: 2023/01/18 16:25:53 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	julia_set(t_fractol *fra, char *argv)
{
	if (*argv == '1')
	{
		fra->dx = -0.3;
		fra->dy = -0.63;
	}
	else if (*argv == '2')
	{
		fra->dy = -0.2;
		fra->dy = -0.8;
	}
	else if (*argv == '3')
	{
		fra->dx = -0.8;
		fra->dy = -0.2;
	}
}

int	julia(t_fractol	*fra)
{
	double	c_re;
	double	c_im;
	double	tmp_re;
	double	tmp_im;
	int		count;

	c_re = (fra->loopx - WIN_WIDTH / fra->x_fin)
		/ (WIN_WIDTH / fra->x_fin - fra-> x_str + fra->zoom) - fra->l_move;
	c_im = (fra->loopy - WIN_HEIGHT / fra->y_fin)
		/ (WIN_HEIGHT / fra->y_fin - fra-> y_str + fra->zoom) - fra->v_move;
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
	return (0);
}
