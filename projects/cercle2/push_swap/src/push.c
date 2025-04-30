/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 08:05:15 by salsoysa          #+#    #+#             */
/*   Updated: 2025/04/30 12:01:59 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_push(t_ps **dst, t_ps **src)
{
	t_ps	*tmp;

	if (!*src)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = tmp;
}

void	ft_pa(t_ps **stack_a, t_ps **stack_b, int n)
{
	ft_push(stack_a, stack_b);
	if (n == 0)
		ft_printf("pa\n");
}

void	ft_pb(t_ps **stack_b, t_ps **stack_a, int n)
{
	ft_push(stack_b, stack_a);
	if (n == 0)
		ft_printf("pb\n");
}
