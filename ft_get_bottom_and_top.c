/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_bottom_and_top.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:22:23 by ple-berr          #+#    #+#             */
/*   Updated: 2022/02/22 11:22:24 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	ft_get_top(t_a **first_pile_b, t_a **first_pile)
{
	int		high;
	t_a		*copy;

	copy = (*first_pile);
	high = (*first_pile)->content;
	while (copy != NULL)
	{
		if (high < copy->content)
		high = copy->content;
		copy = copy->next;
	}
	copy = (*first_pile);
	while (copy->content != high)
		ft_rotate_a(first_pile);
	ft_push_b(first_pile_b, first_pile);
	return (0);
}

int	ft_get_bottom(t_a **pile_b, t_a **pile)
{
	int		bottom;
	t_a		*copy;

	copy = (*pile);
	bottom = (*pile)->content;
	while (copy != NULL)
	{
		if (bottom > copy->content)
		bottom = copy->content;
		copy = copy->next;
	}
	copy = (*pile);
	while (copy->content != bottom)
		ft_rotate_a(pile);
	ft_push_b(pile_b, pile);
	return (0);
}

int	ft_get_bottom_optimized(t_a **pile_b, t_a **pile)
{
	int		bottom;
	int		middle;
	t_a		*copy;

	copy = (*pile);
	bottom = (*pile)->content;
	while (copy != NULL)
	{
		if (bottom >= copy->content)
			bottom = copy->content;
		copy = copy->next;
	}
	copy = (*pile);
	while (copy->content != bottom)
		copy = copy->next;
	middle = (ft_list_length((*pile)) / 2);
	if (copy->position <= middle)
	{
		while ((*pile)->content != bottom)
			ft_rotate_a(pile);
		return (ft_push_b(pile_b, pile));
	}
	while ((*pile)->content != bottom)
		ft_reverse_rotate_a(pile);
	return (ft_push_b(pile_b, pile));
}

int	ft_get_bottom_optimized_b(t_a **pile_b, t_a **pile)
{
	int		bottom;
	int		middle;
	t_a		*copy;

	copy = (*pile_b);
	bottom = (*pile_b)->index;
	while (copy != NULL)
	{
		if (bottom < copy->index)
			bottom = copy->index;
		copy = copy->next;
	}
	copy = (*pile_b);
	while (copy->index != bottom)
		copy = copy->next;
	middle = (ft_list_length((*pile_b)) / 2);
	if (copy->position <= middle)
	{
		while ((*pile_b)->index != bottom)
			ft_rotate_b(pile_b);
		return (ft_push_a(pile_b, pile));
	}
	while ((*pile_b)->index != bottom)
		ft_reverse_rotate_b(pile_b);
	return (ft_push_a(pile_b, pile));
}
