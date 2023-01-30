/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fractol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:08:43 by yichinos          #+#    #+#             */
/*   Updated: 2023/01/29 13:58:37 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	start_mendelbro(t_fractol *fra)
{
	fra->x_str = -2.0;
	fra->x_fin = 2.0;
	fra->y_str = -2.0;
	fra->y_fin = 2.0;
	fra->zoom = 0.4;
	fra->maxiter = 80;
	fra->l_move = 0.75;
	fra->v_move = 0;
}

void	start_julia(t_fractol *fra)
{
	fra->x_str = -2.0;
	fra->x_fin = 2.0;
	fra->y_str = -2.0;
	fra->y_fin = 2.0;
	fra->zoom = 0.25;
	fra->maxiter = 80;
	fra->l_move = 0;
	fra->v_move = 0;
}

void	set_fractol(t_fractol *fra)
{
	if (fra->type == 0)
		start_mendelbro(fra);
	else
		start_julia(fra);
}
