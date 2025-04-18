/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:14:22 by cw3l              #+#    #+#             */
/*   Updated: 2025/04/18 13:56:18 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "thrd_manager.h"

int get_fork_number(t_philosophe *philosophe, int num_fork)
{
    int id;
    int fork;

    if(!philosophe || (num_fork < 1 && num_fork > 2))
        return(-1);
    id = philosophe->id;
    fork = 0;
    if(num_fork == 2)
    {

        if(philosophe->id == 0)
            fork = philosophe->network->n - 1;
        else
            fork = id;
    }
    else if(num_fork == 1)
    {
        if(philosophe->id == 0)
            fork = id;
        else
            fork = id - 1;
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