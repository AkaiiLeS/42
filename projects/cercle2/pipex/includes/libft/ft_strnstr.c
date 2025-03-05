/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:50:09 by salsoysa          #+#    #+#             */
/*   Updated: 2024/11/13 16:28:42 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_l;

	if (ft_strlen(little) == 0)
		return ((char *)big);
	len_l = ft_strlen(little);
	i = 0;
	while (i < len && big[i])
	{
		j = 0;
		while (little[j] == big[i + j] && big[i + j] && i + j < len)
			j++;
		if (j == len_l)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
