/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:28:01 by evella            #+#    #+#             */
/*   Updated: 2024/01/24 21:09:01 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_Dlist	*ft_new_list(void)
{
	t_Dlist *list;

	list = (t_Dlist *)ft_calloc(sizeof(*list), 1);
	list->first = NULL;
	list->last = NULL;
	list->len = 0;
	return(list);
}

void	ft_add_back(t_Dlist *list, int value)
{
	t_Dlist_node *node;

	node = (t_Dlist_node *)ft_calloc(sizeof(*node), 1);
	node->value = value;
	if(list->len == 0)
	{
		node->back = NULL;
		list->first = node;
	}
	else
	{
		node->back = list->last;
		list->last->next = node;
	}
	list->last = node;
	node->next = NULL;
	list->len++;
}

void	ft_add_front(t_Dlist *list, int value)
{
	t_Dlist_node *node;

	node = (t_Dlist_node *)ft_calloc(sizeof(*node), 1);
	node->value = value;
	if(list->len == 0)
	{
		node->next = NULL;
		list->last = node;
	}
	else
	{
		node->next = list->first;
		list->first->back = node;
	}
	list->first = node;
	node->back = NULL;
	list->len++;
}
int	ft_check_double(t_Dlist *lst)
{
	t_Dlist_node	*tmpnode;
	t_Dlist_node	*node;

	node = lst->first;
	while(node)
	{
		tmpnode = node->next;
		while (tmpnode)
		{
			if (node->value == tmpnode->value)
				return (1);
			tmpnode = tmpnode->next;
		}
		node = node->next;
	}
	return (0);
}

int	ft_init_a(t_Dlist *lst, int argc, char **argv)
{
	int	i;
	int	j;
	char **tab;


	i = 1;
	j = 0;
	while (i < argc)
	{
		tab = ft_split(argv[i], ' ');
		while(tab[j])
		{
			ft_add_back(lst, ft_atoi(tab[j]));
			j++;
		}
		j = 0;
		i++;
	}
	if(ft_check_double(lst))
		return (0);
	return (1);
}
