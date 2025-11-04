/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <ede-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:53:41 by ede-lang          #+#    #+#             */
/*   Updated: 2024/03/12 11:50:40 by ede-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	unsigned int	i;
	unsigned int	y;

	i = 0;
	if (find[0] == '\0')
		return ((char *)str);
	if (!len)
		return (NULL);
	while (str[i] && i < len)
	{
		y = 0;
		while (str[i + y] == find[y] && i + y < len)
		{
			if (find[y + 1] == '\0')
				return ((char *)&str[i]);
			else
				y++;
		}
		i++;
	}
	return (NULL);
}
