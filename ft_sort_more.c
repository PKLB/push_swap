/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_more.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 08:27:12 by ple-berr          #+#    #+#             */
/*   Updated: 2022/02/22 08:27:13 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	ft_sort_more(t_a **first_pile_b, t_a **first_pile)
{
	t_a		*temp;
	int		length;
	int		middle;

	length = ft_list_length((*first_pile));
	middle = (ft_list_length((*first_pile)) / 2);
	temp = (*first_pile);
	ft_get_index(first_pile);
	ft_get_pos(first_pile);
	if (length >= 250)
		ft_big_loop(first_pile_b, first_pile, middle);
	else
		ft_small_loop(first_pile_b, first_pile, middle);
	ft_get_index(first_pile_b);
	while (ft_check_empty_list((*first_pile_b)) != 1)
	{
		ft_get_pos(first_pile_b);
		ft_get_bottom_optimized_b(first_pile_b, first_pile);
	}
	return (0);
}

int	ft_big_loop(t_a **pile_b, t_a **pile, int middle)
{
	int	chunk;
	int	count;

	count = 0;
	chunk = 50;
	while (ft_check_empty_list((*pile)) == 0)
	{
		count++;
		if (count == 50)
			chunk += 50;
		if (count == 100)
		{
			middle = (ft_list_length((*pile)) / 2);
			chunk += 50;
			count = 0;
		}
		ft_chunk_big(pile_b, pile, chunk, middle);
	}
	return (0);
}

int	ft_small_loop(t_a **pile_b, t_a **pile, int middle)
{
	int	chunk;
	int	count;

	count = 0;
	chunk = 25;
	while (ft_check_empty_list((*pile)) == 0)
	{
		if (count == 25 || count == 50)
			chunk += 25;
		if (count == 50)
			middle = (ft_list_length((*pile)) / 2);
		count++;
		ft_chunk_mid(pile_b, pile, chunk, middle);
	}
	return (0);
}

int	ft_get_pos(t_a **first_pile)
{
	int		pos;
	t_a		*temp;

	pos = 0;
	temp = (*first_pile);
	while (temp->next != NULL)
	{
		temp->position = pos++;
		temp = temp->next;
	}
	return (0);
}

int	ft_get_index(t_a **first_pile)
{
	static int	index;
	int			check;
	int			lowest;
	t_a			*temp;

	lowest = -2147483647;
	index = -1;
	check = 2147483647;
	temp = (*first_pile);
	while (index < ft_list_length((*first_pile)) - 1)
	{
		if (temp->content < check && temp->index == -1)
			check = temp->content;
		if (temp->content == lowest && temp->index == -1
			&& index < ft_list_length((*first_pile)))
			temp->index = ++index;
		temp = temp->next;
		if (temp == NULL && index < ft_list_length((*first_pile)))
		{
			lowest = check;
			check = 2147483647;
			temp = (*first_pile);
		}
	}
	return (0);
}
