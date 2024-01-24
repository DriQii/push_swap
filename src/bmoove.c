/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmoove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:02:03 by evella            #+#    #+#             */
/*   Updated: 2024/01/24 21:15:28 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_merge(t_Dlist *lstA, t_Dlist *lstB, int *count)
{
	t_Dlist_node	*node;
	t_op				moove;
	t_op				tmpmoove;
	int					i;


	i = 2;
	while (lstB->len > 0)
	{
		node = lstB->first->next;
		moove = ft_check_nb_moove(1, ft_find_targetB(lstB->first->value, lstA), lstB->len, lstA->len);
		while(node)
		{
			tmpmoove = ft_check_nb_moove(i, ft_find_targetB(node->value, lstA), lstB->len, lstA->len);
			if(tmpmoove.total < moove.total)
				moove = tmpmoove;
			node = node->next;
			i++;
		}
		i = 2;
		ft_pushB(lstA, lstB, moove, count);
	}
	ft_last_rotate(lstA, count);
}

int	ft_find_targetB(int	value, t_Dlist *lst)
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
	if(target.res < 0)
		target.best = 1;
	while(node)
	{
		target.tmpres = value - node->value;
		if ((target.tmpres < 0 && target.res > 0) || (target.tmpres < 0 && target.tmpres > target.res))
		{
			target.res = target.tmpres;
			target.best = i;
		}
		if(node->value < target.maxvalue)
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

void	ft_pushB(t_Dlist *lstA, t_Dlist *lstB, t_op op,int *count)
{
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
	*count += op.total + 1;
	while (op.r_current-- > 0)
		rb(lstB, 1);
	while (op.rr_current-- > 0)
		rrb(lstB, 1);
	while (op.r_target-- > 0)
		ra(lstA, 1);
	while (op.rr_target-- > 0)
		rra(lstA, 1);
	pa(lstA, lstB);
}
