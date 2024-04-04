/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <	almichel@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:10:04 by almichel          #+#    #+#             */
/*   Updated: 2024/04/04 18:31:53 by almichel         ###   ########.fr       */
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
		new->prev = NULL;
		new->next = NULL;
		return ;
	}
	while (last->next)
		last = last->next;
	new->next = NULL;
	last->next = new;
	new->prev = last;
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

void	stack_init(t_list **list, char **argv, int split_flag)
{
	int		i;
	t_list	*new_case;
	int		rank;

	new_case = NULL;
	rank = 0;
	if (split_flag == 1)
		i = 0;
	else
		i = 1;
	while (argv[i])
	{
		new_case = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(list, new_case);
		i++;
		rank++;
	}
}
