/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:45:29 by salsoysa          #+#    #+#             */
/*   Updated: 2024/11/16 15:09:12 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_n;
	t_list	*arr;
	void	*mod;

	if (!lst || !f || !del)
		return (NULL);
	lst_n = NULL;
	while (lst)
	{
		mod = f(lst->content);
		arr = ft_lstnew(mod);
		if (!arr)
		{
			del(mod);
			ft_lstclear(&lst_n, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_n, arr);
		lst = lst->next;
	}
	return (lst_n);
}
