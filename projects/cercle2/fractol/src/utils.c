/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:49:45 by salsoysa          #+#    #+#             */
/*   Updated: 2025/02/19 12:25:08 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

double	scale_pixel(double xy, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * (xy) / (old_max) + new_min);
}

t_compnum	add_comp_values(t_compnum x, t_compnum y, t_fractal *fractol)
{
	t_compnum res;

	res.real = x.real + y.real;
	res.imaginary = x.imaginary + y.imaginary;

	return (res);
}

t_compnum square_comp_values(t_compnum z, t_fractal *fractol)
{
	t_compnum	res;

	if (!ft_strncmp(fractol->name, "burningship", 12))
	{
		res.real = (z.real * z.real) - (z.imaginary * z.imaginary);
		res.imaginary = fabs((z.real * z.imaginary) * 2);
	}
	else
	{
		res.real = (z.real * z.real) - (z.imaginary * z.imaginary);
		res.imaginary = ((z.real * z.imaginary) * 2);
	}
	return (res);
}

