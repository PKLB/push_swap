/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 13:38:48 by ple-berr          #+#    #+#             */
/*   Updated: 2022/01/24 16:34:45 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*n;
	size_t	i;

	i = 0;
	n = malloc(count * size);
	if (n == NULL)
		return (NULL);
	while (i < (count * size))
		n[i++] = 0;
	return (n);
}
