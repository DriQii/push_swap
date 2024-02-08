/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amoove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:04:45 by evella            #+#    #+#             */
/*   Updated: 2024/02/08 00:57:52 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_target(t_Dlist_node *node, t_target *target, int value)
{
	int	i;

	i = 1;
	while (node)
	{
		target->tmpres = value - node->value;
		if ((target->tmpres > 0 && target->res < 0)
			|| (target->tmpres > 0 && target->tmpres < target->res))
		{
			target->res = target->tmpres;
			target->best = i;
		}
		if (node->value > target->maxvalue)
		{
			target->max = i;
			target->maxvalue = node->value;
		}
		i++;
		node = node->next;
	}
}

int	ft_find_target(int value, t_Dlist *lst)
{
	t_target		target;
	t_Dlist_node	*node;

	target.best = 0;
	node = lst->first;
	target.maxvalue = lst->first->value;
	target.max = 1;
	target.res = value - lst->first->value;
	if (target.res > 0)
		target.best = 1;
	ft_target(node, &target, value);
	if (target.best == 0)
		target.best = target.max;
	return (target.best);
}

void	ft_last_rotate(t_Dlist *lst_a, int *count)
{
	int				i;
	int				max;
	int				target;
	t_Dlist_node	*node;

	node = lst_a->first;
	max = 0;
	i = 0;
	target = 1;
	while (node && ++i)
	{
		if (node->value > max)
		{
			max = node->value;
			target = i;
		}
		node = node->next;
	}
	while (lst_a->last->value != max && ++(*count))
	{
		if (target <= lst_a->len / 2)
			ra(lst_a, 1);
		else
			rra(lst_a, 1);
	}
}

void	ft_push_a(t_Dlist *lst_a, t_Dlist *lst_b, t_op op, int *count)
{
	*count += op.total + 1;
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
	while (op.r_current-- > 0)
		ra(lst_a, 1);
	while (op.rr_current-- > 0)
		rra(lst_a, 1);
	while (op.r_target-- > 0)
		rb(lst_b, 1);
	while (op.rr_target-- > 0)
		rrb(lst_b, 1);
	pb(lst_a, lst_b);
}
