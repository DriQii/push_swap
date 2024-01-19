/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:28:12 by evella            #+#    #+#             */
/*   Updated: 2024/01/19 13:43:19 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_Dlist *lstA, t_Dlist *lstB)
{
	sa(lstA);
	sb(lstB);
	ft_printf("ss\n");
}

void	rr(t_Dlist *lstA, t_Dlist *lstB)
{
	ra(lstA);
	rb(lstB);
	ft_printf("rr\n");
}

void	rrr(t_Dlist *lstA, t_Dlist *lstB)
{
	rra(lstA);
	rrb(lstB);
	ft_printf("rrr\n");
}
