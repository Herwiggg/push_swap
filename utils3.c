/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:05:32 by almichel          #+#    #+#             */
/*   Updated: 2024/04/11 00:09:13 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_len(t_list **list)
{
	int		i;
	t_list	*head;

	if (*list == NULL)
		return (0);
	head = *list;
	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

void	insert_mediane(t_list **list, int mediane_pos)
{
	int		i;
	t_list	*head;

	i = 0;
	head = *list;
	while (head)
	{
		if (i < mediane_pos)
			head->mediane = 0;
		else
			head->mediane = 1;
		head = head->next;
		i++;
	}
}

t_list	*find_the_smallest(t_list **a)
{
	t_list	*head_a;
	t_list	*the_smallest;
	long	stock_nbr;

	head_a = *a;
	stock_nbr = LONG_MAX;
	while (head_a)
	{
		if (head_a->nbr < stock_nbr)
		{
			stock_nbr = head_a->nbr;
			the_smallest = head_a;
		}
		head_a = head_a->next;
	}
	return (the_smallest);
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

int	ft_check_error(char **argv, int split_flag)
{
	int	i;

	if (split_flag == 1)
		i = -1;
	else
		i = 0;
	if (ft_check_doubles(argv, split_flag) == -1)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	while (argv[++i])
	{
		if (ft_check_nbrs(argv[i]) == -1 || ft_check_int(argv[i]) == -1)
		{
			write(2, "Error\n", 6);
			return (-1);
		}
	}
	if (ft_check_int(argv[0]) == -1)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	return (1);
}
