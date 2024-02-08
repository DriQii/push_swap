/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:27:58 by evella            #+#    #+#             */
/*   Updated: 2024/02/07 19:48:03 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_Dlist *lst_a, int print)
{
	t_Dlist_node	*tmp;

	tmp = lst_a->first->next;
	if (lst_a->first && tmp)
	{
		lst_a->first->next = lst_a->first->next->next;
		if (lst_a->len >= 3)
			lst_a->first->next->back = lst_a->first;
		tmp->next = lst_a->first;
		lst_a->first->back = tmp;
		lst_a->first = tmp;
	}
	if (print == 1)
		ft_putstr("sa\n");
}

void	sb(t_Dlist *lst_b, int print)
{
	t_Dlist_node	*tmp;

	tmp = lst_b->first->next;
	if (lst_b->first && tmp)
	{
		lst_b->first->next = lst_b->first->next->next;
		if (lst_b->len >= 3)
			lst_b->first->next->back = lst_b->first;
		tmp->next = lst_b->first;
		lst_b->first->back = tmp;
		lst_b->first = tmp;
	}
	if (print == 1)
		ft_putstr("sb\n");
}

void	pa(t_Dlist *lst_a, t_Dlist *lst_b)
{
	if (lst_b->first)
	{
		ft_add_front(lst_a, lst_b->first->value);
		ft_del_front(lst_b);
	}
	ft_putstr("pa\n");
}

void	pb(t_Dlist *lst_a, t_Dlist *lst_b)
{
	if (lst_a->first)
	{
		ft_add_front(lst_b, lst_a->first->value);
		ft_del_front(lst_a);
	}
	ft_putstr("pb\n");
}
