/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 23:10:42 by salsoysa          #+#    #+#             */
/*   Updated: 2025/01/31 19:15:45 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	mlx_failure(void)
{
	perror("An Mlx function failed to malloc correctly");
	exit(EXIT_FAILURE);
}

static double	atod(char *av)
{
	long	pre_dec;
	double	post_dec;
	double	power;
	int		sign;

	pre_dec = 0;
	post_dec = 0;
	sign = 1;
	power = 1;
	while ((*av <= 13 && *av >= 9) || *av == 32)
		av++;
	while (*av == '+' || *av == '-')
		if (*av == '-')
			sign = -sign;
	while (*av != '.' && *av)
		pre_dec = (pre_dec * 10) + (*av++ - 48);
	if (*av == '.')
		av++;
	while (*av)
	{
		power /= 10;
		post_dec = post_dec + (*av++ - 48) * power;
	}
	return ((pre_dec + post_dec) * sign);
}

void	error_msg(void)
{
	ft_putendl_fd("Please try again with the correct input:\n", 2);
	ft_putendl_fd("For the mandelbrot set, type in: ./fractol mandelbrot\n", 2);
	ft_putendl_fd("For the julia set, type in: ./fractol julie <d1> <d2>\n", 2);
	ft_putendl_fd("For the burningship set, type in: \
./fractol burningship\n",
					2);
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
		fractol->name = av[1];
		return (1);
	}
	else if (ac == 2 && !ft_strncmp(av[1], "burningship", 11))
	{
		fractol->name = av[1];
		return (1);
	}
	else if (ac == 4 && !ft_strncmp(av[1], "julia", 6))
	{
		{
			check_julia(av[2]);
			check_julia(av[3]);
			fractol->name = av[1];
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
