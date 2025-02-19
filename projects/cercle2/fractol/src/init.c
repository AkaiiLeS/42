/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:54:54 by salsoysa          #+#    #+#             */
/*   Updated: 2025/01/31 20:01:28 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"
#include "../minilibx-linux/mlx.h"



void	init_data(t_fractal *fractol)
{
	
}
void	init_f(t_fractal *fractol)
{
	fractol->mlx_start = mlx_init();
	if (fractol->mlx_start == NULL)
		mlx_failure();
	fractol->mlx_window = mlx_new_window(fractol->mlx_start, HEIGHT, \
			WIDTH, fractol->name);
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
	fractol->img.ptpix = mlx_get_data_addr(fractol->img.img_ptr, \
			fractol->img.bpp, 
			fractol->img.line_s, &fractol->img.endian);
	//init_events; To do
	//init_data; To do
}

