/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements_second.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:51:01 by ple-berr          #+#    #+#             */
/*   Updated: 2022/02/22 13:51:03 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	ft_reverse_rotate_a(t_a **first_pile)
{
	t_a	*tmp;
	t_a	*last;

	tmp = (*first_pile);
	while (tmp->next)
	{
		if (!tmp->next->next)
			last = tmp;
		tmp = tmp->next;
	}
	last->next = NULL;
	tmp->next = (*first_pile);
	(*first_pile) = tmp;
	ft_putstr("rra\n");
	return (0);
}

int	ft_reverse_rotate_b(t_a **first_pile_b)
{
	t_a	*tmp;
	t_a	*last;

	tmp = (*first_pile_b);
	while (tmp->next)
	{
		if (!tmp->next->next)
			last = tmp;
		tmp = tmp->next;
	}
	last->next = NULL;
	tmp->next = (*first_pile_b);
	(*first_pile_b) = tmp;
	ft_putstr("rrb\n");
	return (0);
}

int	ft_swap_a(t_a **first_pile)
{
	t_a		*swap;
	int		tmp;

	if (ft_check_empty_list(*first_pile) != 0)
		return (1);
	tmp = (*first_pile)->content;
	swap = (*first_pile);
	swap->content = swap->next->content;
	swap = swap->next;
	swap->content = tmp;
	ft_putstr("sa\n");
	return (0);
}

int	ft_swap_b(t_a **first_pile_b)
{
	int		tmp;
	t_a		*swap_b;

	if (ft_check_empty_list(*first_pile_b) != 0)
		return (1);
	tmp = (*first_pile_b)->content;
	swap_b = (*first_pile_b);
	swap_b->content = swap_b->next->content;
	swap_b = swap_b->next;
	swap_b->content = tmp;
	ft_putstr("sb\n");
	return (0);
}
