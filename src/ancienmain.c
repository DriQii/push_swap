/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ancienmain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:27:55 by evella            #+#    #+#             */
/*   Updated: 2024/01/22 11:07:18 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "push_swap.h"

int	ft_find_median(t_Dlist *lst)
{
	t_index			i;
	t_Dlist_node	*node;
	int				median;
	int				tmp;
	int				tmpmedian;

	median = lst->first->value;
	i.min = lst->first->value;
	i.max = lst->first->value;
	node = lst->first;
	while(node)
	{
		if(node->value < i.min)
			i.min = node->value;
		else if (node->value > i.max)
			i.max = node->value;
		node = node->next;
	}
	node = lst->first;

	while(node)
	{
		tmp = (i.min + i.max) / 2 - node->value;
		if (tmp < 0)
				tmp *= -1;
		tmpmedian = median - (i.min + i.max) / 2;
		if (tmpmedian < 0)
				tmpmedian *= -1;
		if (tmp < tmpmedian)
			median = node->value;
		node = node->next;
	}
	return (median);
}

void	ft_split_lstA(t_Dlist *lstA, t_Dlist *lstB)
{
	t_index			i;
	int				median;

	median = ft_find_median(lstA);
	i.i = 0;
	i.len = lstA->len;
	while(i.i < i.len)
	{
		if(lstA->first->next)
			if(lstA->first->next->value < lstA->first->value)
				sa(lstA);
		if(lstA->first->value < median)
			pb(lstA, lstB);
		else
			ra(lstA);
		i.i++;
	}
 	if(lstA->len == 1)
		pb(lstA, lstB);
}

void	ft_split_lstB(t_Dlist *lstA, t_Dlist *lstB)
{
	t_index			i;
	int				median;

	median = ft_find_median(lstB);
	i.i = 0;
	i.len = lstB->len;
	while(i.i < i.len)
	{
		if(lstB->first->value > median)
			pa(lstA, lstB);
		else
			rb(lstB);
		i.i++;
	}
	if(lstB->len == 1)
		pa(lstA, lstB);
}

void	ft_join_lst(t_Dlist *lstA, t_Dlist *lstB)
{
	while(lstB->first)
		pa(lstA, lstB);
}
int	ft_check_tri(t_Dlist *lstA)
{
	t_Dlist_node	*node;
	int				tmp;

	node = lstA->first;
	while(node->next)
	{
		tmp = node->value;
		node = node->next;
		if (node->value < tmp)
			return(1);
	}
	return(0);
}

int	ft_check_tri_rev(t_Dlist *lstB)
{
	t_Dlist_node	*node;
	int				tmp;

	node = lstB->first;
	while(node->next)
	{
		tmp = node->value;
		node = node->next;
		if (node->value > tmp)
			return(1);
	}
	return(0);
}

int	main(int argc, char **argv)
{
	t_Dlist *lstA;
	t_Dlist *lstB;

	lstA = ft_new_list();
	lstB = ft_new_list();
	ft_init_a(lstA, argc, argv);
 	while(ft_check_tri(lstA) || lstB->len == 0)
	{
		while (lstA->len > 1 && ft_check_tri(lstA))
			ft_split_lstA(lstA, lstB);
		while (lstB->len > 1 && ft_check_tri_rev(lstB))
			ft_split_lstB(lstA, lstB);
		//ft_join_lst(lstA, lstB);
	}
	ft_print_lst(lstA, lstB);
} */


