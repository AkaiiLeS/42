/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 23:23:08 by salsoysa          #+#    #+#             */
/*   Updated: 2025/04/30 14:35:49 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_lstclear(t_ps **lst)
{
	t_ps	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

int	ft_lstsize(t_ps *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_ps	*ft_lstnew(int value)
{
	t_ps	*new;

	new = (t_ps *)malloc(sizeof(t_ps));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = -1;
	new->target = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_ps **lst, t_ps *new)
{
	t_ps	*tmp;

	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_ps	*ft_init(char **av)
{
	t_ps	*a;
	t_ps	*new;
	int		content;
	int		i;
	int		n;

	i = 0;
	n = 0;
	a = NULL;
	while (av[n])
		n++;
	while (i < n)
	{
		content = ft_atoi(av[i]);
		new = ft_lstnew(content);
		if (!new)
		{
			ft_lstclear(&a);
			return (NULL);
		}
		ft_lstadd_back(&a, new);
		i++;
	}
	return (a);
}
