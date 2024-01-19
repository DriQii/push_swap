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

void	sa(t_Dlist *lstA);
void	sb(t_Dlist *lstB);
void	ss(t_Dlist *lstA, t_Dlist *lstB);
void	pa(t_Dlist *lstA, t_Dlist *lstB);
void	pb(t_Dlist *lstA, t_Dlist *lstB);
void	ra(t_Dlist *lstA);
void	rb(t_Dlist *lstB);
void	rr(t_Dlist *lstA, t_Dlist *lstB);
void	rra(t_Dlist *lstA);
void	rrb(t_Dlist *lstB);
void	rrr(t_Dlist *lstA, t_Dlist *lstB);

t_Dlist	*ft_new_list(void);
void	ft_init_a(t_Dlist *lst, int argc, char **argv);
void	ft_print_lst(t_Dlist *lstA, t_Dlist *lstB);
void	ft_add_front(t_Dlist *list, int value);
void	ft_add_back(t_Dlist *list, int value);
void	ft_del_front(t_Dlist *lst);
void	ft_del_back(t_Dlist *lst);

#endif
