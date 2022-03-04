/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 10:30:38 by ple-berr          #+#    #+#             */
/*   Updated: 2022/02/22 08:27:00 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	main(int argc, char *argv[])
{
	int		i;
	char	**other_numbers;

	i = 0;
	if (argc == 2)
	{
		other_numbers = ft_split(argv[1], ' ');
		if (ft_checks(other_numbers, 0) != 0)
			return (-1);
		while (other_numbers[i])
			i++;
		return (ft_push_swap(i, other_numbers));
	}
	if (argc > 2)
	{
		i = 1;
		while (argv[i])
		{
			if (ft_checks(argv, 1 != 0))
				return (-1);
			i++;
		}
		return (ft_push_swap_other(argv, i));
	}
	return (0);
}

int	ft_push_swap_other(char **argv, int n)
{
	t_a	*pile;
	t_a	*pile_b;
	t_a	**first_pile;
	t_a	**first_pile_b;

	pile = NULL;
	pile_b = NULL;
	first_pile = &pile;
	first_pile_b = &pile_b;
	ft_fill_list_args(n, argv, first_pile);
	if (n == 4)
	{
		ft_sort_three(first_pile);
		free_main(first_pile);
		return (0);
	}
	if (n == 6)
	{
		ft_sort_five(first_pile_b, first_pile);
		free_main(first_pile);
		return (0);
	}
	ft_sort_more(first_pile_b, first_pile);
	free_main(first_pile);
	return (0);
}

int	ft_push_swap(int n, char **other_numbers)
{
	t_a	*pile;
	t_a	*pile_b;
	t_a	**first_pile;
	t_a	**first_pile_b;

	pile = NULL;
	pile_b = NULL;
	first_pile = &pile;
	first_pile_b = &pile_b;
	ft_fill_list(n, other_numbers, first_pile);
	if (n == 3)
	{
		ft_sort_three(first_pile);
		free_main(first_pile);
		return (0);
	}
	if (n == 5)
	{
		ft_sort_five(first_pile_b, first_pile);
		free_main(first_pile);
		return (0);
	}
	ft_sort_more(first_pile_b, first_pile);
	free_main(first_pile);
	return (0);
}

void	free_main(t_a **s)
{
	t_a	*lst;

	while (*s)
	{
		lst = (*s)->next;
		free(*s);
		*s = lst;
	}
	free(*s);
	free(lst);
	*s = NULL;
}
