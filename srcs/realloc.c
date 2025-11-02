/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <ede-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:25:11 by ede-lang          #+#    #+#             */
/*   Updated: 2025/10/30 12:13:07 by ede-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void *realloc(void *ptr, size_t size)
{
    if (!ptr)
        return malloc(size);

    if (size == 0)
    {
        free(ptr);
        return NULL;
    }

    pthread_mutex_lock(&g_malloc_mutex);
    size = ALIGN16(size);
    t_block *block = (t_block *)ptr - 1;

    if (block->size >= size)
    {
        pthread_mutex_unlock(&g_malloc_mutex);
        return ptr;
    }

    pthread_mutex_unlock(&g_malloc_mutex);

    void *new_ptr = malloc(size);
    if (new_ptr)
    {
        ft_memcpy(new_ptr, ptr, block->size);
        free(ptr);
    }

    return new_ptr;
}