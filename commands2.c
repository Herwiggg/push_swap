/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 01:04:23 by almichel          #+#    #+#             */
/*   Updated: 2024/01/14 23:37:30 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_rr(t_list **a, t_list **b)
{
	ft_ra_rb(a);
	ft_ra_rb(b);
}

void	ft_rra_rrb(t_list **list)
{
	t_list *back;
	t_list	*before_back;
	
	back = *list;

	while(back->next)
	{
		before_back = back;
		back = back->next;
	}
	before_back->next = NULL;
	ft_lstadd_front(list, back);
	
}

void	ft_rrr(t_list **a, t_list **b)
{
	ft_rra_rrb(a);
	ft_rra_rrb(b);
}