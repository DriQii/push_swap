/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:29:43 by evella            #+#    #+#             */
/*   Updated: 2024/02/08 20:49:39 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	*ft_freetabtab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free (tab);
	return (NULL);
}
