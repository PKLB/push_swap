/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:22:29 by ple-berr          #+#    #+#             */
/*   Updated: 2022/02/22 11:22:30 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	ft_chunk_big(t_a **pile_b, t_a **pile, int chunk, int mid)
{
	int		*first_second;
	int		temp_chunk;
	t_a		*copy;

	first_second = NULL;
	first_second = malloc(sizeof(int) * 2);
	temp_chunk = chunk;
	copy = (*pile);
	first_second[0] = ft_get_first_big(pile, chunk, copy);
	copy = (*pile);
	chunk = temp_chunk;
	while (copy != NULL)
	{
		if (copy->index <= chunk && copy->index != first_second[0])
			first_second[1] = copy->index;
		else if (copy->next == NULL && first_second[1] >= chunk)
		{
			chunk ++;
			copy = (*pile);
		}
		copy = copy->next;
	}
	if (ft_list_length((*pile)) == 1)
		return (ft_push_b(pile_b, pile));
	return (ft_al_big(first_second, mid, pile, pile_b));
}

int	ft_get_first_big(t_a **pile, int chunk, t_a *copy)
{
	int	first;

	first = (*pile)->index;
	while (copy != NULL)
	{
		if (copy->index <= chunk)
		{
			first = copy->index;
			break ;
		}
		copy = copy->next;
		if (copy->next == NULL && first > chunk)
		{
			chunk++;
			copy = (*pile);
		}
	}
	return (first);
}

int	ft_al_big(int *first_sec, int mid, t_a **pile, t_a **p_b)
{
	if (first_sec[0] >= (first_sec[1] - mid) && first_sec[0] <= mid)
	{
		while ((*pile)->index != first_sec[0])
			ft_rotate_a(pile);
		return (ft_push_b(p_b, pile));
	}
	else if ((first_sec[1] - mid) >= first_sec[0] && first_sec[1] <= mid)
	{
		while ((*pile)->index != first_sec[0])
			ft_rotate_a(pile);
		return (ft_push_b(p_b, pile));
	}
	else if (first_sec[0] <= (first_sec[1] - mid) && first_sec[0] >= mid)
	{
		while ((*pile)->index != first_sec[1])
			ft_reverse_rotate_a(pile);
		return (ft_push_b(p_b, pile));
	}
	else if ((first_sec[1] - mid) <= first_sec[0] && first_sec[1] >= mid)
	{
		while ((*pile)->index != first_sec[1])
			ft_reverse_rotate_a(pile);
		return (ft_push_b(p_b, pile));
	}
	return (ft_get_bottom_optimized(p_b, pile));
}
