/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:10:04 by almichel          #+#    #+#             */
/*   Updated: 2024/01/25 02:46:18 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int nbr)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->nbr = nbr;
	list->cheapest = 0;
	list->target_node = NULL;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		new->next = *lst;
		*lst = new;
	}
}


void	ft_free_list(t_list **list)
{
	t_list	*head;
	t_list	*temp;

	head = *list;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

void	stack_init(t_list **list, char **argv)
{
	int	i;
	t_list *new_case;
	int	rank;

	rank = 0;
	i = 1;
	while (argv[i])
	{
		new_case = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(list, new_case);
		i++;
		rank++;
	}
}
