/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:38:01 by salsoysa          #+#    #+#             */
/*   Updated: 2024/11/22 13:18:21 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int nbr, char *str_hex)
{
	int	cnt;

	cnt = 0;
	if (nbr >= 16)
	{
		cnt += ft_puthex(nbr / 16, str_hex);
		cnt += ft_puthex(nbr % 16, str_hex);
	}
	else
		cnt += ft_print_char(str_hex[nbr]);
	if (cnt < 0)
		return (-1);
	return (cnt);
}