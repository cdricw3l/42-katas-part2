/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_run_simulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:51:04 by ast               #+#    #+#             */
/*   Updated: 2025/05/26 08:59:16 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"

int run_philo(pthread_t threads[200], t_network **net)
{
    int i;
    long long start;
    t_network  *network;
    
    void *(*f_cycle)(void *p);
    network = *net;
    i = 0;
    start = get_current_time();
    if((*net)->pametres[CYCLE] == -1)
        f_cycle = thread_philo_infinit;
    else
        f_cycle = thread_philo_cycle;
    while (i < network->pametres[P])
    {
        network->philos[i]->start = start;
        if(pthread_create(&threads[i],NULL, f_cycle, network->philos[i]))
        {
            printf("Launch Error THREAD %d\n", network->philos[i]->pametres[ID]);
            return(0);
        }
        change_state(network->philos[i], network->philos[i]->pametres[STATE_1], ON);
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
    
    (void)monitiror;
    
    if(!philos_laucher(network, threads))
    {
        printf("Error thread philo launcher\n");
        return(0);
    }
    if(!monitor_launcher(network, &monitiror))
    {
        printf("Error thread monitor launcher\n");
        return(0);
    }
    
    if(!philos_joiner(network, threads))
    {
        printf("Error thread philo joiner\n");
        return(0);
    }
    else
        write(STDOUT_FILENO, "all philo are join\n", ft_strlen("all philo are join\n"));
    if(!monitor_joiner(&monitiror))
    {
        printf("Error thread monitor joiner\n");
        return(0);
    }
    
    
    //destroy_network(network);
    
    return(1);
}
