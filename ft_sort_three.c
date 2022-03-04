/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 08:27:18 by ple-berr          #+#    #+#             */
/*   Updated: 2022/02/22 08:27:19 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	ft_sort_three(t_a **pile)
{
	if ((*pile)->content < (*pile)->next->content
		&& (*pile)->next->content < ft_end((*pile)))
		return (0);
	if ((*pile)->content > (*pile)->next->content
		&& (*pile)->next->next->content > (*pile)->content)
		return (ft_swap_a(pile));
	if ((*pile)->content > (*pile)->next->content
		&& (*pile)->next->content > (*pile)->next->next->content)
	{
		ft_swap_a(pile);
		return (ft_reverse_rotate_a(pile));
	}
	if ((*pile)->content > (*pile)->next->content
		&& (*pile)->content > (*pile)->next->next->content)
		return (ft_rotate_a(pile));
	if ((*pile)->content < (*pile)->next->content
		&& (*pile)->content < (*pile)->next->next->content)
	{
		ft_swap_a(pile);
		return (ft_rotate_a(pile));
	}
	if ((*pile)->content < (*pile)->next->content
		&& (*pile)->next->content > (*pile)->next->next->content)
		return (ft_reverse_rotate_a(pile));
	return (0);
}
