/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_moove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 03:17:35 by evella            #+#    #+#             */
/*   Updated: 2024/02/08 03:18:09 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_last_moove(int *state, t_op *op, int lstlen, int lst_target_len)
{
	if (*state == 1)
	{
		op->r_target = op->target - 1;
		op->r_current = op->current - 1;
		op->rr_target = 0;
		op->rr_current = 0;
	}
	else if (*state == 2)
	{
		op->rr_current = lstlen - op->current + 1;
		op->rr_target = lst_target_len - op->target + 1;
		op->r_current = 0;
		op->r_target = 0;
	}
}

void	ft_last_moove_2(int *state, t_op *op, int lstlen, int lst_target_len)
{
	if (*state == 3)
	{
		op->r_current = op->current - 1;
		op->r_target = op->target - 1;
		op->rr_current = 0;
		op->rr_target = 0;
	}
	else if (*state == 4)
	{
		op->rr_target = lst_target_len - op->target + 1;
		op->rr_current = lstlen - op->current + 1;
		op->r_target = 0;
		op->r_current = 0;
	}
}

void	ft_state(int *state, t_op *op, int *count, int lst_target_len)
{
	if (*state != -1)
	{
		if (lst_target_len - op->target + 1 < *count)
		{
			*count = lst_target_len - op->target + 1;
			*state = 2;
		}
	}
	else
	{
		*count = lst_target_len - op->target + 1;
		*state = 2;
	}
}

void	ft_state_2(int *state, t_op *op, int *count)
{
	if (*state != -1)
	{
		if (op->current - 1 < *count)
		{
			*count = op->current - 1;
			*state = 3;
		}
	}
	else
	{
		*count = op->current - 1;
		*state = 3;
	}
}

void	ft_state_3(int *state, t_op *op, int *count, int lstlen)
{
	if (*state != -1)
	{
		if (lstlen - op->current + 1 < *count)
			*state = 4;
	}
	else
		*state = 4;
}
