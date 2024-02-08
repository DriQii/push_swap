/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:32:09 by evella            #+#    #+#             */
/*   Updated: 2024/02/08 04:40:46 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <../libft/libft.h>

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

void	sa(t_Dlist *lst_a, int print);
void	sb(t_Dlist *lst_b, int print);
void	ss(t_Dlist *lst_a, t_Dlist *lst_b);
void	pa(t_Dlist *lst_a, t_Dlist *lst_b);
void	pb(t_Dlist *lst_a, t_Dlist *lst_b);
void	ra(t_Dlist *lst_a, int print);
void	rb(t_Dlist *lst_b, int print);
void	rr(t_Dlist *lst_a, t_Dlist *lst_b);
void	rra(t_Dlist *lst_a, int print);
void	rrb(t_Dlist *lst_b, int print);
void	rrr(t_Dlist *lst_a, t_Dlist *lst_b);

t_Dlist	*ft_new_list(void);
t_op	ft_check_nb_moove(int current, int target \
, int lstlen, int lst_target_len);
void	ft_print_lst(t_Dlist *lst_a, t_Dlist *lst_b);
void	ft_add_front(t_Dlist *list, int value);
void	ft_add_back(t_Dlist *list, int value);
void	ft_del_front(t_Dlist *lst);
void	ft_del_back(t_Dlist *lst);
void	ft_merge(t_Dlist *lst_a, t_Dlist *lst_b, int *count);
void	ft_push_b(t_Dlist *lst_a, t_Dlist *lst_b, t_op op, int *count);
void	ft_push_a(t_Dlist *lst_a, t_Dlist *lst_b, t_op op, int *count);
void	ft_last_rotate(t_Dlist *lst_a, int *count);
void	ft_tri3(t_Dlist *lst_a, int *count);
int		ft_init_a(t_Dlist *lst, int argc, char **argv);
int		ft_find_target_b(int value, t_Dlist *lst);
int		ft_find_target(int value, t_Dlist *lst);
int		ft_check_tri_rev(t_Dlist *lst_b);
int		ft_check_tri(t_Dlist *lst_a);
void	ft_state_3(int *state, t_op *op, int *count, int lstlen);
void	ft_state_2(int *state, t_op *op, int *count);
void	ft_state(int *state, t_op *op, int *count, int lst_target_len);
void	ft_last_moove_2(int *state, t_op *op, int lstlen, int lst_target_len);
void	ft_last_moove(int *state, t_op *op, int lstlen, int lst_target_len);
t_op	ft_set_op(int target, int current);
void	ft_first_moove(t_op *op, int lst_target_len, int lstlen);
void	ft_end_moove(t_op *op);

#endif
