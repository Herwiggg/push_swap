#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				nbr;
	int				rank;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;


/*-------??????-------*/
int					ft_count_words(const char *s, char c);
char				**ft_strcpy(char **tab, const char *s, char c);
char				**ft_doublefree(char **tab, int k);
char				**ft_split(char const *s, char c);

/*-------Error handling-------*/
long long			ft_atoi(const char *nptr);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_check_nbrs(char *str);
int					ft_check_int(char *str);
int					ft_check_doubles(char **argv);
int					ft_check_error(int argc, char **argv);
int					ft_is_already_sorted(char **argv);

/*-------Lists-------*/
t_list				*ft_lstnew(int nbr);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_free_list(t_list **list);
void				stack_init(t_list **list, char **argv);

/*-------Commands-------*/
void	ft_sa_sb(t_list **list);
void	ft_ss(t_list **a, t_list **b);
void	ft_pa_pb(t_list **list);
void	ft_ra_rb(t_list **list);
void	ft_rr(t_list **a, t_list **b);
void	ft_rra_rrb(t_list **list);
void	ft_rrr(t_list **a, t_list **b);

#endif
