/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 01:04:23 by almichel          #+#    #+#             */
/*   Updated: 2024/01/15 13:28:08 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_rr(t_list **a, t_list **b)
{
	ft_ra_rb(a);
	ft_ra_rb(b);
}

int	ft_rra_rrb(t_list **list)
{
	t_list *back;
	t_list	*before_back;
	
	if (list == NULL || *list == NULL)
		return (-1);
	back = *list;

	while(back->next)
	{
		before_back = back;
		back = back->next;
	}
	before_back->next = NULL;
	ft_lstadd_front(list, back);
	return (0);
	
}

void	ft_rrr(t_list **a, t_list **b)
{
	ft_rra_rrb(a);
	ft_rra_rrb(b);
}
