/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:46:59 by ple-berr          #+#    #+#             */
/*   Updated: 2022/01/25 13:55:11 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	ft_check_number(char **nb, int args)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	if (args == 1)
		i = 0;
	while (nb[i])
	{
		n = 0;
		while (nb[i][n])
		{
			if ((nb[i][n] >= '0' && nb[i][n] <= '9') || (nb[i][n] == ' ')
				|| (nb[i][n] == '-'
				&& nb[i][n + 1] >= '0' && nb[i][n + 1] <= '9'))
				n++;
			else
				return (-1);
		}
		i++;
	}
	return (0);
}

int	ft_check_number_arg(char **argv)
{
	int	i;
	int	n;

	n = 0;
	i = 1;
	while (argv[i])
	{
		n = 0;
		while (argv[i][n])
		{
			if ((argv[i][n] >= '0' && argv[i][n] <= '9') || (argv[i][n] == ' ')
				|| (argv[i][n] == '-'))
				n++;
			else
				return (-1);
		}
		i++;
	}
	return (0);
}

int	ft_check_duplicates(char **numbers, int args)
{
	int	i;
	int	j;

	i = 0;
	if (args == 1)
		i = 1;
	j = i + 1;
	while (numbers[i])
	{
		while ((numbers[j]))
		{
			if ((int)ft_atoi(numbers[i]) == (int)ft_atoi(numbers[j]))
				return (-1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int	ft_check_size(char **numbers, int args)
{
	int	i;

	i = 0;
	if (args == 1)
		i = 1;
	while (numbers[i])
	{
		if (ft_atoi(numbers[i]) >= 2147483647)
			return (-1);
		if (ft_atoi(numbers[i]) <= -2147483647)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_check_if_sorted(char **numbers, int args)
{
	int	i;

	i = 0;
	if (args == 1)
		i = 1;
	while (numbers[i] && (numbers[i + 1] != NULL))
	{
		if (ft_atoi(numbers[i]) > ft_atoi(numbers[i + 1]))
			return (0);
		i++;
	}
	return (0);
}
