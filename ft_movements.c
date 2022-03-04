/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 08:26:39 by ple-berr          #+#    #+#             */
/*   Updated: 2022/02/22 08:26:42 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	ft_rotate_a(t_a **first_pile)
{
	t_a		*swap;
	int		nb;
	int		ind;

	if (ft_check_empty_list(*first_pile) != 0)
		return (1);
	swap = (*first_pile);
	nb = (*first_pile)->content;
	ind = (*first_pile)->index;
	swap->index = swap->next->index;
	swap->content = swap->next->content;
	while (swap->next != NULL)
	{
		swap->index = swap->next->index;
		swap->content = swap->next->content;
		swap = swap->next;
	}
	swap->index = ind;
	swap->content = nb;
	ft_putstr("ra\n");
	return (0);
}

int	ft_rotate_b(t_a **first_pile_b)
{
	t_a		*swap;
	int		nb;
	int		ind;

	if (ft_check_empty_list(*first_pile_b) != 0)
		return (1);
	swap = (*first_pile_b);
	nb = (*first_pile_b)->content;
	ind = (*first_pile_b)->index;
	swap->index = swap->next->index;
	swap->content = swap->next->content;
	while (swap->next != NULL)
	{
		swap->index = swap->next->index;
		swap->content = swap->next->content;
		swap = swap->next;
	}
	swap->index = ind;
	swap->content = nb;
	ft_putstr("rb\n");
	return (0);
}
