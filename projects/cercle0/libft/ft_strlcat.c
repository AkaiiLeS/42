/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:41:14 by salsoysa          #+#    #+#             */
/*   Updated: 2024/11/13 16:48:01 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	dstlen;
	size_t	j;

	i = 0;
	if (!siz)
		return (ft_strlen(src));
	dstlen = ft_strlen(dst);
	j = 0;
	while (dst[j])
		j++;
	while (src[i] && (i + j + 1) < siz)
	{
		dst[i + j] = src[i];
		i++;
	}
	if (i < siz)
		dst[i + j] = '\0';
	if (siz <= dstlen)
		return (siz + ft_strlen(src));
	else
		return (ft_strlen(src) + dstlen);
}
