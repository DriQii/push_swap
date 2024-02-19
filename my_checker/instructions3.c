/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:28:12 by evella            #+#    #+#             */
/*   Updated: 2024/02/19 18:45:58 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ss(t_Dlist *lst_a, t_Dlist *lst_b)
{
	sa(lst_a);
	sb(lst_b);
}

void	rr(t_Dlist *lst_a, t_Dlist *lst_b)
{
	ra(lst_a);
	rb(lst_b);
}

void	rrr(t_Dlist *lst_a, t_Dlist *lst_b)
{
	rra(lst_a);
	rrb(lst_b);
}

int	ft_check_int(char *str)
{
	long	nb;

	nb = atol(str);
	if (nb < -2147483648 || nb > 2147483647)
		return (0);
	return (1);
}

int	ft_check_instructions(char *str)
{
	if (ft_strcmp(str, "pa") == 0)
		return (1);
	else if (ft_strcmp(str, "pb") == 0)
		return (1);
	else if (ft_strcmp(str, "sa") == 0)
		return (1);
	else if (ft_strcmp(str, "sb") == 0)
		return (1);
	else if (ft_strcmp(str, "ss") == 0)
		return (1);
	else if (ft_strcmp(str, "ra") == 0)
		return (1);
	else if (ft_strcmp(str, "rb") == 0)
		return (1);
	else if (ft_strcmp(str, "rr") == 0)
		return (1);
	else if (ft_strcmp(str, "rra") == 0)
		return (1);
	else if (ft_strcmp(str, "rrb") == 0)
		return (1);
	else if (ft_strcmp(str, "rrr") == 0)
		return (1);
	else
		return (0);
}
