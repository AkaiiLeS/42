/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaiissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 23:22:54 by akaiissa          #+#    #+#             */
/*   Updated: 2025/04/30 08:27:23 by akaiissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_swap(t_list **a, t_list **b, const int size)
{
	if (!ft_is_sorted(*a))
	{
		if (size == 2)
			ft_sa(a, 0);
		else if (size == 3)
			ft_sort3(a);
		else if (size <= 5)
			ft_sort5(a, b, size);
		else if (size > 5)
			ft_sort(a, b, size);
	}
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		size;

	if (ac == 1)
		return (0);
	if (ac < 2 || !ft_check(ac, av, &a, &b))
	{
		ft_printf("Error\n");
		return (0);
	}
	size = ft_lstsize(a);
	ft_getid(a);
	push_swap(&a, &b, size);
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}
