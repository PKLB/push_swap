/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 07:55:22 by ple-berr          #+#    #+#             */
/*   Updated: 2022/02/22 08:03:30 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

t_a	*ft_create_list(void)
{
	t_a	*head;

	head = (malloc(sizeof(t_a)));
	if (head == NULL)
		return (NULL);
	head->content = 0;
	head->index = -1;
	head->position = -1;
	head->next = NULL;
	return (head);
}

void	ft_lstadd_front(int number, t_a **first_pile)
{
	t_a	*new_node;

	new_node = ft_create_list();
	new_node->content = number;
	new_node->next = (*first_pile);
	*first_pile = new_node;
}

void	*ft_lstadd_back(int number, t_a *pile)
{
	t_a	*element;
	t_a	*tmp;

	element = malloc(sizeof(t_a));
	element->content = number;
	element->index = -1;
	element->position = -1;
	element->next = NULL;
	tmp = pile;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = element;
	return (element);
}

int	ft_fill_list(int n, char **other_numbers, t_a **pile)
{
	int	i;

	i = 0;
	ft_lstadd_front(ft_atoi(other_numbers[i++]), pile);
	while (i < n)
		ft_lstadd_back(ft_atoi(other_numbers[i++]),*pile);
	return (0);
}

int	ft_fill_list_args(int n, char **other_numbers, t_a **first_pile)
{
	int	i;

	i = 1;
	ft_lstadd_front(ft_atoi(other_numbers[i++]), first_pile);
	while (i < n)
		ft_lstadd_back(ft_atoi(other_numbers[i++]),*first_pile);
	return (0);
}
