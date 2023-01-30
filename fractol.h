/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:18:47 by yichinos          #+#    #+#             */
/*   Updated: 2023/01/30 13:51:29 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <unistd.h>
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
	int		color;
	double	l_move;
	double	v_move;
	int		type;
	t_data	img;
}	t_fractol;

# define WIN_WIDTH 640
# define WIN_HEIGHT 640
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
# define ESC 53
# define ZOOM_OUT 5
# define ZOOM_IN 4

void	my_mlx_pixel_put(t_fractol *fra, int width, int heigh, int color);
int		close_esc(int keycode, t_fractol *fra);
int		key_hook(int keycode, t_fractol *fra);
int		mouse_hook(int button, int x, int y, t_fractol *fra);
void	start_mendelbro(t_fractol *fra);
int		mandelbro(t_fractol *fra);
void	draw_fractol(t_fractol *fra);
int		close_button(t_fractol *fra);
int		ft_strcmp(const char *s1, const char *s2);
void	pixel_put_color(t_fractol *fra, int num);
int		ft_strlen(char	*str);
int		julia(t_fractol	*fra);
void	start_julia(t_fractol *fra);
void	set_fractol(t_fractol *fra);
void	init_fractol(t_fractol *fra);
void	ft_error(void);
void	check_input(int argc, char **argv, t_fractol *fra);
double	ft_get_num(const char *str, double *decimal);
double	ft_atof(const char *str);
int		ft_isspace(char c);
void	ft_exit(t_fractol *fra);

#endif
