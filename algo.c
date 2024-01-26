/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:46:18 by almichel          #+#    #+#             */
/*   Updated: 2024/01/25 21:59:46 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_list	*return_cheapest(t_list **b)
{
	t_list	*head_b;

	if (NULL == b)
		return (NULL);
	head_b = *b;
	while (head_b)
	{
		if (head_b->cheapest == 1)
			return (head_b);
		head_b = head_b->next;
	}
	return (NULL);
}

void	move_nodes(t_list **a, t_list **b)
{
	t_list	*cheapest_node;

	cheapest_node = return_cheapest(b);

	if (cheapest_node->mediane != 1 && cheapest_node->target_node->mediane != 1)
		rotate_both(a, b, cheapest_node);
	else if ((cheapest_node->mediane == 1 && cheapest_node->target_node->mediane == 1))
		reverse_rotate_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 2);
	finish_rotation(a, cheapest_node->target_node, 1);
	ft_pa(a, b);
}

void	rotate_both(t_list	**a, t_list **b, t_list *cheapest_node)
{
	t_list *head_a;
	t_list *head_b;

	head_a = *a;
	head_b = *b;
	while (head_b != cheapest_node && head_a != cheapest_node->target_node)
		ft_rr(a,b);
	refreshing_rank_and_mediane(a);
	refreshing_rank_and_mediane(b);
}

void	reverse_rotate_both(t_list **a, t_list **b, t_list *cheapest_node)
{
	t_list *head_a;
	t_list *head_b;

	head_a = *a;
	head_b = *b;
	while (head_b != cheapest_node && head_a != cheapest_node->target_node)
		ft_rrr(a, b);
	refreshing_rank_and_mediane(a);
	refreshing_rank_and_mediane(b);	
}
void	finish_rotation(t_list **list, t_list *top_node, int flag)
{
	t_list	*head;
	head = *list;
	while (head != top_node)
	{
		if (flag == 1)
		{
			if (top_node->mediane == 0)
				ft_ra_rb(list, 1);
			else
				ft_rra_rrb(list, 1);
		}
		else if (flag == 2)
		{
			if (top_node->mediane == 0)
				ft_ra_rb(list, 2);
			else
				ft_rra_rrb(list, 2);
		}
		head = *list;
	}
	
}
