/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:14:22 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/21 19:26:54 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thrd_manager.h"



int ft_destroy_mutext(mutex fork[N], int idx)
{
    int i;

    i = 0;
    while(i < idx)
    {
        assert(pthread_mutex_destroy(&fork[i]) == 0);
        i++;
    }
    return(0);
}

pthread_mutex_t *ft_create_arr_mutext(int n)
{
    int idx;
    pthread_mutex_t *arr;

    arr = malloc(sizeof(pthread_mutex_t) * n);
    if(!arr)
        return(NULL);
    idx = 0;
    while (idx < n)
    {
        if(pthread_mutex_init(&arr[idx],NULL) != 0)
        {
            ft_destroy_mutext(arr, idx);
            perror("Mutex error: ");
        }
        idx++;
    }
    return(arr);
}