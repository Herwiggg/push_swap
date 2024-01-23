/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 02:11:18 by almichel          #+#    #+#             */
/*   Updated: 2024/01/23 02:17:14 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*find_target_node(t_list **a, t_list *head_b)
{
	t_list	*head_a;
	t_list	*target_node;
	long	best_match;

	best_match = LONG_MAX;
	target_node = NULL;
	head_a = *a;
	while (head_b)
	{
		head_a = *a;
		while (head_a)
		{
			if (head_a->nbr > head_b->nbr && head_a->nbr < best_match)
			{
				best_match = head_a->nbr;
				target_node = head_a;
			}
			head_a = head_a->next;
		}
		if (LONG_MAX == best_match)
			head_b->target_node = the_smallest_node_in_a(a, target_node);
		else
			head_b->target_node = target_node;
		head_b = head_b->next;
	}
}

t_list	*the_smallest_node_in_a(t_list **a, t_list *target_node)
{
	t_list	*head_a;
	int		stock_nbr;

	head_a = *a;
	stock_nbr = LONG_MAX;
	while (head_a)
	{
		if (head_a->nbr < stock_nbr)
		{
			stock_nbr = head_a->nbr;
			target_node = head_a;
		}
		head_a = head_a->next;
	}
	return (target_node);
}


void	refreshing_rank_and_mediane(t_list **list)
{
	t_list	*head;
	int	i;
	int	len;
	i = 0;
	head = *list;
	while (head)
	{
		head->rank = i;
		head = head->next;
		i++;
	}
	len = list_len(list);
	if(len % 2 == 0)
		insert_mediane(list, len / 2);
	else
		insert_mediane(list, (len / 2) + 1);
}

void	set_price(t_list **a, t_list **b)
{
	t_list	*head_a;
	t_list	*head_b;
	int		len_a;
	int		len_b;

	len_a = list_len(a);
	len_b = list(b);
	head_a = *a;
	head_b = *b;
	while (head_b)
	{
		head_b->push_price = head_b->rank;
		if (head_b->mediane == 0)
			head_b->push_price = len_b - (head_b->rank);
		if (head_b->mediane == 1)
			head_b->push_price += head_b->target_node->rank;
		else
			head_b->push_price += len_a - (head_b->target_node->rank);
		head_b = head_b->next;
	}
}

void	find_the_cheapest(t_list **b)
{
	t_list	*the_cheapest;
	long	best_match;
	t_list	*head_b;

	head_b = *b;
	if (b == NULL)
		return;
	best_match = LONG_MAX;
	while (head_b)
	{
		if (head_b->push_price < best_match)
		{
			best_match = head_b->push_price;
			the_cheapest = head_b;
		}
		head_b = head_b->next;
	}
	the_cheapest->cheapest = 1;
}
