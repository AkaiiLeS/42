/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:42:39 by salsoysa          #+#    #+#             */
/*   Updated: 2025/01/31 20:07:59 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	pixel_check(int x, int y, t_fractal *fractol)
{
	t_compnum	z;
	t_compnum	c;
	int	i;

	z.real = 0.0;
	z.imaginary = 0.0;

	c.real = scale_pixel(x, -2, +2, WIDTH);
	c.imaginary = scale_pixel(y, +2, -2, HEIGHT);

	while(i < fractol->max_iteration)
}
