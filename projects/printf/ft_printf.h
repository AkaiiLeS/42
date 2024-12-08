/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:51:05 by salsoysa          #+#    #+#             */
/*   Updated: 2024/11/22 13:19:32 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdint.h>

// Utils
int		ft_putptr(uintptr_t nbr);
int		ft_puthex(unsigned int nbr, char *str_hex);
int		ft_putnbr(int nb);
void	ft_putchar(char c);
int		ft_putunbr(unsigned int nbr);

// Print foo
int		ft_print_string(char *str);
int		ft_print_uint(unsigned int nbr);
int		ft_print_decimal(int a);
int		ft_print_char(char c);
int		ft_print_pvoid(uintptr_t p);
int		ft_printf(const char *str, ...);
int		ft_print_hex(unsigned int nbr, int wcase);
#endif
