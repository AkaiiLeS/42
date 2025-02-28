#include <stdlib.h>
#include "../minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <stdlib.h>
#include <stdio.h>

#define MALLOC_ERROR 1
#define WIDTH	400
#define HEIGHT	400
#define	MLX_ERROR 1

//int	main()
//{
	//void *mlx_ptr;
	//mlx_ptr = mlx_init();
		//if (NULL == mlx_ptr)
			//return (1);
	//mlx_destroy_display(mlx_ptr);
	//free(mlx_ptr);
//}

//int	main()
//{
//	void *mlx_connection; // ptr qui recupere l'init du serveur
//	void *mlx_window; // ptr qui va recup le return de mlx_window qui est un énorme malloc.
//
//	mlx_connection = mlx_init(); 
//	// protection pcq mlx_init c'est un gros malloc sa mère.
//	if (NULL == mlx_connection)
//		return(MALLOC_ERROR);
//	mlx_window = mlx_new_window(mlx_connection, HEIGHT, WIDTH, "My window"); 
//	// pareil protection du gros malloc sa maman
//	if (NULL == mlx_window)
//	{
//		mlx_destroy_display(mlx_connection);
//		free(mlx_connection);
//		return(MALLOC_ERROR);
//	}
//	mlx_loop(mlx_connection); 
//	// mlx_loop permet de garder le serveur actif, pcq sinon la window s'ouvre et s'éteint instant
//
//	// ici je vais avoir des leaks si j'arrête avec C-c, pour éviter ces leaks je dois fair un 
//	// event
//	
//	mlx_destroy_window(mlx_connection, mlx_window); // detruit la window
//	mlx_destroy_display(mlx_connection); // detruit et clean la connection
//	free(mlx_connection); // free tout pour éviter tout leak
//}

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_mlx_data;

// on va stocker toutes les infos dont on a besoin dans cette struct pcq la 
// fonction de principale prend (void *)ptr_sur_info
// on a besoin de tout ca pour passer plus d'élements d'un coup du coup

int	input_work(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		printf("The %d key (ESC) has been pressed\n\n", keysym);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	printf("The %d key has been pressed\n\n", keysym);
	return (0);
}

int	main(void)
{
	t_mlx_data data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "Première fenêtre!");
	if (data.win_ptr == NULL)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (MLX_ERROR);
	}

	mlx_key_hook(data.win_ptr, input_work, &data);
	// les fonctions "mlx_hook" (dont mlx_key_hook), permettent de reagir a des events
	// un event est toutes actions qui se fait dans la window, comme par exemple appuyer sur (ESC)
	// un hook c'est souvent utiliser pour debuguer
	mlx_loop(data.mlx_ptr);
}

