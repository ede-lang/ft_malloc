/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <ede-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:30:27 by ede-lang          #+#    #+#             */
/*   Updated: 2024/03/12 11:51:32 by ede-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief search str, replace all occurences of "fromstr" by "tostr"
 * @brief str need to be malloc, and is free during execution
 * @param str string to be searched
 * @param fromstr string to find
 * @param tostr replace by
 * @return char*
 */
char	*ft_strrep(char *str, char *fromstr, char *tostr)
{
	char	*iterator;
	char	*tmp;
	char	*result;
	size_t	fromlen;

	fromlen = ft_strlen(fromstr);
	iterator = str;
	while (*iterator)
	{
		if (!ft_strncmp(iterator, fromstr, fromlen))
		{
			*iterator = 0;
			iterator += fromlen;
			result = ft_strjoin(str, tostr);
			tmp = result;
			result = ft_strjoin(result, iterator);
			free(tmp);
			free(str);
			return (ft_strrep(result, fromstr, tostr));
		}
		iterator++;
	}
	return (str);
}
