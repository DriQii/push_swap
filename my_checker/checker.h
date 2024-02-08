/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:46:29 by evella            #+#    #+#             */
/*   Updated: 2024/02/08 20:50:43 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"

typedef struct s_Dlist_node
{
	int					value;
	struct s_Dlist_node	*back;
	struct s_Dlist_node	*next;
}				t_Dlist_node;

typedef struct s_Dlist
{
	int					len;
	struct s_Dlist_node	*first;
	struct s_Dlist_node	*last;
}				t_Dlist;

typedef struct s_D_list
{
	t_Dlist		*lst_a;
	t_Dlist		*lst_b;
}				t_D_list;

typedef struct s_index
{
	int	i;
	int	j;
}				t_index;

typedef struct s_target
{
	int				best;
	int				max;
	int				res;
	int				tmpres;
	int				maxvalue;
}				t_target;

typedef struct s_op
{
	int	r_current;
	int	rr_current;
	int	r_target;
	int	rr_target;
	int	total;
	int	target;
	int	current;
	int	lstlen;
	int	i;
}				t_op;

void	sa(t_Dlist *lst_a);
void	sb(t_Dlist *lst_b);
void	ss(t_Dlist *lst_a, t_Dlist *lst_b);
void	pa(t_Dlist *lst_a, t_Dlist *lst_b);
void	pb(t_Dlist *lst_a, t_Dlist *lst_b);
void	ra(t_Dlist *lst_a);
void	rb(t_Dlist *lst_b);
void	rr(t_Dlist *lst_a, t_Dlist *lst_b);
void	rra(t_Dlist *lst_a);
void	rrb(t_Dlist *lst_b);
void	rrr(t_Dlist *lst_a, t_Dlist *lst_b);

t_Dlist	*ft_new_list(void);
t_op	ft_check_nb_moove(int current, int target \
, int lstlen, int lst_target_len);
void	ft_print_lst(t_Dlist *lst_a, t_Dlist *lst_b);
void	ft_add_front(t_Dlist *list, int value);
void	ft_add_back(t_Dlist *list, int value);
void	ft_del_front(t_Dlist *lst);
void	ft_del_back(t_Dlist *lst);
int		ft_init_a(t_Dlist *lst, int argc, char **argv);
int		ft_check_tri(t_Dlist *lst_a);
void	*ft_freetabtab(char **tab);

#endif
