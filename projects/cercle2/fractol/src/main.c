#include "../headers/fractol.h"

int	main(int ac, char **av)
{
	t_fractal fractol;

//	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 11)) \
//			|| (ac == 4 && !ft_strncmp(av[1], "julia", 6)))
//	{
//		fractol.name = av[1];
//		init_f(&fractol);	
//	}
//	else
//	{
//		ft_putendl_fd("NOPE TRY AGAIN", 1);
//		exit(EXIT_FAILURE);
//	}
	if (!check_args(ac, av, &fractol))
			exit(EXIT_FAILURE);
	init_f(&fractol);
//	render_f(&fractol);
//	mlx_key_hook(fractol->mlx_start, &keyhook, &fractol);
//	mlx_scroll_hook(fractol->mlx_start, &scrollhook, &fractol);
//	mlx_loop(fractol->mlx_start);
//	mlx_terminate(fractol->mlx_start);
	exit (EXIT_SUCCESS);
}
