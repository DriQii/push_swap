/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:27:58 by evella            #+#    #+#             */
/*   Updated: 2024/02/08 20:56:35 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_Dlist *lst_a)
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
}

void	sb(t_Dlist *lst_b)
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
}

void	pa(t_Dlist *lst_a, t_Dlist *lst_b)
{
	if (lst_b->first)
	{
		ft_add_front(lst_a, lst_b->first->value);
		ft_del_front(lst_b);
	}
}

void	pb(t_Dlist *lst_a, t_Dlist *lst_b)
{
	if (lst_a->first)
	{
		ft_add_front(lst_b, lst_a->first->value);
		ft_del_front(lst_a);
	}
}
