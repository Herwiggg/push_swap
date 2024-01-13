/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 00:52:25 by almichel          #+#    #+#             */
/*   Updated: 2024/01/13 03:04:51 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa_sb(t_list **list)
{
	t_list	*first;
	t_list	*second;
	t_list	*temp;

	first = *list;
	second = first->next;
	temp = second->next;
	second->next = first;
	second->prev = first->prev;
	first->next = temp;
	first->prev = second;
	if (temp)
		temp->prev = first;
	if (second->prev)
		second->prev->next = second;
	else
		*list = second;
}

void	ft_ss(t_list **a, t_list **b)
{
}

void	ft_pa_pb(t_list **list)
{
}

void	ft_ra_rb(t_list **list)
{
}

void	ft_rr(t_list **a, t_list **b)
{
}
