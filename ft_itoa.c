/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:10:45 by ple-berr          #+#    #+#             */
/*   Updated: 2022/01/24 17:07:52 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

static int	ft_int_len(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_strrev(char *c, int n)
{
	int		i;
	char	swap;

	i = 0;
	c[n] = '\0';
	n = n - 1;
	while (i < n)
	{
		swap = c[i];
		c[i] = c[n];
		c[n] = swap;
		n--;
		i++;
	}
	return (c);
}

static char	*ft_mallokitoa(int n_copy, int len)
{
	char	*copy;

	if (n_copy == -2147483648)
	{
		copy = ft_strdup("-2147483648");
		return (copy);
	}
	copy = malloc((len + 1) * sizeof(char));
	return (copy);
}

char	*ft_itoa(int n)
{
	char	*copy;
	int		len;
	int		i;
	int		n_copy;

	n_copy = n;
	len = ft_int_len(n);
	copy = ft_mallokitoa(n_copy, len);
	if (copy == NULL)
		return (NULL);
	if (n_copy == -2147483648)
		return (copy);
	i = 0;
	if (n < 0)
		n *= -1;
	copy[i++] = n % 10 + '0';
	while (n > 9)
	{
		n /= 10;
		copy[i++] = n % 10 + '0';
	}
	copy = ft_strrev(copy, len);
	if (n_copy < 0)
		copy[0] = '-';
	return (copy);
}
