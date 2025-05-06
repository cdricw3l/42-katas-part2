/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:44:27 by ast               #+#    #+#             */
/*   Updated: 2025/04/30 07:06:44 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "init_network.h"

t_mutex *init_mutex(void)
{
    t_mutex *mut;

    mut = malloc(sizeof(t_mutex) * 1);
    if(!mut || pthread_mutex_init(mut, NULL) != 0)
    {
        printf("error\n");
        return(NULL);
    }
    return(mut);
}

t_mutex **init_mutex_arr(int n)
{
    t_mutex **mutexs;
    int i;

    i = 0;

    if(n < 1)
        return(NULL);
    mutexs = malloc(sizeof(t_mutex *) * (n));
    while (i < n)
    {
        mutexs[i] = init_mutex();
        if(!mutexs[i])
            return(ft_destroy_mutexs(&mutexs,i));
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
    mutex_data->forks = init_mutex_arr(n);
    if(!mutex_data->forks)
    {
        free(mutex_data);
        return(NULL);
    }
    mutex_data->pens = init_mutex_arr(n);
    if(!mutex_data->pens)
    {
        ft_destroy_mutexs(&mutex_data->forks, n);
        free(mutex_data);
        return(NULL);
    }
    mutex_data->m_states = init_mutex_arr(n);
    if (!mutex_data->m_states)
    {
        ft_destroy_mutexs(&mutex_data->forks, n);
        ft_destroy_mutexs(&mutex_data->pens, n);
        free(mutex_data);
        return(NULL);
    }
    mutex_data->print = init_mutex();
    return(mutex_data);
}
