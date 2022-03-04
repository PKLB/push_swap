/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:46:26 by ple-berr          #+#    #+#             */
/*   Updated: 2022/01/25 13:48:36 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int	ft_checks(char **numbers, int args)
{
	if (args == 1)
	{
		if (ft_check_number_arg(numbers) != 0)
			return (1);
	}
	else
	{
		if (ft_check_number(numbers, args) != 0)
			return (1);
	}
	if (ft_check_duplicates(numbers, args) != 0)
		return (1);
	if (ft_check_size(numbers, args) != 0)
		return (1);
	if (ft_check_if_sorted(numbers, args) != 0)
		return (1);
	return (0);
}
