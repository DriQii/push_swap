/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:53:53 by evella            #+#    #+#             */
/*   Updated: 2024/02/08 20:56:45 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_Dlist *lst_a)
{
	if (lst_a->first)
	{
		ft_add_back(lst_a, lst_a->first->value);
		ft_del_front(lst_a);
	}
}

void	rb(t_Dlist *lst_b)
{
	if (lst_b->first)
	{
		ft_add_back(lst_b, lst_b->first->value);
		ft_del_front(lst_b);
	}
}

void	rra(t_Dlist *lst_a)
{
	if (lst_a->first)
	{
		ft_add_front(lst_a, lst_a->last->value);
		ft_del_back(lst_a);
	}
}

void	rrb(t_Dlist *lst_b)
{
	if (lst_b->first)
	{
		ft_add_front(lst_b, lst_b->last->value);
		ft_del_back(lst_b);
	}
}
