/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <ede-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:58:24 by ede-lang          #+#    #+#             */
/*   Updated: 2024/03/12 13:10:22 by ede-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief get list and new node, append node at the end of the list
 *
 * @param lst list
 * @param new node to push
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*it;

	if (lst)
	{
		if (!*lst)
			*lst = new;
		else
		{
			it = ft_lstlast(*lst);
			it->next = new;
		}
	}
}
