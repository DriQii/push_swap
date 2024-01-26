/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:27:55 by evella            #+#    #+#             */
/*   Updated: 2024/01/26 21:53:17 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_tri3(t_Dlist *lstA , int *count)
{
	if (lstA->first->value > lstA->first->next->value
	&& lstA->first->next->value > lstA->first->next->next->value)
	{
		sa(lstA, 1);
		rra(lstA, 1);
		*count += 1;
	}
	else if (lstA->first->value > lstA->first->next->value
	&& lstA->first->next->value < lstA->first->next->next->value
	&& lstA->first->next->next->value > lstA->first->value)
		sa(lstA, 1);
	else if (lstA->first->value > lstA->first->next->value
	&& lstA->first->next->value < lstA->first->next->next->value
	&& lstA->first->next->next->value < lstA->first->value)
		ra(lstA, 1);
	else if (lstA->first->value < lstA->first->next->value
	&& lstA->first->next->value > lstA->first->next->next->value
	&& lstA->first->next->next->value > lstA->first->value)
	{
		sa(lstA, 1);
		ra(lstA, 1);
		*count += 1;
	}
	else if (lstA->first->value < lstA->first->next->value
	&& lstA->first->next->value > lstA->first->next->next->value
	&& lstA->first->next->next->value < lstA->first->value)
		rra(lstA, 1);
	*count += 1;
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

t_op	ft_check_nb_moove(int current, int target, int lstlen, int lst_target_len)
{
	t_op	op;
	int		count;
	int		state;
	int		tmp;

	state = -1;
	count = 0;
	op.r_current = 0;
	op.rr_current = 0;
	op.r_target = 0;
	op.rr_target = 0;
	op.target = target;
	op.current = current;
	if (current <= lstlen / 2)
		op.r_current = current - 1;
	else
		op.rr_current = lstlen - current + 1;
	if (target <= lst_target_len / 2)
		op.r_target = target - 1;
	else
		op.rr_target = lst_target_len - target + 1;
	tmp = op.r_current + op.rr_target + op.rr_current + op.r_target;
	if((target - 1) < tmp && op.rr_current == 0)
	{
		count = target - 1;
		state = 1;
	}
	if (lst_target_len - target + 1 < tmp && op.r_current == 0)
	{
		if (state != -1)
		{
			if(lst_target_len - target + 1 < count)
			{
				count = lst_target_len - target + 1;
				state = 2;
			}
		}
		else
		{
			count = lst_target_len - target + 1;
			state = 2;
		}
	}
	if (current - 1 < tmp && op.rr_target == 0)
	{
		if (state != -1)
		{
			if(current - 1 < count)
			{
				count = current - 1;
				state = 3;
			}
		}
		else
		{
			count = current - 1;
			state = 3;
		}
	}
	if (lstlen - current + 1 < tmp && op.r_target == 0)
	{
		if (state != -1)
		{
			if(lstlen - current + 1 < count)
				state = 4;
		}
		else
			state = 4;
	}
	if (state == 1)
	{
		op.r_target = target - 1;
		op.r_current = current - 1;
		op.rr_target = 0;
		op.rr_current = 0;
	}
	else if (state == 2)
	{
		op.rr_current = lstlen - current + 1;
		op.rr_target = lst_target_len - target + 1;
		op.r_current = 0;
		op.r_target = 0;
	}
	else if (state == 3)
	{
		op.r_current = current - 1;
		op.r_target = target - 1;
		op.rr_current = 0;
		op.rr_target = 0;
	}
	else if (state == 4)
	{
		op.rr_target = lst_target_len - target + 1;
		op.rr_current = lstlen - current + 1;
		op.r_target = 0;
		op.r_current = 0;
	}

	/* if(target - 1 < (op.r_current + op.rr_target))
	{

		op.r_target = target - 1;
		op.rr_target = 0;
	}
	else if(current - 1 < (op.rr_current + op.r_target))
	{
		op.r_current = current - 1;
		op.rr_current = 0;
	} */
	if(op.r_current > op.r_target)
		op.total = op.r_current;
	else
		op.total = op.r_target;
	if(op.rr_current > op.rr_target)
		op.total += op.rr_current;
	else
		op.total += op.rr_target;
	return (op);
}

void	ft_turk_algo(t_Dlist *lstA, t_Dlist *lstB, int *count)
{
	t_Dlist_node		*node;
	t_op				moove;
	t_op				tmpmoove;
	int					i;


	i = 2;
	pb(lstA, lstB);
	pb(lstA, lstB);
	*count += 2;
	while (lstA->len > 3)
	{
		node = lstA->first->next;
		moove = ft_check_nb_moove(1, ft_find_target(lstA->first->value, lstB), lstA->len, lstB->len);

		while(node)
		{
			tmpmoove = ft_check_nb_moove(i, ft_find_target(node->value, lstB), lstA->len, lstB->len);
			if(tmpmoove.total < moove.total)
				moove = tmpmoove;
			node = node->next;
			i++;
		}
		i = 2;
		ft_pushA(lstA, lstB, moove, count);
	}
}

int	main(int argc, char **argv)
{
	t_Dlist *lstA;
	t_Dlist *lstB;
	static int count;

	count = 0;
	lstA = ft_new_list();
	lstB = ft_new_list();
	if (!ft_init_a(lstA, argc, argv))
		return(0);
	if(ft_check_tri(lstA))
		return (0);
	//ft_print_lst(lstA, lstB);
	if (lstA->len <= 3)
	{
		if(lstA->len == 2)
			sa(lstA, 1);
		else
			ft_tri3(lstA, &count);
	}
	else
	{
		ft_turk_algo(lstA, lstB, &count);
		ft_tri3(lstA, &count);
		ft_merge(lstA, lstB, &count);
	}
	//ft_print_lst(lstA, lstB);
	//printf("count = %d\n", count);
	//printf("%d\n", ft_check_tri(lstA));
}


