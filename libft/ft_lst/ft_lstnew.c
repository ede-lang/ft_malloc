/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <ede-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:31:44 by ede-lang          #+#    #+#             */
/*   Updated: 2024/03/12 13:23:12 by ede-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief create a new node
 *
 * @param content the content of the node
 * @return t_list*
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*chain;

	chain = malloc(sizeof(t_list));
	if (chain == NULL)
		return (NULL);
	chain->content = content;
	chain->next = NULL;
	return (chain);
}
