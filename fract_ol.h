/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:18:47 by yichinos          #+#    #+#             */
/*   Updated: 2023/01/16 17:02:33 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_fractol {
	void	*mlx_ptr;
	void	*win_ptr;
	double	x_str;
	double	y_str;
	double	x_fin;
	double	y_fin;
	double	dx;
	double	dy;
	int		loopx;
	int		loopy;
	int		maxiter;
	double	zoom;
	double	left;
	double	l_move;
	double	v_move;
	t_data	img;
}	t_fractol;

# define ZOOM_IN 4
# define ESC 53
# define WIN_WIDTH 640
# define WIN_HEIGHT 640

void	my_mlx_pixel_put(t_fractol *fra, int width, int heigh, int color);
int		close_esc(int keycode, t_fractol *fra);
int		key_hook(int keycode, t_fractol *fra);
int		mouse_hook(int button, int x, int y, t_fractol *fra);
void	start_mendelbro(t_fractol *fra);
int		mandelbro(t_fractol *fra);
void	fractol(t_fractol *fra);
void	color(t_fractol *fra, int num);
void	color2(t_fractol *fra, int num);
int		close_button(t_fractol *fra);
int		ft_strcmp(const char *s1, const char *s2);
void	rainbow(t_fractol *fra, int num);
void	black(t_fractol *fra, int num);



#endif
