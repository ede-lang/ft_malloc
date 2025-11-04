/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <ede-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:50:40 by ede-lang          #+#    #+#             */
/*   Updated: 2025/11/04 16:44:40 by ede-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
// #include <stdlib.h>
#include <string.h>
#include "ft_malloc.h"

int main(void)
{
    printf("=== Test malloc ===\n");
    char *str = malloc(20);
    if (!str)
    {
        perror("malloc failed");
        return 1;
    }
    strcpy(str, "Hello malloc!");
    printf("str = \"%s\"\n", str);

    printf("\n=== Test realloc (agrandir) ===\n");
    char *re = realloc(str, 40);
    if (!re)
    {
        perror("realloc failed");
        free(str);
        return 1;
    }
    strcat(re, " (realloc OK)");
    printf("re = \"%s\"\n", re);

    printf("\n=== Test calloc ===\n");
    int *arr = calloc(5, sizeof(int));
    if (!arr)
    {
        perror("calloc failed");
        free(re);
        return 1;
    }
    printf("calloc 5 ints: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("\n=== Test realloc (rétrécir) ===\n");
    re = realloc(re, 10);
    if (!re)
    {
        perror("realloc failed (shrink)");
        free(arr);
        return 1;
    }
    printf("re (after shrink) = \"%s\"\n", re);
    
    printf("printing details :\n");
    // ft_show_alloc_mem();
    // ft_show_alloc_mem_ex();

    printf("\n=== Test free ===\n");
    free(arr);
    free(re);
    
    printf("All tests done!\n");

    // ft_show_alloc_mem_ex();

    return 0;
}
