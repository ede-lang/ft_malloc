/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <ede-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:09:48 by ede-lang          #+#    #+#             */
/*   Updated: 2024/03/12 13:26:20 by ede-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief alloc a set of memory cell and set them to 0
 *
 * @param nmemb number of memory cell
 * @param size size of the data
 * @return void*
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	if (nmemb && size && nmemb > (2147483647 / size))
		return (NULL);
	tab = malloc(nmemb * size);
	if (tab == NULL)
		return (NULL);
	ft_bzero(tab, size * nmemb);
	return (tab);
}
