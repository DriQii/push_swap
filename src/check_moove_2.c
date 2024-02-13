/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_moove_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 03:19:35 by evella            #+#    #+#             */
/*   Updated: 2024/02/12 15:14:34 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_end_moove(t_op *op)
{
	if (op->r_current > op->r_target)
		op->total = op->r_current;
	else
		op->total = op->r_target;
	if (op->rr_current > op->rr_target)
		op->total += op->rr_current;
	else
		op->total += op->rr_target;
}

void	ft_first_moove(t_op *op, int lst_target_len, int lstlen)
{
	if (op->current <= lstlen / 2)
		op->r_current = op->current - 1;
	else
		op->rr_current = lstlen - op->current + 1;
	if (op->target <= lst_target_len / 2)
		op->r_target = op->target - 1;
	else
		op->rr_target = lst_target_len - op->target + 1;
}

t_op	ft_set_op(int target, int current)
{
	t_op	op;

	op.r_current = 0;
	op.rr_current = 0;
	op.r_target = 0;
	op.rr_target = 0;
	op.target = target;
	op.current = current;
	return (op);
}
