/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:47:05 by salsoysa          #+#    #+#             */
/*   Updated: 2024/11/22 13:56:58 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *str)
{
	int		cnt;
	char	*nope;

	cnt = 0;
	if (!str)
	{
		nope = "(null)";
		while (nope[cnt])
		{
			if (ft_print_char(nope[cnt]) == -1)
				return (-1);
			cnt++;
		}
	}
	else
	{
		while (str[cnt])
		{
			if (ft_print_char(str[cnt]) == -1)
				return (-1);
			cnt++;
		}
	}
	return (cnt);
}