/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <ede-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:23:42 by ede-lang          #+#    #+#             */
/*   Updated: 2024/03/12 13:25:25 by ede-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief set an area of memory to 0
 *
 * @param s pointer
 * @param n number of memory cell to set
 */
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*cc;

	cc = s;
	while (n--)
		*cc++ = '\0';
}
