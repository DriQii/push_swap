/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:27:55 by evella            #+#    #+#             */
/*   Updated: 2024/02/08 21:09:33 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cut_tri(int state, int *count, t_Dlist *lst_a)
{
	if (state == 1)
	{
		sa(lst_a, 1);
		rra(lst_a, 1);
		*count += 1;
	}
	else
	{
		sa(lst_a, 1);
		ra(lst_a, 1);
		*count += 1;
	}
}

void	ft_tri3(t_Dlist *lst_a, int *count)
{
	if (lst_a->first->value > lst_a->first->next->value
		&& lst_a->first->next->value > lst_a->first->next->next->value)
		ft_cut_tri(1, count, lst_a);
	else if (lst_a->first->value > lst_a->first->next->value
		&& lst_a->first->next->value < lst_a->first->next->next->value
		&& lst_a->first->next->next->value > lst_a->first->value)
		sa(lst_a, 1);
	else if (lst_a->first->value > lst_a->first->next->value
		&& lst_a->first->next->value < lst_a->first->next->next->value
		&& lst_a->first->next->next->value < lst_a->first->value)
		ra(lst_a, 1);
	else if (lst_a->first->value < lst_a->first->next->value
		&& lst_a->first->next->value > lst_a->first->next->next->value
		&& lst_a->first->next->next->value > lst_a->first->value)
		ft_cut_tri(2, count, lst_a);
	else if (lst_a->first->value < lst_a->first->next->value
		&& lst_a->first->next->value > lst_a->first->next->next->value
		&& lst_a->first->next->next->value < lst_a->first->value)
		rra(lst_a, 1);
	*count += 1;
}

t_op	ft_check_nb_moove(int current, int target \
, int lstlen, int lst_target_len)
{
	t_op	op;
	int		count;
	int		state;
	int		tmp;

	state = -1;
	count = 0;
	op = ft_set_op(target, current);
	ft_first_moove(&op, lst_target_len, lstlen);
	tmp = op.r_current + op.rr_target + op.rr_current + op.r_target;
	if ((target - 1) < tmp && op.rr_current == 0)
	{
		count = target - 1;
		state = 1;
	}
	if (lst_target_len - target + 1 < tmp && op.r_current == 0)
		ft_state(&state, &op, &count, lst_target_len);
	if (current - 1 < tmp && op.rr_target == 0)
		ft_state_2(&state, &op, &count);
	if (lstlen - current + 1 < tmp && op.r_target == 0)
		ft_state_3(&state, &op, &count, lstlen);
	ft_last_moove(&state, &op, lstlen, lst_target_len);
	ft_last_moove_2(&state, &op, lstlen, lst_target_len);
	ft_end_moove(&op);
	return (op);
}

void	ft_turk_algo(t_Dlist *lst_a, t_Dlist *lst_b, int *count)
{
	t_Dlist_node		*node;
	t_op				moove;
	t_op				tmpmoove;
	int					i;

	i = 1;
	pb(lst_a, lst_b);
	pb(lst_a, lst_b);
	*count += 2;
	while (lst_a->len > 3)
	{
		node = lst_a->first->next;
		moove = ft_check_nb_moove(1, ft_find_target(lst_a->first->value, lst_b) \
		, lst_a->len, lst_b->len);
		while (node && ++i)
		{
			tmpmoove = ft_check_nb_moove(i, ft_find_target(node->value, lst_b) \
			, lst_a->len, lst_b->len);
			if (tmpmoove.total < moove.total)
				moove = tmpmoove;
			node = node->next;
		}
		i = 1;
		ft_push_a(lst_a, lst_b, moove, count);
	}
}

int	main(int argc, char **argv)
{
	t_D_list	lsts;
	static int	count;

	if (argc == 1)
		return (1);
	count = 0;
	lsts.lst_a = ft_new_list();
	lsts.lst_b = ft_new_list();
	if (!ft_init_a(lsts.lst_a, argc, argv))
		return (0);
	if (ft_check_tri(lsts.lst_a))
		return (0);
	if (lsts.lst_a->len <= 4)
		ft_tri4(&lsts, &count);
	else
	{
		ft_turk_algo(lsts.lst_a, lsts.lst_b, &count);
		ft_tri3(lsts.lst_a, &count);
		ft_merge(lsts.lst_a, lsts.lst_b, &count);
	}
	ft_freelst(lsts.lst_a);
	free(lsts.lst_b);
}
