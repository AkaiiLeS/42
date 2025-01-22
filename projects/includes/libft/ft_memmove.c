/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:33:27 by salsoysa          #+#    #+#             */
/*   Updated: 2024/11/16 15:12:42 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*t_dst;
	const unsigned char	*t_src;

	if (!dst && !src)
		return (NULL);
	if (dst < src)
		ft_memcpy(dst, src, n);
	else
	{
		t_dst = dst;
		t_src = src;
		while (n--)
			t_dst[n] = t_src[n];
	}
	return (dst);
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
