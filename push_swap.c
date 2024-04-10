/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:36:42 by almichel          #+#    #+#             */
/*   Updated: 2024/04/11 00:09:06 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort(t_list **a)
{
	t_list	*highest_node;
	t_list	*head_a;

	highest_node = biggest_node(a);
	head_a = *a;
	if (head_a == highest_node)
		ft_ra_rb(a, 1);
	else if (head_a->next == highest_node)
		ft_rra_rrb(a, 1);
	if ((*a)->nbr > (*a)->next->nbr)
		ft_sa_sb(a, 1);
}

void	big_sort(t_list **a, t_list **b)
{
	t_list	*the_smallest;

	ft_push_to_b(a, b);
	tiny_sort(a);
	while (*b != NULL)
	{
		find_target_node(a, b);
		refreshing_rank_and_mediane(a);
		refreshing_rank_and_mediane(b);
		set_price(a, b);
		find_the_cheapest(b);
		move_nodes(a, b);
	}
	refreshing_rank_and_mediane(a);
	the_smallest = find_the_smallest(a);
	if (the_smallest->mediane == 0)
		while (*a != the_smallest)
			ft_ra_rb(a, 1);
	else
		while (*a != the_smallest)
			ft_rra_rrb(a, 1);
}

void	push_swap(t_list **a, char **argv, int split_flag)
{
	t_list	*b;

	b = NULL;
	stack_init(a, argv, split_flag);
	if (stack_len(a) == 2)
		ft_sa_sb(a, 1);
	else if (stack_len(a) == 3)
		tiny_sort(a);
	else
		big_sort(a, &b);
	ft_free_list(a);
}

void	start(char **argv, int split_flag, t_list *a, int argc)
{
	if (ft_check_error(argv, split_flag) == -1)
	{
		if (argc == 2)
			ft_doublefree(argv, ft_count_tabs(argv));
		return ;
	}
	if (ft_is_already_sorted(argv, split_flag) != -1)
	{
		push_swap(&a, argv, split_flag);
		if (argc == 2)
			ft_doublefree(argv, ft_count_tabs(argv));
	}
	else if (split_flag == 1)
		ft_doublefree(argv, ft_count_tabs(argv));
}

int	main(int argc, char **argv)
{
	t_list	*a;
	int		split_flag;

	a = NULL;
	split_flag = 0;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!(argv))
			return (1);
		split_flag = 1;
	}
	start(argv, split_flag, a, argc);
}
