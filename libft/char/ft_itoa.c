/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <ede-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:19:13 by ede-lang          #+#    #+#             */
/*   Updated: 2024/03/12 11:47:34 by ede-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static size_t	ft_intlen(int nb)
{
	size_t	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

/**
 * @brief convert an int to a string
 *
 * @param n int to convert
 * @return char*
 */
char	*ft_itoa(int n)
{
	size_t	size;
	char	*result;
	long	nb;

	size = ft_intlen(n);
	nb = n;
	result = malloc(sizeof(char) * (size + 1));
	if (result == NULL)
		return (NULL);
	if (nb < 0)
		nb = -nb;
	result[size] = 0;
	while (size)
	{
		result[size - 1] = (nb % 10) + '0';
		nb = nb / 10;
		size--;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}
