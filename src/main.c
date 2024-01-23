/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:27:55 by evella            #+#    #+#             */
/*   Updated: 2024/01/23 11:06:31 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_tri3(t_Dlist *lstA)
{
	if (lstA->first->value > lstA->first->next->value
	&& lstA->first->next->value > lstA->first->next->next->value)
	{
		sa(lstA);
		rra(lstA);
	}
	else if (lstA->first->value > lstA->first->next->value
	&& lstA->first->next->value < lstA->first->next->next->value
	&& lstA->first->next->next->value > lstA->first->next->value)
		sa(lstA);
	else if (lstA->first->value > lstA->first->next->value
	&& lstA->first->next->value < lstA->first->next->next->value
	&& lstA->first->next->next->value < lstA->first->next->value)
		ra(lstA);
	else if (lstA->first->value < lstA->first->next->value
	&& lstA->first->next->value > lstA->first->next->next->value
	&& lstA->first->next->next->value > lstA->first->next->value)
	{
		sa(lstA);
		ra(lstA);
	}
	else if (lstA->first->value < lstA->first->next->value
	&& lstA->first->next->value > lstA->first->next->next->value
	&& lstA->first->next->next->value < lstA->first->next->value)
		rra(lstA);
}


void	ft_find_median_node(t_Dlist_node *node, t_median *median)
{
	while (node)
	{
		median->tmpfind = median->res - median->find;
		if(median->tmpfind < 0)
			median->tmpfind *= -1;
		median->tmp = median->res - node->value;
		if(median->tmp < 0)
			median->tmp *= -1;
		if(median->tmp < median->tmpfind)
			median->find = node->value;
		node = node->next;
	}
}

int	ft_find_median(t_Dlist *lst)
{
	t_Dlist_node	*node;
	t_median		median;
	int				i;

	i = 0;
	node = lst->first;
	median.first = lst->first->value;
	median.last = lst->last->value;
	median.find = lst->first->value;
	if(lst->len > 7)
	{
		while (i++ < lst->len / 4)
			node = node->next;
		median.mid1 = node->value;
		while (i++ < (lst->len / 4) * 2)
			node = node->next;
		median.mid1 +=node->value;
		while (i++ < (lst->len / 4 * 3))
			node = node->next;
		median.mid1 += node->value;
	}
	else if (lst->len > 3)
	{
		while (i++ < lst->len / 2)
			node = node->next;
		median.mid1 = node->value * 3;

	}
	else if(lst->len > 1)
		median.mid1 = node->next->value * 3;

	//printf("\n\n calc [%d]\n\n", (median.first + median.first + median.mid1 + 5) / 5);
	median.res = (median.first + median.first + median.mid1) / 5;
	node = lst->first;
	ft_find_median_node(node, &median);
	return (median.find);
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
			return(0);
	}
	return(1);
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
			return(0);
	}
	return(1);
}

void	ft_split_lstA(t_Dlist *lstA, t_Dlist *lstB)
{
	int				median;
	int				len;

	len = lstA->len;
	median = ft_find_median(lstA);
	while(len != 1 && !ft_check_tri(lstA))
	{
		ft_print_lst(lstA, lstB);
		printf("\nlen = %d\n", lstA->len);
		if (lstA->len == 3)
			ft_tri3(lstA);
		else if(lstA->len > 3)
		{
			/* if(lstA->first->next->value < lstA->first->value)
					sa(lstA); */
			if(lstA->first->value < median)
				pb(lstA, lstB);
			else
				ra(lstA);
			len--;
		}


		//printf("\nmedian%d\n", median);
	}
}

void	ft_split_lstB(t_Dlist *lstA, t_Dlist *lstB)
{
	t_Dlist_node	*node;
	int				median;
	int				len;

	len = lstB->len;
	node = lstB->first;
	median = ft_find_median(lstB);

	while(len != 0)
	{
		if(lstB->first->value >= median)
			pa(lstA, lstB);
		else
			rb(lstB);
		len--;
	}
	if(lstB->len <= 2 && lstB->len != 0)
	{
		/* if(lstB->first->next)
			if(lstB->first->next->value > lstB->first->value)
					sb(lstB); */
		pa(lstA, lstB);
	}
	printf("b len %d\n", lstB->len);
}

int	main(int argc, char **argv)
{
	t_Dlist *lstA;
	t_Dlist *lstB;

	lstA = ft_new_list();
	lstB = ft_new_list();
	ft_init_a(lstA, argc, argv);
 	/* while(!ft_check_tri(lstA))
	{
		while (lstA->len > 1 && !ft_check_tri(lstA))
			ft_split_lstA(lstA, lstB);
		while (lstB->len > 1 && ft_check_tri_rev(lstB))
			ft_split_lstB(lstA, lstB);
		ft_join_lst(lstA, lstB);
	} */
	//ft_print_lst(lstA, lstB);
	 while(!ft_check_tri(lstA))
	{
		while(lstA->len > 1 && !ft_check_tri(lstA))
			ft_split_lstA(lstA, lstB);
		while(lstB->len != 0)
			ft_split_lstB(lstA, lstB);
		//ft_print_lst(lstA, lstB);
	}
	//ft_print_lst(lstA, lstB);

}


