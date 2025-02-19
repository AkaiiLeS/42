/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pvoid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:48:12 by salsoysa          #+#    #+#             */
/*   Updated: 2025/01/29 19:29:13 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_pvoid(uintptr_t p)
{
	int	cnt;

	cnt = 0;
	if (!p)
		return (ft_print_string("(nil)"));
	cnt += ft_print_string("0x");
	if (cnt < 0)
		return (-1);
	cnt += ft_putptr(p);
	if (cnt < -1)
		return (-1);
	return (cnt);
}
