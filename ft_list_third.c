/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_third.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:28:19 by ple-berr          #+#    #+#             */
/*   Updated: 2022/02/22 11:28:20 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	ft_list_length(t_a *pile)
{
	int	i;

	i = 0;
	while (pile != NULL)
	{
		i++;
		pile = pile->next;
	}
	return (i);
}

int	ft_check_empty_list(t_a *pile)
{
	if (pile == NULL)
		return (1);
	return (0);
}

void	*ft_remove_last(t_a *pile)
{
	list	*tmp;
	list	*before;

	if (ft_check_empty_list(pile) == 1)
		return (NULL);
	if (pile->next == NULL)
	{
		free(pile);
		pile = NULL;
		return (NULL);
	}
	tmp = pile;
	before = pile;
	while (tmp->next != NULL)
	{
		before = tmp;
		tmp = tmp->next;
	}
	before->next = NULL;
	free(tmp);
	tmp = NULL;
	return (0);
}
