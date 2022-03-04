/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:16:06 by ple-berr          #+#    #+#             */
/*   Updated: 2022/01/24 16:35:59 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

char	*ft_strdup(const char *c)
{
	int		i;
	char	*str;

	i = 0;
	while (c[i])
		i++;
	str = malloc(i * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (c[i])
	{
		str[i] = c[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
