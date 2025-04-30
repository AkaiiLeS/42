#include "../includes/push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

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

int	ft_lstsize(t_list *lst)
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

t_list	*ft_lstnew(int value)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
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

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

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

t_list	*ft_init(char **av)
{
	t_list	*a;
	t_list	*new;
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
