/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:27:58 by evella            #+#    #+#             */
/*   Updated: 2024/01/19 12:52:38 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_Dlist *lstA)
{
	t_Dlist_node *tmp;

	tmp = lstA->first->next;
	if(lstA->first && tmp)
	{
		lstA->first->next = lstA->first->next->next;
		tmp->next = lstA->first;
		lstA->first->back = tmp;
		lstA->first = tmp;
	}
	ft_printf("sa\n");
}

void	sb(t_Dlist *lstB)
{
	t_Dlist_node *tmp;

	tmp = lstB->first->next;
	if(lstB->first && tmp)
	{
		lstB->first->next = lstB->first->next->next;
		tmp->next = lstB->first;
		lstB->first->back = tmp;
		lstB->first = tmp;
	}
	ft_printf("sb\n");
}

void	pa(t_Dlist *lstA, t_Dlist *lstB)
{
	if(lstB->first)
	{
		ft_add_front(lstA, lstB->first->value);
		ft_del_front(lstB);
	}
	ft_printf("pa\n");
}

void	pb(t_Dlist *lstA, t_Dlist *lstB)
{
	if(lstA->first)
	{
		ft_add_front(lstB, lstA->first->value);
		ft_del_front(lstA);
	}
	ft_printf("pb\n");
}
