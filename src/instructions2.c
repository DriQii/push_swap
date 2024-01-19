/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:53:53 by evella            #+#    #+#             */
/*   Updated: 2024/01/19 13:41:05 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_Dlist *lstA)
{
	if(lstA->first)
	{
		ft_add_back(lstA, lstA->first->value);
		ft_del_front(lstA);
		lstA->len++;
	}
	printf("ra\n");
}

void	rb(t_Dlist *lstB)
{
	if(lstB->first)
	{
		ft_add_back(lstB, lstB->first->value);
		ft_del_front(lstB);
		lstB->len++;
	}
	printf("rb\n");
}

void	rra(t_Dlist *lstA)
{
	if(lstA->first)
	{
		ft_add_front(lstA, lstA->last->value);
		ft_del_back(lstA);
		lstA->len++;
	}
	printf("rra\n");
}

void	rrb(t_Dlist *lstB)
{
	if(lstB->first)
	{
		ft_add_front(lstB, lstB->last->value);
		ft_del_back(lstB);
		lstB->len++;
	}
	printf("rra\n");
}
