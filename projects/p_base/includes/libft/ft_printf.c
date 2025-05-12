/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:48:45 by salsoysa          #+#    #+#             */
/*   Updated: 2025/04/30 13:10:40 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	format_set(const char *str, va_list param, int i)
{
	int	cnt;

	cnt = 0;
	if (str[i] == 'c')
		cnt += ft_print_char((char)va_arg(param, int));
	else if (str[i] == 's')
		cnt += ft_print_string((char *)va_arg(param, char *));
	else if (str[i] == 'p')
		cnt += ft_print_pvoid((uintptr_t)va_arg(param, uintptr_t));
	else if (str[i] == 'u')
		cnt += ft_print_uint((unsigned int)va_arg(param, unsigned int));
	else if (str[i] == 'x' || str[i] == 'X')
		cnt += ft_print_hex((unsigned int)va_arg(param, unsigned int), str[i]);
	else if (str[i] == 'd' || str[i] == 'i')
		cnt += ft_print_decimal((int)va_arg(param, int));
	else if (str[i] == '%')
		cnt += ft_print_char('%');
	return (cnt);
}

static int	subprint(const char *str, va_list param)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			cnt += format_set(str, param, ++i);
			if (cnt < 0)
				return (-1);
		}
		else
		{
			cnt += ft_print_char(str[i]);
			if (cnt < 0)
				return (-1);
		}
		i++;
	}
	return (cnt);
}

int	ft_printf(const char *str, ...)
{
	va_list	param;
	int		cnt;

	va_start(param, str);
	cnt = 0;
	if (!str)
		return (-1);
	cnt = subprint(str, param);
	va_end(param);
	return (cnt);
}
//
//int	main(void)
//{
//	ft_printf("Mine:%d\n", ft_printf("%s", "it works!!"));
//	printf("Std:%d\n", ft_printf("%s", "it works!!"));
//	ft_printf("Mine:%s\n", "test");
//	printf("Std:%s\n", "test");
//	ft_printf("Mine:%p\n", "test");
//	printf("Std:%p\n", "test");
//	ft_printf("Mine:%c\n", 'T');
//	printf("Std:%c\n", 'T');
//	ft_printf("Mine:%u\n", 313199);
//	printf("Std:%u\n", 313199);
//	ft_printf("Mine:%%\n", '%');
//	printf("Std:%u\n", '%');
//	ft_printf("Mine:%x\n", 2455);
//	printf("Std:%x\n", 2455);
//	ft_printf("Mine:%X\n", 245598238);
//	printf("Std:%X\n", 245598238);
//}
