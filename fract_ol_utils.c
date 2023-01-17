/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:27:56 by yichinos          #+#    #+#             */
/*   Updated: 2023/01/17 12:54:43 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	my_mlx_pixel_put(t_fractol *fra, int x, int y, int color)
{
	char	*dst;

	dst = fra->img.addr + (y * fra->img.line_length + x
			* (fra->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (1)
	{
		if (*s1 == '\0' || *s2 == '\0')
			return ((unsigned char)*s1 - (unsigned char)*s2);
		if (*s1 != *s2 || *s1 + 32 != *s2 + 32)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
}

int	ft_strlen(char	*str)
{
	int	count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}
