/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 23:23:40 by salsoysa          #+#    #+#             */
/*   Updated: 2025/04/30 14:37:27 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
# include "libft/libft.h"

typedef struct s_ps
{
	int			value;
	int			index;
	int			pos;
	int			target;
	int			cost_a;
	int			cost_b;
	struct s_ps	*next;
}				t_ps;

//  -- Moves -- //
void			ft_sa(t_ps **stack, int n);
void			ft_sb(t_ps **stack, int n);
void			ft_ss(t_ps **stack_a, t_ps **stack_b, int n);
void			ft_pa(t_ps **stack_a, t_ps **stack_b, int n);
void			ft_pb(t_ps **stack_b, t_ps **stack_a, int n);
void			ft_ra(t_ps **stack, int n);
void			ft_rb(t_ps **stack, int n);
void			ft_rr(t_ps **stack_a, t_ps **stack_b, int n);
void			ft_rra(t_ps **stack, int n);
void			ft_rrb(t_ps **stack, int n);
void			ft_rrr(t_ps **stack_a, t_ps **stack_b, int n);

//  -- Sorting -- //
void			ft_pushb(t_ps **stack_a, t_ps **stack_b, int size);
void			ft_sort(t_ps **stack_a, t_ps **stack_b, int size);
void			ft_move(t_ps **stack_a, t_ps **stack_b, int cost_a, int cost_b);
int				ft_getmax(t_ps *stack);
void			ft_getid(t_ps *stack);
int				ft_is_sorted(t_ps *stack);
void			ft_sort3(t_ps **stack);
void			ft_sort5(t_ps **stack_a, t_ps **stack_b, int size);

// -- Utils -- //
int				ft_check(int ac, char **av, t_ps **a, t_ps **b);
void			ft_lstclear(t_ps **lst);
int				ft_lstsize(t_ps *lst);
t_ps			*ft_lstnew(int value);
void			ft_lstadd_back(t_ps **lst, t_ps *new);
t_ps			*ft_init(char **av);
int				ft_abs(int n);
void			ft_target(t_ps **stack_a, t_ps **stack_b);
void			ft_cost(t_ps **stack_b, int size_a);

#endif
