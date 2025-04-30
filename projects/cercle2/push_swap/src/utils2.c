/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:48:34 by salsoysa          #+#    #+#             */
/*   Updated: 2025/04/30 12:49:04 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

static void	get_pos(t_ps **stack)
{
	int		i;
	t_ps	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

static int	get_target_pos(t_ps **stack_a, int index, int target_id,
		int target_pos)
{
	t_ps	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index > index && tmp->index < target_id)
		{
			target_id = tmp->index;
			target_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (target_id != INT_MAX)
		return (target_pos);
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index < target_id)
		{
			target_id = tmp->index;
			target_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (target_pos);
}

void	ft_target(t_ps **stack_a, t_ps **stack_b)
{
	t_ps	*tmp;
	int		target;

	target = 0;
	tmp = *stack_b;
	get_pos(stack_a);
	get_pos(stack_b);
	while (tmp)
	{
		target = get_target_pos(stack_a, tmp->index, INT_MAX, target);
		tmp->target = target;
		tmp = tmp->next;
	}
}

void	ft_cost(t_ps **stack_b, int size_a)
{
	t_ps	*b;
	int		size_b;

	b = *stack_b;
	size_b = ft_lstsize(b);
	while (b)
	{
		b->cost_b = b->pos;
		if (b->pos > size_b / 2)
			b->cost_b = (size_b - b->pos) * -1;
		b->cost_a = b->target;
		if (b->target > size_a / 2)
			b->cost_a = (size_a - b->target) * -1;
		b = b->next;
	}
}
