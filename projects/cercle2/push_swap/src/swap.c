/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 08:18:54 by salsoysa          #+#    #+#             */
/*   Updated: 2025/04/30 14:36:14 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_swap(t_ps **stack)
{
	t_ps	*first;
	t_ps	*second;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	ft_sa(t_ps **stack, int n)
{
	ft_swap(stack);
	if (n == 0)
		ft_printf("sa\n");
}

void	ft_sb(t_ps **stack, int n)
{
	ft_swap(stack);
	if (n == 0)
		ft_printf("sb\n");
}

void	ft_ss(t_ps **stack_a, t_ps **stack_b, int n)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	if (n == 0)
		ft_printf("ss\n");
}
