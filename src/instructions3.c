/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:28:12 by evella            #+#    #+#             */
/*   Updated: 2024/01/24 21:31:44 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_Dlist *lstA, t_Dlist *lstB)
{
	sa(lstA, 0);
	sb(lstB, 0);
	ft_putstr("ss\n");
}

void	rr(t_Dlist *lstA, t_Dlist *lstB)
{
	ra(lstA, 0);
	rb(lstB, 0);
	ft_putstr("rr\n");
}

void	rrr(t_Dlist *lstA, t_Dlist *lstB)
{
	rra(lstA, 0);
	rrb(lstB, 0);
	ft_putstr("rrr\n");
}
