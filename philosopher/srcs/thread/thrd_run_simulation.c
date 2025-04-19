/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_run_simulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:51:04 by ast               #+#    #+#             */
/*   Updated: 2025/04/19 09:37:18 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "thread.h"

static int run_philo(pthread_t threads[200], t_network **net)
{
    int i;
    t_network  *network;

    network = *net;
    i = 0;
    while (i < network->n)
    {
        if(i % 2 == 0 && i != 1)
        {
            if(pthread_create(&threads[i],NULL, thread_philo, network->philos[i]))
                return(0);
            else 
                printf("lauch %d\n", network->philos[i]->id);
        }
        i++;
    }
    i = 0;
    while (i < network->n)
    {
        if((i % 3 == 0 && i != 0) || i == 1)
        {
            if(pthread_create(&threads[i],NULL,thread_philo, network->philos[i]))
                return(0);
            else 
                printf("lauch %d\n", network->philos[i]->id);
        }
        i++;
    }
    return(1);
}

int join_philos(pthread_t *threads, int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        if(pthread_join(threads[i], NULL))
            return(0);
        i++;
    }
    return (1);
}

int philos_laucher(t_network **net)
{
    pthread_t threads[200];
    
    if(run_philo(threads, net))
        return(0);
    if(join_philos(threads, (*net)->n))
        return(0);
    return(1);
}

int monitor_launcher(t_network **network)
{
    pthread_t monitiror;

    if(pthread_create(&monitiror, NULL, thread_monitor, *network))
    {
        printf("error\n");
        return(0);
    }
    if(pthread_join(monitiror, NULL))
    {
        printf("error\n");
        return(0);
    }
    return(1);
}

int run_simulation(t_network **network)
{
    // if(!monitor_launcher(network))
    // {
    //     printf("Error thread launcher\n");
    //     return(0);
    //     printf("end threa   d\n");
    // }
    if(!philos_laucher(network))
    {
        printf("Error thread launcher\n");
        return(0);
    }
    
    return(1);
}