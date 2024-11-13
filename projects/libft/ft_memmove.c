/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:33:27 by salsoysa          #+#    #+#             */
/*   Updated: 2024/11/13 16:31:31 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdint.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (dest);
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
			i++;
		}
		return (dest);
	}
	else
	{
		i = n - 1;
		while (i != (size_t) - 1)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
			i--;
		}
		return (dest);
	}
}
// if (!dest && !src)
// return (NULL);
//#include <stdio.h>
//
// int	main(void)
//{
//	char dest[20] = "Bonjour";
//	char src[] = "Salut";
//
//	printf("Starting position:\n");
//	printf("Dest: %s\n", dest);
//	printf("Src: %s\n", src);
//
//	ft_memmove(dest, src, 5);
//
//	printf("Ending position:\n");
//	printf("Dest: %s\n", dest);
//	printf("Src: %s\n", src);
//
//	return (0);
//}
