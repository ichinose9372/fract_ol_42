/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fractol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:08:43 by yichinos          #+#    #+#             */
/*   Updated: 2023/01/18 16:10:49 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	start_mendelbro(t_fractol *fra)
{
	fra->x_str = -2.0;
	fra->x_fin = 2.0;
	fra->y_str = -2.0;
	fra->y_fin = 2.0;
	fra->zoom = 100;
	fra->maxiter = 80;
	fra->l_move = 1.0;
	fra->v_move = 0;
}

void	start_julia(t_fractol *fra)
{
	fra->x_str = -2.0;
	fra->x_fin = 2.0;
	fra->y_str = -2.0;
	fra->y_fin = 2.0;
	fra->zoom = 10;
	fra->maxiter = 80;
	fra->l_move = 0;
	fra->v_move = 0;
}

void	set_fractol(t_fractol *fra)
{
	if (fra->type == 1)
		start_mendelbro(fra);
	else if (fra->type == 2)
		start_julia(fra);
}
