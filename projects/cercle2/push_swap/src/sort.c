/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 08:19:50 by salsoysa          #+#    #+#             */
/*   Updated: 2025/04/30 14:36:27 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_getmax(t_ps *stack)
{
	int	max;

	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

void	ft_getid(t_ps *stack)
{
	t_ps	*head;
	t_ps	*tmp;
	int		i;

	head = stack;
	while (head)
	{
		i = 1;
		tmp = stack;
		while (tmp)
		{
			if (tmp->value < head->value)
				i++;
			tmp = tmp->next;
		}
		head->index = i;
		head = head->next;
	}
}

int	ft_is_sorted(t_ps *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_sort3(t_ps **stack)
{
	int	max;

	max = ft_getmax(*stack);
	if (ft_is_sorted(*stack))
		return ;
	if ((*stack)->index == max)
		ft_ra(stack, 0);
	else if ((*stack)->next->index == max)
		ft_rra(stack, 0);
	if ((*stack)->index > (*stack)->next->index)
		ft_sa(stack, 0);
}

void	ft_sort5(t_ps **stack_a, t_ps **stack_b, int size)
{
	while (ft_lstsize(*stack_a) > size - 2)
	{
		if ((*stack_a)->index == 1 || (*stack_a)->index == 2)
			ft_pb(stack_b, stack_a, 0);
		else
			ft_ra(stack_a, 0);
	}
	if (ft_is_sorted(*stack_b))
		ft_sb(stack_b, 0);
	ft_sort3(stack_a);
	ft_pa(stack_a, stack_b, 0);
	ft_pa(stack_a, stack_b, 0);
}
