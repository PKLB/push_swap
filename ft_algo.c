/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 08:25:58 by ple-berr          #+#    #+#             */
/*   Updated: 2022/02/22 11:14:28 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lib_push_swap.h"

int	ft_chunk_mid(t_a **pile_b, t_a **pile, int chunk, int mid)
{
	int		*first_sec;
	int		temp_chunk;
	t_a		*copy;

	first_sec = NULL;
	first_sec = malloc(sizeof(int) * 2);
	temp_chunk = chunk;
	copy = (*pile);
	first_sec[0] = ft_get_first(pile, chunk, copy);
	copy = (*pile);
	chunk = temp_chunk;
	first_sec[1] = ft_get_second(chunk, copy, first_sec[0]);
	if (ft_list_length((*pile)) == 1)
		return (ft_push_b(pile_b, pile));
	return (ft_algo(first_sec, mid, pile, pile_b));
}

int	ft_get_first(t_a **first_pile, int chunk, t_a *copy)
{
	int	first;

	first = (*first_pile)->index;
	while (copy != NULL)
	{
		if (copy->index <= chunk)
		{
			first = copy->index;
			break ;
		}
		copy = copy->next;
	}
	return (first);
}

int	ft_get_second(int chunk, t_a *copy, int first)
{
	int	second;

	while (copy != NULL)
	{
		if (copy->index <= chunk && copy->index != first)
			second = copy->index;
		else if (copy->index >= chunk && copy->index != first)
			second = copy->index;
		copy = copy->next;
	}
	return (second);
}

int	ft_algo(int *first_sec, int mid, t_a **pile, t_a **pile_b)
{
	if (first_sec[0] <= mid && first_sec[0] < first_sec[1])
	{
		while ((*pile)->index != first_sec[0])
			ft_rotate_a(pile);
		return (ft_push_b(pile_b, pile));
	}
	else if (first_sec[1] <= mid && first_sec[1] < first_sec[0])
	{
		while ((*pile)->index != first_sec[1])
			ft_rotate_a(pile);
		return (ft_push_b(pile_b, pile));
	}
	else if (first_sec[0] >= mid && first_sec[0] > first_sec[1])
	{
		while ((*pile)->index != first_sec[0])
			ft_reverse_rotate_a(pile);
		return (ft_push_b(pile_b, pile));
	}
	else if (first_sec[1] >= mid && first_sec[1] > first_sec[0])
	{
		while ((*pile)->index != first_sec[1])
			ft_reverse_rotate_a(pile);
		return (ft_push_b(pile_b, pile));
	}
	return (ft_get_bottom_optimized(pile_b, pile));
}
