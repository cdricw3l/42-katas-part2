/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:44:27 by ast               #+#    #+#             */
/*   Updated: 2025/04/18 21:05:14 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "init_network.h"

void *ft_destroy_mutexs(t_mutex ***mutexs, int len)
{
    int i;
    t_mutex **f;
    
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

t_mutex **init_mutex(int n)
{
    t_mutex **mutexs;
    int i;

    i = 0;

    if(n < 1)
        return(NULL);
    mutexs = malloc(sizeof(t_mutex *) * (n));
    while (i < n)
    {
        mutexs[i] = malloc(sizeof(t_mutex)  * 1);
        if(!mutexs[i] || pthread_mutex_init(mutexs[i], NULL) != 0)
        {
            printf("error\n");
            return(ft_destroy_mutexs(&mutexs, i));
        }
        i++;

    }
    return(mutexs);
}