/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:29:43 by evella            #+#    #+#             */
/*   Updated: 2024/02/07 19:49:31 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	ft_print_lst(t_Dlist *lst_a, t_Dlist *lst_b)
{
	t_Dlist_node	*nodeA;
	t_Dlist_node	*nodeB;

	nodeA = lst_a->first;
	nodeB = lst_b->first;
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
	printf("\n\n");
} */

void	ft_del_front(t_Dlist *lst)
{
	t_Dlist_node	*tmp;

	if (!lst->first->next)
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
	t_Dlist_node	*tmp;

	if (!lst->last->back)
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

int	ft_check_tri(t_Dlist *lst_a)
{
	t_Dlist_node	*node;
	int				tmp;

	node = lst_a->first;
	while (node->next)
	{
		tmp = node->value;
		node = node->next;
		if (node->value < tmp)
			return (0);
	}
	return (1);
}

int	ft_check_tri_rev(t_Dlist *lst_b)
{
	t_Dlist_node	*node;
	int				tmp;

	node = lst_b->first;
	while (node->next)
	{
		tmp = node->value;
		node = node->next;
		if (node->value > tmp)
			return (0);
	}
	return (1);
}
