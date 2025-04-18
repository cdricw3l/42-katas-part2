/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_network.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 06:06:02 by ast               #+#    #+#             */
/*   Updated: 2025/04/18 12:57:20 by ast              ###   ########.fr       */
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

void *ft_destroy_philos(t_philo ***philos, int len)
{
    int i;
    t_philo **p;

    i = 0;
    p = *philos;
    while (i < len)
    {
        free(p[i]);
        p[i] = NULL;
        i++;
    }
    free(*philos);
    return(NULL);
}

t_philo **init_philos(int *params, mutex_t **forks, mutex_t **pens)
{
    int     n;
    int     i;
    t_philo **philos;

    n = params[P];
    i = 0;
    philos = malloc(sizeof(t_philo *) * n);
    if(!philos)
        return(NULL);
    while (i < n)
    {
        philos[i] = malloc(sizeof(t_philo) * 1);
        if(!philos[i])
            return(ft_destroy_philos(&philos, i));
        philos[i]->id = i;
        philos[i]->tte = params[TTE];
        philos[i]->tts = params[TTS];
        philos[i]->state = OFF;
        philos[i]->cycle = params[CYCLE];
        philos[i]->meal_time_data = NULL;
        philos[i]->fork_1 = forks[i];
        philos[i]->fork_2 = ;
        philos[i]->pen = pens[i];

    }
        
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

t_network *create_network(int *params)
{
	mutex_t     **forks;
	mutex_t     **pens;
    t_philo     **philos;
    t_network   *network;

    forks = init_mutex(params[P]);
    if(!forks)
        return(NULL);
    pens = init_mutex(params[P]);
    if(!pens)
        return(ft_destroy_mutexs(forks, params[P]));
    philos = init_philos(params, forks, pens);
    if(!philos)
    {
        ft_destroy_mutexs(forks, params[P]);
        return(ft_destroy_mutexs(pens, args[P]));
    }
    
}
