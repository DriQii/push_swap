/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:27:58 by evella            #+#    #+#             */
/*   Updated: 2024/01/24 21:31:30 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_Dlist *lstA, int print)
{
	t_Dlist_node *tmp;

	tmp = lstA->first->next;
	if(lstA->first && tmp)
	{

		lstA->first->next = lstA->first->next->next;
		if(lstA->len >= 3)
			lstA->first->next->back = lstA->first;
		tmp->next = lstA->first;
		lstA->first->back = tmp;
		lstA->first = tmp;
	}
	if (print == 1)
		ft_putstr("sa\n");
}

void	sb(t_Dlist *lstB, int print)
{
	t_Dlist_node *tmp;

	tmp = lstB->first->next;
	if(lstB->first && tmp)
	{
		lstB->first->next = lstB->first->next->next;
		if(lstB->len >= 3)
			lstB->first->next->back = lstB->first;
		tmp->next = lstB->first;
		lstB->first->back = tmp;
		lstB->first = tmp;
	}
	if (print == 1)
		ft_putstr("sb\n");
}

void	pa(t_Dlist *lstA, t_Dlist *lstB)
{
	if(lstB->first)
	{
		ft_add_front(lstA, lstB->first->value);
		ft_del_front(lstB);
	}
	ft_putstr("pa\n");
}

void	pb(t_Dlist *lstA, t_Dlist *lstB)
{
	if(lstA->first)
	{
		ft_add_front(lstB, lstA->first->value);
		ft_del_front(lstA);
	}
	ft_putstr("pb\n");
}
