/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:11:44 by almichel          #+#    #+#             */
/*   Updated: 2024/01/19 18:36:09 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_already_sorted(char **argv)
{
	int i;
	int j;
	i = 1;
	while (argv[i + 1])
	{
		j = i + 1;
		if (ft_atoi(argv[i]) < ft_atoi(argv[j]))
			i++;
		else
			return (0);
	}
	return (-1);
}

int	ft_count_tabs(char **tab)
{
	int	i;
	int	j;
	i = 0;

	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
			j++;
		i++;
	}
	return (i);
}
int stack_len(t_list **list)
{
	int	i;
	t_list *head;
	
	i = 0;
	head = *list;

	while(head)
	{
		i++;
		head = head->next;
	}
	return (i);
}
t_list *biggest_node(t_list **list)
{
	t_list *head;
	int		big_nbr;
	t_list	*temp;

	head = *list;
	temp = head;
	big_nbr = head->nbr;
	head = head->next;
	while (head)
	{
		if (head->nbr > big_nbr)
		{
			big_nbr = head->nbr;
			temp = head;
		}
		head = head->next;
	}
	return (temp);
}

