/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <ede-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:52:35 by ede-lang          #+#    #+#             */
/*   Updated: 2024/03/12 13:31:33 by ede-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief copy a memory area to another, copy even if overlaping area
 *
 * @param dest destination
 * @param src source
 * @param n nb of byte to copy
 * @return void*
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*csrc;
	char	*cdest;
	size_t	i;

	csrc = (char *)src;
	cdest = (char *)dest;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		if (csrc + i == cdest)
		{
			while (n--)
				cdest[n] = csrc[n];
			return (dest);
		}
		i++;
	}
	ft_memcpy(dest, src, n);
	return (dest);
}
