/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <ede-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:13:07 by ede-lang          #+#    #+#             */
/*   Updated: 2024/03/12 13:57:57 by ede-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief return a malloced copy of a string
 *
 * @param src
 * @return char*
 */
char	*ft_strdup(const char *src)
{
	char	*cp;
	int		i;

	i = 0;
	while (src[i])
		i++;
	cp = (char *)malloc((i + 1) * sizeof(char));
	if (cp == NULL)
		return (cp);
	i = 0;
	while (src[i])
	{
		cp[i] = src[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}
