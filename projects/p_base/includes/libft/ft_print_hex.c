/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:47:46 by salsoysa          #+#    #+#             */
/*   Updated: 2025/01/29 19:25:39 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_hex(unsigned int nbr, int wcase)
{
	char	*str_hex;

	if (wcase == 'x')
		str_hex = "0123456789abcdef";
	else
		str_hex = "0123456789ABCDEF";
	return (ft_puthex(nbr, str_hex));
}
