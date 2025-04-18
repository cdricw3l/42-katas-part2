/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_network.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 06:06:02 by ast               #+#    #+#             */
/*   Updated: 2025/04/18 06:48:51 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "init_network.h"

void *ft_destroy_mutexs(mutex_t ***mutexs, int len)
{
    int i;
    mutex_t **f;
    
    i = 0;
    while (i < len)
    {
        if(f[i])
        {
            free(f[i]);
            f[i] == NULL;
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
    if(n != 1)
        return(NULL);
    mutexs = ft_c(sizeof(mutex_t *) * (n));
    while (i < n)
    {
        if(pthread_mutex_init(mutexs[i],NULL) != 0)
            return(ft_destroy_fork(&mutexs, i));
        i++;
    }
    return(mutexs);
}

t_network *create_network(int *args)
{
	mutex_t     **forks;
	mutex_t     **pens;
    t_philo     **philos;
    t_network   *network;

    forks = init_mutex(args[0]);
    if(!forks)
        return(NULL);
    pens = init_mutex(args[0]);
    if(!pens)
        return(ft_destroy_mutexs(forks, args[P]));
    philos = init_philos();
    if(!philos)
    {
        ft_destroy_mutexs(forks, args[P]);
        return(ft_destroy_mutexs(pens, args[P]));
    }
    
}
