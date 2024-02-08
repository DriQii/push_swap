/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:28:12 by evella            #+#    #+#             */
/*   Updated: 2024/02/07 19:38:06 by evella           ###   ########.fr       */
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
