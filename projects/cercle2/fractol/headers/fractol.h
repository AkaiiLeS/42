/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:41:19 by salsoysa          #+#    #+#             */
/*   Updated: 2025/02/19 12:24:44 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../includes/libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR_1 "Wrong arguments, \
	please retry with valid arguments :\n\"./fractol mandelbrot\" \
	or \"./fractol julia <first_value> <second_value>\"\n"

# define WIDTH 900
# define HEIGHT 900

typedef struct s_compnum
{
	double	real;
	double	imaginary;
}			t_compnum;

typedef struct s_img
{
	void	*img_ptr;
	int		*bpp;
	int		*line_s;
	char	*ptpix;
	int		endian;
}			t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_start;
	void	*mlx_window;
	t_img	img;
	double	sy;
	double	sx;
	double	zoom;
	double	jx;
	double	jy;
	double	min_real;
	double	max_real;
	double	min_im;
	double	max_im;
}			t_fractal;

// * Checks * //

int	check_args(int ac, char **av, t_fractal *fractol);
void	error_msg(void);
void	mlx_failure(void);

// * Fractal Init * //
void	init_f(t_fractal *fractol);
void	init_data(t_fractal *fractol);

// * Math foo * //
t_compnum square_comp_values(t_compnum z, t_fractal *fractol);
t_compnum	add_comp_values(t_compnum z1, t_compnum z2, t_fractal *fractol);
double	scale_pixel(double xy, double new_min, double new_max, double old_max);

#endif
