/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:14:22 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/25 22:06:02 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thrd_manager.h"

int get_fork_number(t_philosophe *philosophe, int num_fork)
{
    int id;
    int fork;
    int p;
    
    if(!philosophe)
        return(-1);
    id = philosophe->id;
    fork = 0;
    p = philosophe->network->p / philosophe->network->n - 1;
    if(num_fork == 1)
        fork = id + p + p * id;
    else if(num_fork == 2)
    {
        if(philosophe->id == 0)
            fork = philosophe->network->p - 1;
        else
            fork = (id - 1) + p + p * (id - 1);
    }
    return (fork);
}

int ft_destroy_mutext(pthread_mutex_t ***fork, int idx)
{
    int i;
    pthread_mutex_t **arr;

    i = 0;
    arr = *fork;
    if(arr)
    {
        while(i < idx)
        {
            if(arr[i])
            {
                if(pthread_mutex_destroy(arr[i]) != 0)
                    return(0);
                free(arr[i]);
                arr[i] = NULL;
            }
            i++;
        }
        free(*fork);
        *fork = NULL;
    }
    return(1);
}

pthread_mutex_t **ft_create_arr_mutext(int n)
{
    int idx;
    pthread_mutex_t **arr;

    arr = malloc(sizeof(pthread_mutex_t *) * n);
    if(!arr)
        return(NULL);
    idx = 0;
    while (idx < n)
    {
        arr[idx] = malloc(sizeof(pthread_mutex_t));
        if(!arr[idx] || pthread_mutex_init(arr[idx],NULL) != 0)
        {
            ft_destroy_mutext(&arr, idx);
            perror("Mutex error: ");
        }
        idx++;
    }
    return(arr);
}