/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:41:19 by salsoysa          #+#    #+#             */
/*   Updated: 2025/02/27 17:35:52 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../headers/keys.h"
# include "../includes/libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 700
# define HEIGHT 700

// * Colors in ARGB * //
# define BLACK 0x000000FF
# define WHITE 0xFFFFFFFF
# define RED 0xFF0000FF
# define GREEN 0x00FF00FF
# define BLUE 0x0000FFFF
# define YELLOW 0xFFFF00FF
# define MAGENTA 0xFF00FFFF
# define CYAN 0x00FFFFFF
# define ORANGE 0xFFA500FF
# define PURPLE 0x660066FF
# define GRAY 0x808080FF
# define LIGHT_GRAY 0xD3D3D3FF
# define DARK_GRAY 0xA9A9A9FF

// * FRACTAL SETS * //
# define JULIA 1
# define MANDELBROT 2
# define BURNINGSHIP 3

// * Structs * //
typedef struct s_compnum
{
	double	real;
	double	imaginary;
}			t_compnum;

typedef struct s_img
{
	void	*img_ptr;
	int		bpp;
	int		line_s;
	char	*ptpix;
	int		endian;
}			t_img;

typedef struct s_fractal
{
	int		name;
	void	*mlx_start;
	void	*mlx_window;
	t_img	img;
	double	esc_val;
	int		max_iteration;
	double	sy;
	double	sx;
	double	zoom;
	double	jx;
	double	jy;
}			t_fractal;

// * Checks * //
int			check_args(int ac, char **av, t_fractal *fractol);
void		error_msg(void);
void		mlx_failure(void);
int			skip_space_sign(char *str, int *is_neg);

// * Fractal Init * //
void		init_f(t_fractal *fractol);
void		init_data(t_fractal *fractol);
void		f_render(t_fractal *fractol);

// * Math foo * //
t_compnum	square_comp_values(t_compnum z, t_fractal *fractol);
t_compnum	add_comp_values(t_compnum z1, t_compnum z2, t_fractal *fractol);
double		scale_pixel(double xy, double new_min, double new_max,
				double old_max);
double		atod(char *str);

// * Events foot * //
int			clean_close(t_fractal *fractol);
int			key_press(int keysym, t_fractal *fractol);
int			mouse_press(int button, int x, int y, t_fractal *fractol);

#endif
