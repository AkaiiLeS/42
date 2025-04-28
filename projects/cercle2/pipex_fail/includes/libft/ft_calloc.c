/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:38:46 by salsoysa          #+#    #+#             */
/*   Updated: 2024/11/13 16:28:32 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memfill(size_t size)
{
	void	*str;
	size_t	i;

	str = (void *)malloc(size);
	if (!str)
		return (NULL);
	i = 0;
	while (i < size)
	{
		*(unsigned char *)(str + i) = 0;
		i++;
	}
	return (str);
}

void	*ft_calloc(size_t nbe, size_t size)
{
	if (size && nbe > ((size_t)-1 / size))
		return (NULL);
	return (ft_memfill(nbe * size));
}
