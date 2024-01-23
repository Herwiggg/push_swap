/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:05:32 by almichel          #+#    #+#             */
/*   Updated: 2024/01/22 23:50:09 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_len(t_list **list)
{
	int	i;
	t_list	*head;
	
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
	int	i;
	t_list	*head;

	i = 0;
	head = *list;
	while (head)
	{
		if	(i < mediane_pos)
			head->mediane = 0;
		else
			head->mediane = 1;
		head = head->next;
		i++;
	}
}
