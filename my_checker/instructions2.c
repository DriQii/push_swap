/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:53:53 by evella            #+#    #+#             */
/*   Updated: 2024/02/19 18:55:48 by evella           ###   ########.fr       */
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

char	*ft_trim_output(char *str)
{
	char		*op;
	char		*tmp;

	if (str)
		free(str);
	op = get_next_line(0);
	tmp = op;
	if (op)
	{
		op = ft_strtrim(op, "\n");
		free(tmp);
	}
	return (op);
}
