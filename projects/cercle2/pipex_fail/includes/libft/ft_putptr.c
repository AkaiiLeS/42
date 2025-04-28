/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:30:02 by salsoysa          #+#    #+#             */
/*   Updated: 2025/01/29 19:28:03 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(uintptr_t nbr)
{
	char	*str_hex;
	int		cnt;

	str_hex = "0123456789abcdef";
	cnt = 0;
	if (nbr >= 16)
	{
		cnt += ft_putptr(nbr / 16);
		cnt += ft_putptr(nbr % 16);
	}
	else
		cnt += ft_print_char(str_hex[nbr]);
	if (cnt < 0)
		return (-1);
	return (cnt);
}
