/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_run_simulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:51:04 by ast               #+#    #+#             */
/*   Updated: 2025/04/20 09:18:44 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "thread.h"

int run_philo(pthread_t threads[200], t_network **net)
{
    int i;
    t_network  *network;
    
    void *(*f_cycle)(void *p);
    network = *net;
    i = 0;
    if((*net)->pametres[CYCLE] == -1)
    {
        f_cycle = thread_philo_infinit;
        printf("Le thread sera cyclique\n");
    }
    else
    {
        f_cycle = thread_philo_cycle;
        printf("Le thread sera cyclique\n");
    }
    while (i < network->pametres[P])
    {
        if(i % 2 == 0 && i != 1)
        {
            if(pthread_create(&threads[i],NULL, f_cycle, network->philos[i]))
                return(0);
            else
                printf("lauch %d\n", network->philos[i]->pametres[ID]);
            sleep(1);
        }
        i++;
    }
    i = 0;
    while (i < network->pametres[P])
    {
        if((i % 3 == 0 && i != 0) || i == 1)
        {
            if(pthread_create(&threads[i],NULL,f_cycle, network->philos[i]))
                return(0);
            else
            {
                printf("lauch %d\n", network->philos[i]->pametres[ID]);
            }
        }
        sleep(1);
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

int philos_laucher(t_network **net, pthread_t threads[200])
{
    
    if(!run_philo(threads, net))
        return(0);
   
    return(1);
}

int philos_joiner(t_network **net, pthread_t threads[200])
{
    
    if(!join_philos(threads, (*net)->pametres[P]))
        return(0);
   
    return(1);
}


int monitor_launcher(t_network **network, pthread_t *monitiror)
{


    if(pthread_create(monitiror, NULL, thread_monitor, network))
    {
        printf("error\n");
        return(0);
    }
    return(1);
}

int monitor_joiner(pthread_t *monitiror)
{

    if(pthread_join(*monitiror, NULL))
    {
        printf("error\n");
        return(0);
    }
    return(1);
}

int run_simulation(t_network **network)
{

    pthread_t monitiror;
    pthread_t threads[200];
    

    if(!monitor_launcher(network, &monitiror))
    {
        printf("Error thread monitor launcher\n");
        return(0);
    }
    if(!philos_laucher(network, threads))
    {
        printf("Error thread philo launcher\n");
        return(0);
    }
    if(!monitor_joiner(&monitiror))
    {
        printf("Error thread monitor joiner\n");
        return(0);
    }
    if(!philos_joiner(network, threads))
    {
        printf("Error thread philo joiner\n");
        return(0);
    }
    return(1);
}
