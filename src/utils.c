/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:29:43 by evella            #+#    #+#             */
/*   Updated: 2024/01/19 13:40:27 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_lst(t_Dlist *lstA, t_Dlist *lstB)
{
	t_Dlist_node	*nodeA;
	t_Dlist_node	*nodeB;

	nodeA = lstA->first;
	nodeB = lstB->first;
	while (nodeA || nodeB)
	{
		if (nodeA && !nodeB)
		{
			ft_printf("%d  |\n", nodeA->value);
			nodeA = nodeA->next;
		}
		else if (!nodeA && nodeB)
		{
			ft_printf("    |  %d\n", nodeB->value);
			nodeB = nodeB->next;
		}
		else
		{
			ft_printf("%d  |", nodeA->value);
			ft_printf("  %d\n", nodeB->value);
			nodeA = nodeA->next;
			nodeB = nodeB->next;
		}
	}
}

void	ft_del_front(t_Dlist *lst)
{
	t_Dlist_node *tmp;

	if(!lst->first->next)
	{
		free(lst->first);
		lst->first = NULL;
		lst->last = NULL;
		lst->len = 0;

	}
	else
	{
		tmp = lst->first;
		lst->first = lst->first->next;
		lst->first->back = NULL;
		free(tmp);
		lst->len--;
	}
}

void	ft_del_back(t_Dlist *lst)
{
	t_Dlist_node *tmp;

	if(!lst->last->back)
	{
		free(lst->first);
		lst->first = NULL;
		lst->last = NULL;
		lst->len = 0;

	}
	else
	{
		tmp = lst->last;
		lst->last = lst->last->back;
		lst->last->next = NULL;
		free(tmp);
		lst->len--;
	}
}
