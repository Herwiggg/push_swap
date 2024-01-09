#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

int			ft_count_words(const char *s, char c);
char		**ft_strcpy(char **tab, const char *s, char c);
char		**ft_doublefree(char **tab, int k);
char		**ft_split(char const *s, char c);
long long	ft_atoi(const char *nptr);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_check_nbrs(char *str);
int			ft_check_int(char *str);
int			ft_check_doubles(char **argv);
int			ft_check_error(int argc, char **argv);

#endif
