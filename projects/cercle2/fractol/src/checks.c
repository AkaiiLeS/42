/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 23:10:42 by salsoysa          #+#    #+#             */
/*   Updated: 2025/02/27 17:31:36 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	mlx_failure(void)
{
	perror("An Mlx function failed to malloc correctly");
	exit(EXIT_FAILURE);
}

int	skip_space_sign(char *str, int *is_neg)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*is_neg *= -1;
		i++;
	}
	return (i);
}

void	error_msg(void)
{
	ft_putendl_fd("Please try again with the correct input:\n", 2);
	ft_putendl_fd("For the mandelbrot set, type in: ./fractol mandelbrot\n", 2);
	ft_putendl_fd("For the julia set, type in: ./fractol julia <d1> <d2>", 2);
	ft_putendl_fd("with d1 and d2 between -1.5 and 1.5\n", 2);
	exit(EXIT_FAILURE);
}

static int	check_julia(char *av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i])
	{
		if (av[i] == '.')
		{
			while (j < i)
			{
				if (av[j++] == '.')
					error_msg();
			}
		}
		if (av[i] == '+' || av[i] == '-')
		{
			if (i != 0 || ft_isdigit(av[i + 1] == 0))
				error_msg();
		}
		if (ft_isdigit(av[i++] == 0))
			error_msg();
	}
	return (1);
}

int	check_args(int ac, char **av, t_fractal *fractol)
{
	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 11))
	{
		fractol->name = MANDELBROT;
		return (1);
	}
	else if (ac == 4 && !ft_strncmp(av[1], "julia", 6))
	{
		{
			check_julia(av[2]);
			check_julia(av[3]);
			fractol->name = JULIA;
			fractol->jx = atod(av[2]);
			fractol->jy = atod(av[3]);
			return (1);
		}
	}
	else
	{
		error_msg();
		exit(EXIT_FAILURE);
	}
}
