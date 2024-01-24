#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <../libft/libft.h>

typedef struct	s_Dlist_node
{
	int	value;
	struct s_Dlist_node *back;
	struct s_Dlist_node *next;
}				t_Dlist_node;

typedef struct	s_Dlist
{
	int	len;
	struct s_Dlist_node *first;
	struct s_Dlist_node *last;
}				t_Dlist;

typedef struct	s_index
{
	int	i;
	int	j;
}				t_index;

typedef struct	s_target
{
	int				best;
	int				max;
	int				res;
	int				tmpres;
	int				maxvalue;
}				t_target;

typedef struct	s_op
{
	int	r_current;
	int	rr_current;
	int	r_target;
	int	rr_target;
	int	total;
	int	target;
	int	current;
}				t_op;

void	sa(t_Dlist *lstA, int print);
void	sb(t_Dlist *lstB, int print);
void	ss(t_Dlist *lstA, t_Dlist *lstB);
void	pa(t_Dlist *lstA, t_Dlist *lstB);
void	pb(t_Dlist *lstA, t_Dlist *lstB);
void	ra(t_Dlist *lstA, int print);
void	rb(t_Dlist *lstB, int print);
void	rr(t_Dlist *lstA, t_Dlist *lstB);
void	rra(t_Dlist *lstA, int print);
void	rrb(t_Dlist *lstB, int print);
void	rrr(t_Dlist *lstA, t_Dlist *lstB);

t_Dlist	*ft_new_list(void);
t_op	ft_check_nb_moove(int current, int target, int lstlen, int lst_target_len);

void	ft_print_lst(t_Dlist *lstA, t_Dlist *lstB);
void	ft_add_front(t_Dlist *list, int value);
void	ft_add_back(t_Dlist *list, int value);
void	ft_del_front(t_Dlist *lst);
void	ft_del_back(t_Dlist *lst);
void	ft_merge(t_Dlist *lstA, t_Dlist *lstB, int *count);
void	ft_pushB(t_Dlist *lstA, t_Dlist *lstB, t_op op,int *count);
void	ft_pushA(t_Dlist *lstA, t_Dlist *lstB, t_op op,int *count);
void	ft_last_rotate(t_Dlist *lstA, int *count);
void	ft_tri3(t_Dlist *lstA , int *count);
int		ft_init_a(t_Dlist *lst, int argc, char **argv);
int		ft_find_targetB(int	value, t_Dlist *lst);
int		ft_find_target(int	value, t_Dlist *lst);
int		ft_check_tri_rev(t_Dlist *lstB);
int		ft_check_tri(t_Dlist *lstA);


#endif
