/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <ede-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:05:08 by ede-lang          #+#    #+#             */
/*   Updated: 2024/03/12 11:50:45 by ede-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief delete all char before and after the string contained in set
 *
 * @param s1 string to trim
 * @param set set of char to delete
 * @return char*
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	len;
	char	*s;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1) - 1;
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (len && ft_strchr(set, s1[len]))
		len--;
	s = ft_substr(s1, start, len - start + 1);
	return (s);
}
