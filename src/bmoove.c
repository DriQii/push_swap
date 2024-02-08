/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmoove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:02:03 by evella            #+#    #+#             */
/*   Updated: 2024/02/08 00:59:46 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_merge(t_Dlist *lst_a, t_Dlist *lst_b, int *count)
{
	t_Dlist_node		*node;
	t_op				moove;
	t_op				tmpmoove;
	int					i;

	i = 2;
	while (lst_b->len > 0)
	{
		node = lst_b->first->next;
		moove = ft_check_nb_moove(1, \
		ft_find_target_b(lst_b->first->value, lst_a), lst_b->len, lst_a->len);
		while (node)
		{
			tmpmoove = ft_check_nb_moove(i, \
			ft_find_target_b(node->value, lst_a), lst_b->len, lst_a->len);
			if (tmpmoove.total < moove.total)
				moove = tmpmoove;
			node = node->next;
			i++;
		}
		i = 2;
		ft_push_b(lst_a, lst_b, moove, count);
	}
	ft_last_rotate(lst_a, count);
}

static void	ft_target(t_Dlist_node *node, t_target *target, int value)
{
	int	i;

	i = 1;
	while (node)
	{
		target->tmpres = value - node->value;
		if ((target->tmpres < 0 && target->res > 0)
			|| (target->tmpres < 0 && target->tmpres > target->res))
		{
			target->res = target->tmpres;
			target->best = i;
		}
		if (node->value < target->maxvalue)
		{
			target->max = i;
			target->maxvalue = node->value;
		}
		i++;
		node = node->next;
	}
}

int	ft_find_target_b(int value, t_Dlist *lst)
{
	t_target		target;
	t_Dlist_node	*node;

	target.best = 0;
	node = lst->first;
	target.maxvalue = lst->first->value;
	target.max = 1;
	target.res = value - lst->first->value;
	if (target.res < 0)
		target.best = 1;
	ft_target(node, &target, value);
	if (target.best == 0)
		target.best = target.max;
	return (target.best);
}

void	ft_push_b(t_Dlist *lst_a, t_Dlist *lst_b, t_op op, int *count)
{
	while (op.r_current > 0 && op.r_target > 0)
	{
		op.r_current--;
		op.r_target--;
		rr(lst_a, lst_b);
		*count -= 1;
	}
	while (op.rr_current > 0 && op.rr_target > 0)
	{
		op.rr_current--;
		op.rr_target--;
		rrr(lst_a, lst_b);
		*count -= 1;
	}
	*count += op.total + 1;
	while (op.r_current-- > 0)
		rb(lst_b, 1);
	while (op.rr_current-- > 0)
		rrb(lst_b, 1);
	while (op.r_target-- > 0)
		ra(lst_a, 1);
	while (op.rr_target-- > 0)
		rra(lst_a, 1);
	pa(lst_a, lst_b);
}
