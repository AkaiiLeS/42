/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:31:48 by salsoysa          #+#    #+#             */
/*   Updated: 2024/11/13 16:29:20 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	k;
	char	*str;

	i = 0;
	if (!s1)
		return (NULL);
	k = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (i < k && ft_strchr(set, s1[k - 1]))
		k--;
	str = (char *)malloc(sizeof(char) * (k - i + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1 + i, k - i + 1);
	str[k - i] = '\0';
	return (str);
}
