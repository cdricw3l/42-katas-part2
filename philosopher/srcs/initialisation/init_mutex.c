/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:44:27 by ast               #+#    #+#             */
/*   Updated: 2025/04/18 20:08:09 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "init_network.h"

void *ft_destroy_mutexs(mutex_t ***mutexs, int len)
{
    int i;
    mutex_t **f;
    
    i = 0;
    f = *mutexs;
    while (i < len)
    {
        if(f[i])
        {
            if(pthread_mutex_destroy(f[i]) != 0)
                printf("Mutex destroy err");
            free(f[i]);
            f[i] = NULL;
        }
        i++;
    }
    free(*mutexs);
    *mutexs = NULL;
    return(NULL);
}

mutex_t **init_mutex(int n)
{
    mutex_t **mutexs;
    int i;

    i = 0;
    if(n < 1)
        return(NULL);
    mutexs = malloc(sizeof(mutex_t *) * (n));
    while (i < n)
    {
        if(pthread_mutex_init(mutexs[i],NULL) != 0)
            return(ft_destroy_mutexs(&mutexs, i));
        i++;
    }
    return(mutexs);
}