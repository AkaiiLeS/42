/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:49:45 by salsoysa          #+#    #+#             */
/*   Updated: 2025/02/27 17:05:41 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

double	scale_pixel(double xy, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * (xy) / (old_max) + new_min);
}

t_compnum	add_comp_values(t_compnum x, t_compnum y, t_fractal *fractol)
{
	t_compnum	res;

	if (fractol->name == 3)
	{
		res.real = x.real + y.real;
		res.imaginary = x.imaginary + y.imaginary;
	}
	else
	{
		res.real = x.real + y.real;
		res.imaginary = x.imaginary + y.imaginary;
	}
	return (res);
}

t_compnum	square_comp_values(t_compnum z, t_fractal *fractol)
{
	t_compnum	res;

	if (fractol->name == 3)
	{
		res.real = (z.real * z.real) - (z.imaginary * z.imaginary);
		res.imaginary = fabs((z.real * z.imaginary * 2));
	}
	else
	{
		res.real = (z.real * z.real) - (z.imaginary * z.imaginary);
		res.imaginary = ((z.real * z.imaginary) * 2);
	}
	return (res);
}

double	atod(char *str)
{
	int		i;
	double	nb;
	int		is_neg;
	double	div;

	nb = 0;
	div = 0.1;
	is_neg = 1;
	i = skip_space_sign(str, &is_neg);
	while (str[i] && ft_isdigit(str[i]) && str[i] != '.')
	{
		nb = (nb * 10.0) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		nb = nb + ((str[i] - '0') * div);
		div *= 0.1;
		i++;
	}
	if (str[i] && !ft_isdigit(str[i]))
		return (-42);
	return (nb * is_neg);
}
