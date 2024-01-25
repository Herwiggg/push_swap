/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:36:42 by almichel          #+#    #+#             */
/*   Updated: 2024/01/25 19:06:27 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	big_sort(t_list **a, t_list **b)
{
	t_list	*head_b;
	t_list	*the_smallest;
	
	head_b = *b;
	ft_push_to_b(a, b);
	tiny_sort(a);
	while (*b != NULL)
	{
		find_target_node(a, b);
		refreshing_rank_and_mediane(a);
		refreshing_rank_and_mediane(b);
		set_price(a, b);
		find_the_cheapest(b);
		move_nodes(a,b);
	}
	refreshing_rank_and_mediane(a);
	the_smallest = find_the_smallest(a);
	if (the_smallest->mediane == 0)
		while (*a != the_smallest)
			ft_ra_rb(a, 1);
	else
		while (*a != the_smallest);
			ft_rra_rrb(a, 1);
	ft_ra_rb(a, 1);
}

void	ft_push_to_b(t_list **a, t_list **b)
{
	int	i;
	int	len;

	len = stack_len(a);
	i = 0;
	while (i < len - 3)
	{
		ft_pb(a, b);
		i++;
	}
}

void	tiny_sort(t_list **a)
{
	t_list *highest_node;
	t_list *head_a;
	
	head_a = *a;
	highest_node = biggest_node(a);
	if (head_a == highest_node)
		ft_ra_rb(a, 1);
	else if (head_a->next == highest_node)
		ft_rra_rrb(a, 1);
	if ((*a)->nbr > (*a)->next->nbr)
		ft_sa_sb(a, 1);
}


int	ft_check_error(int argc, char **argv)
{
	int i = 0;
	if (ft_check_doubles(argv) == -1)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	while (++i < argc)
	{
		if (ft_check_nbrs(argv[i]) == -1)
		{
			write(2, "Error\n", 6);
				return (-1);
		}
		if (ft_check_int(argv[i]) == -1)
		{
			write(2, "Error\n", 6);
				return (-1);
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	
	b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (ft_check_error(argc, argv) == -1)
		{
			if (argc == 2)
				ft_doublefree(argv, ft_count_tabs(argv));
			write(2, "Error\n", 6);
			return (1);
		}
	if (ft_is_already_sorted(argv) != -1)
	{
		stack_init(&a, argv);
		if (stack_len(&a) == 2)
			ft_sa_sb(&a, 1);
		else if (stack_len(&a) == 3)
			tiny_sort(&a);
		else
			big_sort(&a, &b);
			//t_list *head_a;
			//head_a = *a;
			while (a)
			{
				printf("%d\n", a->nbr);
				a = a->next;
			}
		if (argc == 2)
			ft_doublefree(argv, ft_count_tabs(argv));
	}
}
