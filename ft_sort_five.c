/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 08:27:06 by ple-berr          #+#    #+#             */
/*   Updated: 2022/02/22 08:27:07 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	ft_is_sorted(t_a *pile)
{
	t_a	*check;

	check = pile;
	if (ft_check_empty_list(pile) != 0)
		return (1);
	while (check->next != NULL)
	{
		if (check->content < check->next->content)
			check = check->next;
		else
			break ;
	}
	if (check->next == NULL)
		return (0);
	else
		return (1);
}

int	ft_sort_five(t_a **first_pile_b, t_a **first_pile)
{
	ft_get_bottom_optimized(first_pile_b, first_pile);
	ft_get_bottom_optimized(first_pile_b, first_pile);
	ft_sort_three(first_pile);
	ft_push_a(first_pile_b, first_pile);
	ft_push_a(first_pile_b, first_pile);
	return (0);
}
