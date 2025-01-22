/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:03:38 by salsoysa          #+#    #+#             */
/*   Updated: 2024/11/16 15:14:42 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ilen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		i;
	int		cpy;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	cpy = n;
	if (n < 0)
		cpy = -n;
	i = ft_ilen(n);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	i--;
	if (cpy == 0)
		str[i] = '0';
	while (cpy > 0)
	{
		str[i--] = (cpy % 10) + '0';
		cpy /= 10;
	}
	if (n < 0)
		str[i] = '-';
	return (str);
}
