/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_second.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:28:13 by ple-berr          #+#    #+#             */
/*   Updated: 2022/02/22 11:28:14 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	ft_remove_first(t_a **first_pile)
{
	t_a	*tmp;

	tmp = *first_pile;
	(*first_pile) = (*first_pile)->next;
	free(tmp);
	tmp = NULL;
	return (0);
}

int	ft_push_b(t_a **first_pile_b, t_a **first_pile)
{
	ft_putstr("pb\n");
	if (ft_check_empty_list(*first_pile) != 0)
		return (1);
	ft_lstadd_front((*first_pile)->content, first_pile_b);
	ft_remove_first(first_pile);
	return (0);
}

int	ft_push_a(t_a **first_pile_b, t_a **first_pile)
{
	ft_putstr("pa\n");
	if (ft_check_empty_list(*first_pile_b) != 0)
		return (1);
	ft_lstadd_front((*first_pile_b)->content, first_pile);
	ft_remove_first(first_pile_b);
	return (0);
}

int	ft_end(t_a *pile)
{
	int		i;
	t_a		*tmp;

	tmp = pile;
	i = 0;
	while (tmp->next != NULL)
		tmp = tmp->next;
	i = tmp->content;
	return (i);
}
