/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:46:18 by almichel          #+#    #+#             */
/*   Updated: 2024/01/24 00:01:00 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_list	*return_cheapest(t_list **b)
{
	t_list	*head_b;

	head_b = *b;
	while (head_b)
	{
		if (head_b->cheapest == 1)
			return (head_b);
		head_b = head_b->next;
	}
}

void	move_nodes(t_list **a, t_list **b)
{
	t_list	*cheapest_node;

	cheapest_node = return_cheapest(b);

	if (cheapest_node->mediane == 1 && cheapest_node->target_node->mediane == 1)
		rotate_both(a, b, cheapest_node);
	else if ((cheapest_node->mediane != 1 && cheapest_node->target_node->mediane != 1))
		reverse_rotate_both(a, b, cheapest_node);
	finish_rotation(a, cheapest_node, 1);
	finish_rotation(b, cheapest_node, 2);
	ft_pa(a, b);
}

void	rotate_both(t_list	**a, t_list **b, t_list *cheapest_node)
{
	while (*b != cheapest_node && *a != cheapest_node)
		ft_rr(a,b);
	refreshing_rank_and_mediane(a);
	refreshing_rank_and_mediane(b);
}

void	reverse_rotate_both(t_list **a, t_list **b, t_list *cheapest_node)
{
	while (*b != cheapest_node && *a != cheapest_node)
		ft_rrr(a, b);
	refreshing_rank_and_mediane(a);
	refreshing_rank_and_mediane(b);	
}
void	finish_rotation(t_list **list, t_list *top_node, int flag)
{
	while (*list != top_node)
	{
		if (flag == 1)
		{
			if (top_node->mediane == 0)
				ft_ra_rb(list, 1);
			else
				ft_rra_rrb(list, 1);
		}
		else if (flag = 2)
		{
			if (top_node->mediane == 0)
				ft_ra_rb(list, 2);
			else
				ft_rra_rrb(list, 2);
		}
	}
}
