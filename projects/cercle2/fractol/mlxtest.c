#include <stdlib.h>
#include "minilibx-linux/mlx.h"

#define MALLOC_ERROR 1
#define WIDTH	400
#define HEIGHT	400

//int	main()
//{
	//void *mlx_ptr;
	//mlx_ptr = mlx_init();
		//if (NULL == mlx_ptr)
			//return (1);
	//mlx_destroy_display(mlx_ptr);
	//free(mlx_ptr);
//}

int	main()
{
	void *mlx_connection; // ptr qui recupere l'init du serveur
	void *mlx_window; // ptr qui va recup le return de mlx_window qui est un énorme malloc.

	mlx_connection = mlx_init(); // protection pcq mlx_init c'est un gros malloc sa mère.
	if (NULL == mlx_connection)
		return(MALLOC_ERROR);
	mlx_window = mlx_new_window(mlx_connection, HEIGHT, WIDTH, "My window"); // pareil protection du gros malloc sa maman
	if (NULL == mlx_window)
	{
		mlx_destroy_display(mlx_connection);
		free(mlx_connection);
		return(MALLOC_ERROR);
	}
	mlx_loop(mlx_connection); // mlx_loop permet de garder le serveur actif, pcq sinon la window s'ouvre et s'éteint instant

	mlx_destroy_window(mlx_connection, mlx_window); // detruit la window
	mlx_destroy_display(mlx_connection); // detruit et clean la connection
	free(mlx_connection); // free tout pour éviter tout leak
}
