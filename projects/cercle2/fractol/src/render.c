/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:42:39 by salsoysa          #+#    #+#             */
/*   Updated: 2025/02/27 17:14:23 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

static void	fractal_coord(t_compnum *z, t_compnum *c, t_fractal *fractol)
{
	if (fractol->name == 1)
	{
		c->real = fractol->jx;
		c->imaginary = fractol->jy;
	}
	else
	{
		c->real = z->real;
		c->imaginary = z->imaginary;
	}
}

static void	my_pp(int x, int y, t_img *img, int color)
{
	int	offs;

	offs = (y * img->line_s) + (x * (img->bpp / 8));
	*(unsigned int *)(img->ptpix + offs) = color;
}

static void	pixel_check(int x, int y, t_fractal *fractol)
{
	t_compnum	z;
	t_compnum	c;
	int			i;
	int			color;

	i = 0;
	z.real = (scale_pixel(x, -2, 2, WIDTH) * fractol->zoom) + fractol->sx;
	z.imaginary = (scale_pixel(y, -2, 2, HEIGHT) * fractol->zoom)
		+ fractol->sy;
	color = 0x660066FF;
	fractal_coord(&z, &c, fractol);
	while (i < fractol->max_iteration)
	{
		z = add_comp_values(square_comp_values(z, fractol), c, fractol);
		if ((z.real * z.real) + (z.imaginary * z.imaginary) > fractol->esc_val)
		{
			color = scale_pixel(i, BLACK, BLUE, fractol->max_iteration);
			my_pp(x, y, &fractol->img, color);
			return ;
		}
		i++;
	}
	my_pp(x, y, &fractol->img, CYAN);
}

void	f_render(t_fractal *fractol)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			pixel_check(x, y, fractol);
	}
	mlx_put_image_to_window(fractol->mlx_start, fractol->mlx_window,
		fractol->img.img_ptr, 0, 0);
}
