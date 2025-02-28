/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:54:54 by salsoysa          #+#    #+#             */
/*   Updated: 2025/02/27 16:12:15 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"
#include "../minilibx-linux/mlx.h"
#include <X11/X.h>

static void	call_events(t_fractal *fractol)
{
	mlx_hook(fractol->mlx_window, KeyPress, KeyPressMask, key_press, fractol);
	mlx_hook(fractol->mlx_window, DestroyNotify, StructureNotifyMask,
		clean_close, fractol);
	mlx_hook(fractol->mlx_window, ButtonPress, ButtonPressMask, mouse_press,
		fractol);
}

void	init_data(t_fractal *fractol)
{
	fractol->esc_val = 4;
	fractol->max_iteration = 60;
	fractol->sx = 0.0;
	fractol->sy = 0.0;
	fractol->zoom = 1.5;
}

void	init_f(t_fractal *fractol)
{
	fractol->mlx_start = mlx_init();
	if (fractol->mlx_start == NULL)
		mlx_failure();
	fractol->mlx_window = mlx_new_window(fractol->mlx_start, WIDTH, HEIGHT,
			"Fractol");
	if (fractol->mlx_window == NULL)
	{
		mlx_destroy_display(fractol->mlx_start);
		free(fractol->mlx_start);
		mlx_failure();
	}
	fractol->img.img_ptr = mlx_new_image(fractol->mlx_start, WIDTH, HEIGHT);
	if (fractol->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractol->mlx_start, fractol->mlx_window);
		mlx_destroy_display(fractol->mlx_start);
		free(fractol->mlx_start);
		mlx_failure();
	}
	fractol->img.ptpix = mlx_get_data_addr(fractol->img.img_ptr,
			&fractol->img.bpp, &fractol->img.line_s, &fractol->img.endian);
	call_events(fractol);
	init_data(fractol);
}
