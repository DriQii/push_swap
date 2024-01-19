/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:27:55 by evella            #+#    #+#             */
/*   Updated: 2024/01/19 13:50:17 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_Dlist *lstA;
	t_Dlist *lstB;

	lstA = ft_new_list();
	lstB = ft_new_list();
	ft_init_a(lstA, argc, argv);
	ft_print_lst(lstA,lstB);
}
