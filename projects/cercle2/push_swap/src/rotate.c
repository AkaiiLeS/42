/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 08:17:57 by salsoysa          #+#    #+#             */
/*   Updated: 2025/04/30 14:36:50 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_rotate(t_ps **stack)
{
	t_ps	*first;
	t_ps	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	ft_ra(t_ps **stack, int n)
{
	ft_rotate(stack);
	if (n == 0)
		ft_printf("ra\n");
}

void	ft_rb(t_ps **stack, int n)
{
	ft_rotate(stack);
	if (n == 0)
		ft_printf("rb\n");
}

void	ft_rr(t_ps **stack_a, t_ps **stack_b, int n)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	if (n == 0)
		ft_printf("rr\n");
}
