/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:19:37 by salsoysa          #+#    #+#             */
/*   Updated: 2025/02/27 14:42:37 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

int	clean_close(t_fractal *fractol)
{
	mlx_destroy_image(fractol->mlx_start, fractol->img.img_ptr);
	mlx_destroy_window(fractol->mlx_start, fractol->mlx_window);
	mlx_destroy_display(fractol->mlx_start);
	free(fractol->mlx_start);
	exit(EXIT_SUCCESS);
}

int	key_press(int keysym, t_fractal *fractol)
{
	if (keysym == KEY_ESC)
		clean_close(fractol);
	if (keysym == KEY_DOWN)
		fractol->sy -= (0.2 * fractol->zoom);
	else if (keysym == KEY_UP)
		fractol->sy += (0.2 * fractol->zoom);
	else if (keysym == KEY_RIGHT)
		fractol->sx += (0.2 * fractol->zoom);
	else if (keysym == KEY_LEFT)
		fractol->sx -= (0.2 * fractol->zoom);
	else if (keysym == KEY_ONE)
		fractol->max_iteration += 5;
	else if (keysym == KEY_TWO)
		fractol->max_iteration -= 5;
	f_render(fractol);
	return (0);
}

int	mouse_press(int button, int x, int y, t_fractal *fractol)
{
	x = 0;
	y = 0;
	if (button == MOUSE_WHEEL_DOWN)
		fractol->zoom *= 1.05;
	else if (button == MOUSE_WHEEL_UP)
		fractol->zoom *= 0.95;
	f_render(fractol);
	return (0);
}
