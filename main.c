/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:17:28 by yichinos          #+#    #+#             */
/*   Updated: 2023/01/18 16:27:36 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	start(t_fractol *fra)
{
	fra->mlx_ptr = mlx_init();
	if (fra->mlx_ptr == NULL)
		exit(1);
	fra->win_ptr = mlx_new_window(fra->mlx_ptr, 640, 640, "fracto_ol");
	if (fra->win_ptr == NULL)
		exit(1);
	fra->img.img = mlx_new_image(fra->mlx_ptr, 640, 640);
	if (fra->img.img == NULL)
		exit(1);
	fra->img.addr = mlx_get_data_addr(fra->img.img,
			&fra->img.bits_per_pixel, &fra->img.line_length,
			&fra->img.endian);
}

int	check_input(int argc, char **argv, t_fractol *fra)
{
	if (argc < 2)
	{
		write(1, "ERROR!\n", ft_strlen("ERROR!\n"));
		write(1, "Please select--", ft_strlen("Please select--"));
		write(1, "----mandelbrot\n", ft_strlen("----mandelbrot\n"));
		write(1, "              |----julia\n",
			ft_strlen("              |----julia\n"));
		exit(1);
	}
	else if (argc > 3)
		exit(1);
	else
	{
		if (!ft_strcmp("mandelbrot", argv[1]))
			fra->type = 1;
		else if ((!ft_strcmp("julia", argv[1])) && argc == 3)
		{
			fra->type = 2;
			julia_set(fra, argv[2]);
		}
		else
		{
			write(1, "missing type!\n", ft_strlen("missing type!\n"));
			exit(1);
		}
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_fractol	fra;

	start(&fra);
	check_input(argc, argv, &fra);
	set_fractol(&fra);
	fractol(&fra);
	mlx_mouse_hook(fra.win_ptr, &mouse_hook, &fra);
	mlx_key_hook(fra.win_ptr, &key_hook, &fra);
	mlx_hook(fra.win_ptr, 17, 1L << 3, close_button, &fra);
	mlx_hook(fra.win_ptr, 2, 1L << 0, close_esc, &fra);
	mlx_loop(fra.mlx_ptr);
	return (0);
}
