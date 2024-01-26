/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amoove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:04:45 by evella            #+#    #+#             */
/*   Updated: 2024/01/26 14:10:38 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_target(int	value, t_Dlist *lst)
{
	t_target		target;
	t_Dlist_node	*node;
	int				i;

	i = 1;
	target.best = 0;
	node = lst->first;
	target.maxvalue = lst->first->value;
	target.max = 1;
	target.res = value - lst->first->value;
	if(target.res > 0)
		target.best = 1;
	while(node)
	{
		target.tmpres = value - node->value;
		if ((target.tmpres > 0 && target.res < 0) || (target.tmpres > 0 && target.tmpres < target.res))
		{
			target.res = target.tmpres;
			target.best = i;
		}
		if(node->value > target.maxvalue)
		{
			target.max = i;
			target.maxvalue = node->value;
		}
		i++;
		node = node->next;
	}
	if(target.best == 0)
		target.best = target.max;
	return(target.best);
}

void	ft_last_rotate(t_Dlist *lstA, int *count)
{
	int	i;
	int	max;
	int	target;
	t_Dlist_node *node;

	node = lstA->first;
	max = 0;
	i = 1;
	target = 1;
	while (node)
	{
		if(node->value > max)
		{
			max = node->value;
			target = i;
		}
		i++;
		node = node->next;
	}
	while (lstA->last->value != max)
	{
		if(target <= lstA->len / 2)
			ra(lstA, 1);
		else
			rra(lstA, 1);
		*count += 1;
	}
}

void	ft_pushA(t_Dlist *lstA, t_Dlist *lstB, t_op op,int *count)
{
	*count += op.total + 1;
	while (op.r_current > 0 && op.r_target > 0)
	{
		op.r_current--;
		op.r_target--;
		rr(lstA, lstB);
		*count -= 1;
	}
	while (op.rr_current > 0 && op.rr_target > 0)
	{
		op.rr_current--;
		op.rr_target--;
		rrr(lstA, lstB);
		*count -= 1;
	}
	while (op.r_current-- > 0)
		ra(lstA, 1);
	while (op.rr_current-- > 0)
		rra(lstA, 1);
	while (op.r_target-- > 0)
		rb(lstB, 1);
	while (op.rr_target-- > 0)
		rrb(lstB, 1);
	pb(lstA, lstB);
}
