/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:27:56 by yichinos          #+#    #+#             */
/*   Updated: 2023/01/24 12:16:49 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return ((unsigned int)*s1 - (unsigned int)*s2);
		s1++;
		s2++;
	}
	return (0);
}

int	ft_isdigit(char c)
{
	if ('0' <= c && c <= '9')
	{
		return (1);
	}
	return (0);
}

int	ft_isspace(char c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

double	ft_get_num(const char *str, double *dot)
{
	double	result;

	result = 0;
	while (*str != '\0' && *str != '.')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		while (*str != '\0')
		{
			result = result * 10 + (*str - '0');
			*dot = *dot * 10;
			str++;
			if (!('0' <= *str && *str <= '9') && *str != '\0')
				break ;
		}
	}
	return (result);
}

double	ft_atof(const char *str)
{
	double	result;
	double	dot;
	int		sign;

	result = 0;
	dot = 1;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (!(ft_isdigit(*str)))
		ft_error();
	result = ft_get_num(str, &dot);
	if (result / dot * sign > 2.0 || result / dot * sign < -2.0)
		ft_error();
	return (result / dot * sign);
}
