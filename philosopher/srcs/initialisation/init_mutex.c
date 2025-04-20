/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:44:27 by ast               #+#    #+#             */
/*   Updated: 2025/04/20 07:57:53 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "init_network.h"

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
t_mutex_data *init_mutex_struct(int n)
{
    t_mutex_data *mutex_data;

    mutex_data = malloc(sizeof(t_mutex_data) * 1);
    if(!mutex_data)
        return(NULL);
    mutex_data->forks = init_mutex(n);
    if(!mutex_data->forks)
    {
        free(mutex_data);
        return(NULL);
    }
    mutex_data->pens = init_mutex(n);
    if(!mutex_data->pens)
    {
        free(mutex_data);
        return(ft_destroy_mutexs(&fork, n));
    }
    mutex_data->m_states = init_mutex(n);
    if (!mutex_data->m_states)
    {
        free(mutex_data);
        ft_destroy_mutexs(&fork, n);
        return(ft_destroy_mutexs(&mutex_data->pens, n));
    }
    return(mutex_data);
}
