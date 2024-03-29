/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 01:04:23 by almichel          #+#    #+#             */
/*   Updated: 2024/01/27 21:07:07 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr(t_list **a, t_list **b)
{
	write(1, "rr\n", 3);
	ft_ra_rb(a, 3);
	ft_ra_rb(b, 3);
}

int	ft_rra_rrb(t_list **list, int flag)
{
	t_list	*back;
	t_list	*before_back;

	before_back = NULL;
	if (list == NULL || *list == NULL)
		return (-1);
	back = *list;
	while (back->next)
	{
		before_back = back;
		back = back->next;
	}
	before_back->next = NULL;
	back->prev = NULL;
	ft_lstadd_front(list, back);
	(*list)->next->prev = *list;
	if (flag == 1)
		write(1, "rra\n", 4);
	else if (flag == 2)
		write(1, "rrb\n", 4);
	return (0);
}

void	ft_rrr(t_list **a, t_list **b)
{
	write(1, "rrr\n", 4);
	ft_rra_rrb(a, 3);
	ft_rra_rrb(b, 3);
}
