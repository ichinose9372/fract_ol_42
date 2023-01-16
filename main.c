/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:17:28 by yichinos          #+#    #+#             */
/*   Updated: 2023/01/16 11:51:49 by yichinos         ###   ########.fr       */
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

int	check_input(int argc, char **argv, t_fractol *fra)
{
	if (argc < 2)
		return (0);
	else if (argc > 3)
		return (0);
	else
	{
		start(fra);
		if (!ft_strcmp("mandelbro", argv[1]))
		{
			start_mendelbro(fra);
			fractol(fra);
		}
		else
			return (0);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_fractol	fra;

	check_input(argc, argv, &fra);
	mlx_mouse_hook(fra.win_ptr, &mouse_hook, &fra);
	mlx_key_hook(fra.win_ptr, &key_hook, &fra);
	mlx_hook(fra.win_ptr, 17, 1L << 3, close_button, &fra);
	mlx_hook(fra.win_ptr, 2, 1L << 0, close_esc, &fra);
	mlx_loop(fra.mlx_ptr);
	return (0);
}
