/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:17:28 by yichinos          #+#    #+#             */
/*   Updated: 2023/01/30 13:56:43 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	init_fractol(t_fractol *fra)
{
	fra->mlx_ptr = mlx_init();
	if (fra->mlx_ptr == NULL)
		exit(EXIT_FAILURE);
	fra->win_ptr = mlx_new_window(fra->mlx_ptr, 640, 640, "fract_ol");
	if (fra->win_ptr == NULL)
	{
		free(fra->mlx_ptr);
		exit(EXIT_FAILURE);
	}
	fra->img.img = mlx_new_image(fra->mlx_ptr, 640, 640);
	if (fra->img.img == NULL)
	{
		mlx_destroy_window(fra->mlx_ptr, fra->win_ptr);
		free(fra->mlx_ptr);
		exit(EXIT_FAILURE);
	}
	fra->img.addr = mlx_get_data_addr(fra->img.img,
			&fra->img.bits_per_pixel, &fra->img.line_length,
			&fra->img.endian);
}

void	check_input(int argc, char **argv, t_fractol *fra)
{
	if (argc < 2 || argc > 4)
		ft_error();
	if (!ft_strcmp("mandelbrot", argv[1]) && !argv[2])
		fra->type = 0;
	else if (!ft_strcmp("julia", argv[1]) && argv[2] && argv[3])
	{
		fra->type = 1;
		fra->dx = ft_atof(argv[2]);
		fra->dy = ft_atof(argv[3]);
	}
	else
		ft_error();
}

int	main(int argc, char **argv)
{
	t_fractol	fra;

	init_fractol(&fra);
	check_input(argc, argv, &fra);
	set_fractol(&fra);
	draw_fractol(&fra);
	mlx_mouse_hook(fra.win_ptr, &mouse_hook, &fra);
	mlx_key_hook(fra.win_ptr, &key_hook, &fra);
	mlx_hook(fra.win_ptr, 17, 1L << 3, close_button, &fra);
	mlx_hook(fra.win_ptr, 2, 1L << 0, close_esc, &fra);
	mlx_loop(fra.mlx_ptr);
	return (0);
}

// __attribute__((destructor)) static void destructor()
// {
//     system("leaks -q fractol");
// }
