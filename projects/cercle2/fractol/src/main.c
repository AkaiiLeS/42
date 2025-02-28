/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:41:29 by salsoysa          #+#    #+#             */
/*   Updated: 2025/02/27 16:56:18 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractol;

	if (!check_args(ac, av, &fractol))
		exit(EXIT_FAILURE);
	init_f(&fractol);
	f_render(&fractol);
	mlx_loop(fractol.mlx_start);
	exit(EXIT_SUCCESS);
}
