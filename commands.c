/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 00:52:25 by almichel          #+#    #+#             */
/*   Updated: 2024/01/24 01:41:29 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sa_sb(t_list **list, int flag)
{
	t_list	*first;
	t_list	*second;
	t_list	*temp;

	if (list == NULL || *list == NULL)
		return (-1);
	first = *list;
	second = first->next;
	if (!second)
		return (-1);
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
	if (flag == 1)
		write(1, "sa\n", 3);
	else if (flag == 2)
		write(1, "sb\n", 3);
	return (0);
}

void	ft_ss(t_list **a, t_list **b)
{
	ft_sa_sb(a, 3);
	ft_sa_sb(b, 3);
	write(1, "ss\n", 3);
}

int	ft_pa(t_list **a, t_list **b)
{
	 t_list *head_b;

    if (!b || !*b)
        return (-1);
    
    head_b = *b;
    *b = head_b->next;

    if (*b)
        (*b)->prev = NULL;

    if (!*a)
    {
        *a = head_b;
        head_b->prev = NULL;
        head_b->next = NULL;
    }
    else
    {
        head_b->next = *a;
        (*a)->prev = head_b;
        *a = head_b;
        head_b->prev = NULL;
    }

    write(1, "pa\n", 3);
    return (0);
}

int	ft_pb(t_list **a, t_list **b)
{
 t_list *head_a;

    if (!a || !*a)
        return (-1);
    head_a = *a;
    *a = head_a->next;

    if (!*b)
    {
        *b = head_a;
        head_a->prev = NULL;
        head_a->next = NULL;
    }
    else
    {
        head_a->next = *b;
        (*b)->prev = head_a;
        *b = head_a;
        head_a->prev = NULL;
    }
    write(1, "pb\n", 3);
    return (0);
}

int	ft_ra_rb(t_list **list, int flag)
{
	t_list	*head;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return (-1);
	head = *list;
	*list = head->next;
	head->next->prev = NULL;
	head->next = NULL;
	ft_lstadd_back(list, head);
	if (flag == 1)
		write(1, "ra\n", 3);
	else if (flag == 2)
		write(1, "rb\n", 3);
	return (0);
}
