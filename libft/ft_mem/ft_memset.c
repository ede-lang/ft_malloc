/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <ede-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:51:54 by ede-lang          #+#    #+#             */
/*   Updated: 2024/03/12 13:32:47 by ede-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief set each byte of a memory are to a char
 *
 * @param s area
 * @param c char to set
 * @param n nb of byte to set
 * @return void*
 */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*cc;

	cc = s;
	while (n--)
		*cc++ = (unsigned char)c;
	return (s);
}
