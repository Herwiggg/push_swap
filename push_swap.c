/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:36:42 by almichel          #+#    #+#             */
/*   Updated: 2024/01/16 01:45:12 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	tiny_sort(t_list **a)
{
	t_list *head;
	t_list *second;
	t_list *third;

	head = *a;
	second = head->next;
	third = second->next;
	if (head->nbr > second->nbr && head->nbr > third->nbr)
		ft_ra_rb(a);
	else if (second->nbr > third->nbr)
		ft_rra_rrb(a);
	if ()
	

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
			ft_sa_sb(&a);
		else if (stack_len(&a) == 3)
			tiny_sort(&a);
		//else
		//	big_sort(&a, &b);
		if (argc == 2)
			ft_doublefree(argv, ft_count_tabs(argv));
	}
}
