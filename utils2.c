/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:11:44 by almichel          #+#    #+#             */
/*   Updated: 2024/01/12 19:14:18 by almichel         ###   ########.fr       */
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

