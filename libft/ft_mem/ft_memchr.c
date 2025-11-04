/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <ede-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:06:45 by ede-lang          #+#    #+#             */
/*   Updated: 2024/03/12 13:27:32 by ede-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief search an area of memory to find a char
 *
 * @param s area to search
 * @param c char to find
 * @param n max area size to search
 * @return void*
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*cs;

	cs = (const char *)s;
	while (n--)
	{
		if (*cs == (char)c)
			return ((void *)cs);
		cs++;
	}
	return (NULL);
}
