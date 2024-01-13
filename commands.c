/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 00:52:25 by almichel          #+#    #+#             */
/*   Updated: 2024/01/13 17:10:09 by almichel         ###   ########.fr       */
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
	ft_sa_sb(a);
	ft_sa_sb(b);
}

void	ft_pa(t_list **a, t_list **b)
{
	t_list *head_a;
	t_list *head_b;

	if (!b || !*b)
		return;
	head_a = *a;
	head_b = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	if (*a)
		(*a)->prev = head_b;
	head_b->next = head_a;
	head_b->prev = NULL;
	*a = head_b;
}

void	ft_pb(t_list **a, t_list **b)
{
	t_list *head_a;
	t_list *head_b;

	if (!a || !*a)
		return;
	head_a = *a;
	head_b = *b;
	*a = (*a)->next;
	(*a)->prev = NULL;
	if (*b)
		(*b)->prev = head_a;
	head_a->next = head_b;
	head_a->prev = NULL;
	*b = head_a;
}

void	ft_ra_rb(t_list **list)
{
	t_list *head;

	head = *list;
	*list = head->next;
	head->next->prev = NULL;
	head->next = NULL; 
	ft_lstadd_back(list, head);
}

