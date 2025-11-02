/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <ede-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:51:20 by ede-lang          #+#    #+#             */
/*   Updated: 2025/10/30 11:59:54 by ede-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/mman.h>
# include <sys/resource.h>
# include "libft.h"

# define TINY_MAX 128
# define SMALL_MAX 1024
# define PAGE_SIZE getpagesize()
# define ALIGN16(x) (((x) + 15) & ~15)

typedef enum e_zone_type {
    TINY,
    SMALL,
    LARGE
} t_zone_type;

typedef struct s_block {
    size_t size;
    int free;
    struct s_block *next;
} t_block;

typedef struct s_zone {
    t_zone_type type;
    size_t size;
    struct s_zone *next;
    t_block *blocks;
    void *mem;
} t_zone;

extern t_zone *g_zones;
extern pthread_mutex_t g_malloc_mutex;

int is_debug_mode(void);
void   *allocate_in_zone(t_zone_type type, size_t size);
void   *allocate_large(size_t size);

void			*malloc(size_t size);
void			free(void *ptr);
void			*calloc(size_t num, size_t size);
void			*realloc(void *ptr, size_t size);
void			show_alloc_mem(void);

#endif