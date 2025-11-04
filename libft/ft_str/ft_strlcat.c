/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <ede-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:46:19 by ede-lang          #+#    #+#             */
/*   Updated: 2024/03/12 14:00:54 by ede-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief copy a string at the end of an other
 *
 * @param dst
 * @param src
 * @param size
 * @return size_t
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dst[i] && i < size)
		i++;
	while ((i + j) < size - 1 && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	if (j)
		dst[i + j] = 0;
	return (i + ft_strlen(src));
}
