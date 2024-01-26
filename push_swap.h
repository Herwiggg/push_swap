#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	int				nbr;
	int				rank;
	int				push_price;
	int				mediane;
	int				cheapest;
	int				smallest;
	struct s_list	*target_node;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

void read_list(t_list *start_a, t_list *start_b);
/*-------Error handling-------*/
long long			ft_atoi(const char *nptr);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_check_nbrs(char *str);
int					ft_check_int(char *str);
int					ft_check_doubles(char **argv);
int					ft_check_error(int argc, char **argv);
int					ft_is_already_sorted(char **argv);
int					ft_count_tabs(char **tab);

/*-------Lists & parsing-------*/
t_list				*ft_lstnew(int nbr);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_free_list(t_list **list);
void				stack_init(t_list **list, char **argv);
int					ft_count_words(const char *s, char c);
char				**ft_strcpy(char **tab, const char *s, char c);
char				**ft_doublefree(char **tab, int k);
char				**ft_split(char const *s, char c);
int					stack_len(t_list **list);
t_list				*biggest_node(t_list **list);

/*-------Commands-------*/
int					ft_sa_sb(t_list **list, int flag);
void				ft_ss(t_list **a, t_list **b);
int					ft_pa(t_list **a, t_list **b);
int					ft_pb(t_list **a, t_list **b);
int					ft_ra_rb(t_list **list, int flag);
void				ft_rr(t_list **a, t_list **b);
int					ft_rra_rrb(t_list **list, int flag);
void				ft_rrr(t_list **a, t_list **b);

/*-------Algo-------*/
void				tiny_sort(t_list **a);
void				big_sort(t_list **a, t_list **b);
/*! : init nodes*/
void				ft_push_to_b(t_list **a, t_list **b);
void				*find_target_node(t_list **a, t_list **b);
t_list				*the_smallest_node_in_a(t_list **a);
int					list_len(t_list **list);
void				insert_mediane(t_list **list, int mediane_pos);
void				refreshing_rank_and_mediane(t_list **list);
void				set_price(t_list **a, t_list **b);
void				find_the_cheapest(t_list **b);
t_list				*find_the_smallest(t_list **a);
/*2 : move nodes*/
t_list				*return_cheapest(t_list **b);
void				move_nodes(t_list **a, t_list **b);
void				rotate_both(t_list **a, t_list **b, t_list *cheapest_node);
void				reverse_rotate_both(t_list **a, t_list **b,
						t_list *cheapest_node);
void				finish_rotation(t_list **list, t_list *top_node, int flag);

#endif