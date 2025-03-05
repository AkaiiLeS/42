/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:03:02 by salsoysa          #+#    #+#             */
/*   Updated: 2025/01/29 19:28:10 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int nb)
{
	int	cnt;

	cnt = 0;
	if (nb == -2147483648)
		cnt += ft_print_string("-2147483648");
	else if (nb < 0)
	{
		cnt += ft_print_char('-');
		nb = -nb;
		cnt += ft_putnbr(nb);
	}
	else
	{
		if (nb >= 10)
		{
			cnt += ft_putnbr(nb / 10);
			cnt += ft_putnbr(nb % 10);
		}
		else
			cnt += ft_print_char(nb + 48);
	}
	if (cnt < 0)
		return (-1);
	return (cnt);
}
