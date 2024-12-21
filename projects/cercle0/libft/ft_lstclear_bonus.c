/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:38:48 by salsoysa          #+#    #+#             */
/*   Updated: 2024/11/16 15:16:58 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*index;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		index = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = index;
	}
	*lst = NULL;
}
