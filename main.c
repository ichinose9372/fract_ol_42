/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:17:28 by yichinos          #+#    #+#             */
/*   Updated: 2023/01/13 16:48:56 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	start(t_fractol *fra)
{
	fra->mlx_ptr = mlx_init();
	fra->win_ptr = mlx_new_window(fra->mlx_ptr, 640, 640, "Mandelbro");
	fra->img.img = mlx_new_image(fra->mlx_ptr, 640, 640);
	fra->img.addr = mlx_get_data_addr(fra->img.img,
			&fra->img.bits_per_pixel, &fra->img.line_length,
			&fra->img.endian);
}

int	main(void)
{
	t_fractol	fra;

	start(&fra);
	start_mendelbro(&fra);
	fractol(&fra);
	mlx_mouse_hook(fra.win_ptr, &mouse_hook, &fra);
	mlx_key_hook(fra.win_ptr, &key_hook, &fra);
	mlx_hook(fra.win_ptr, 33, 1L << 17, close, &fra);
	mlx_hook(fra.win_ptr, 2, 1L << 0, close, &fra);
	mlx_loop(fra.mlx_ptr);
	return (0);
}
