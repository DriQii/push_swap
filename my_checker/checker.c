/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:48:49 by evella            #+#    #+#             */
/*   Updated: 2024/02/13 16:16:07 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_check(t_D_list *lsts, char *op)
{
	if (op[0] == 's')
	{
		if (op[1] == 'a')
			sa(lsts->lst_a);
		else if (op[1] == 'b')
			sb(lsts->lst_b);
		else
			ss(lsts->lst_a, lsts->lst_b);
	}
}

void	rotate_check(t_D_list *lsts, char *op)
{
	if (op[0] == 'r')
	{
		if (op[1] == 'r')
		{
			if (op[2] == 'a')
				rra(lsts->lst_a);
			else if (op[2] == 'b')
				rrb(lsts->lst_b);
			else if (op[2] == 'r')
				rrr(lsts->lst_a, lsts->lst_b);
			else
				rr(lsts->lst_a, lsts->lst_b);
		}
		else if (op[1] == 'a')
			ra(lsts->lst_a);
		else if (op[1] == 'b')
			rb(lsts->lst_b);
	}
}

void	push_check(t_D_list *lsts, char *op)
{
	if (op[0] == 'p')
	{
		if (op[1] == 'a')
			pa(lsts->lst_a, lsts->lst_b);
		else if (op[1] == 'b')
			pb(lsts->lst_a, lsts->lst_b);
	}
}

void	ft_freelst(t_Dlist *lst)
{
	t_Dlist_node	*tmp;

	while (lst->first)
	{
		tmp = lst->first;
		lst->first = lst->first->next;
		free(tmp);
	}
	free(lst);
}

int	main(int argc, char **argv)
{
	t_D_list	lsts;
	char		*op;

	if (argc == 1)
		return (1);
	lsts.lst_a = ft_new_list();
	if (!ft_init_a(lsts.lst_a, argc, argv))
		return (ft_freelst(lsts.lst_a), 0);
	lsts.lst_b = ft_new_list();
	op = get_next_line(0);
	while (op)
	{
		swap_check(&lsts, op);
		rotate_check(&lsts, op);
		push_check(&lsts, op);
		free(op);
		op = get_next_line(0);
	}
	if (ft_check_tri(lsts.lst_a) && lsts.lst_b->len == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_freelst(lsts.lst_a);
	free(lsts.lst_b);
}
