/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 08:14:36 by salsoysa          #+#    #+#             */
/*   Updated: 2025/04/30 12:14:11 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_reverse_rotate(t_ps **stack)
{
	t_ps	*prev;
	t_ps	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	prev = *stack;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	ft_rra(t_ps **stack, int n)
{
	ft_reverse_rotate(stack);
	if (n == 0)
		ft_printf("rra\n");
}

void	ft_rrb(t_ps **stack, int n)
{
	ft_reverse_rotate(stack);
	if (n == 0)
		ft_printf("rrb\n");
}

void	ft_rrr(t_ps **stack_a, t_ps **stack_b, int n)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	if (n == 0)
		ft_printf("rrr\n");
}
