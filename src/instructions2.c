/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:53:53 by evella            #+#    #+#             */
/*   Updated: 2024/02/07 19:38:04 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_Dlist *lst_a, int print)
{
	if (lst_a->first)
	{
		ft_add_back(lst_a, lst_a->first->value);
		ft_del_front(lst_a);
	}
	if (print == 1)
		ft_putstr("ra\n");
}

void	rb(t_Dlist *lst_b, int print)
{
	if (lst_b->first)
	{
		ft_add_back(lst_b, lst_b->first->value);
		ft_del_front(lst_b);
	}
	if (print == 1)
		ft_putstr("rb\n");
}

void	rra(t_Dlist *lst_a, int print)
{
	if (lst_a->first)
	{
		ft_add_front(lst_a, lst_a->last->value);
		ft_del_back(lst_a);
	}
	if (print == 1)
		ft_putstr("rra\n");
}

void	rrb(t_Dlist *lst_b, int print)
{
	if (lst_b->first)
	{
		ft_add_front(lst_b, lst_b->last->value);
		ft_del_back(lst_b);
	}
	if (print == 1)
		ft_putstr("rrb\n");
}
