/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:28:12 by evella            #+#    #+#             */
/*   Updated: 2024/02/15 23:18:57 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_Dlist *lst_a, t_Dlist *lst_b)
{
	sa(lst_a, 0);
	sb(lst_b, 0);
	ft_putstr("ss\n");
}

void	rr(t_Dlist *lst_a, t_Dlist *lst_b)
{
	ra(lst_a, 0);
	rb(lst_b, 0);
	ft_putstr("rr\n");
}

void	rrr(t_Dlist *lst_a, t_Dlist *lst_b)
{
	rra(lst_a, 0);
	rrb(lst_b, 0);
	ft_putstr("rrr\n");
}

void	ft_tri4(t_D_list *lsts, int *count)
{
	if (lsts->lst_a->len == 4)
	{
		pb(lsts->lst_a, lsts->lst_b);
		ft_tri3(lsts->lst_a, count);
		ft_merge(lsts->lst_a, lsts->lst_b, count);
	}
	else if (lsts->lst_a->len == 3)
		ft_tri3(lsts->lst_a, count);
	else if (lsts->lst_a->len == 2)
		sa(lsts->lst_a, 1);
}

int	ft_check_int(char *str)
{
	long	nb;

	nb = atol(str);
	if (nb < -2147483648 || nb > 2147483647)
		return (0);
	return (1);
}
