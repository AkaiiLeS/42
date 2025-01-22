/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:35:36 by salsoysa          #+#    #+#             */
/*   Updated: 2024/11/22 13:15:25 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int nbr)
{
	int	cnt;

	cnt = 0;
	if (nbr >= 10)
	{
		cnt += ft_putnbr(nbr / 10);
		cnt += ft_putnbr(nbr % 10);
	}
	else
		cnt += ft_print_char(nbr + 48);
	return (cnt);
}
