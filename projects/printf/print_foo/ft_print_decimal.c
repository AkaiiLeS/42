/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:46:35 by salsoysa          #+#    #+#             */
/*   Updated: 2024/11/19 16:46:57 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_decimal(int a)
{
	int	cnt;

	cnt = 0;
	cnt += ft_putnbr(a);
	if (cnt < 0)
		return (-1);
	return (cnt);
}