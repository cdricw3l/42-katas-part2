/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_monitor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 09:14:45 by ast               #+#    #+#             */
/*   Updated: 2025/05/28 06:47:04 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"

int kill_philos(t_network **net)
{
    int i;
    t_network *network;

    i = 0;
    network = *net;
    while (i < network->pametres[P])
    {
        change_state(network->philos[i], network->philos[i]->pametres[STATE_1] ,OFF);
        i++;
    }
    return(i);
}



int are_alive(t_network *network)
{
    int i;
    int k;

    i = 0;
    k = 0;
    while (i < network->pametres[P])
    {
        if(pthread_mutex_lock(network->philos[i]->m_state))
            printf("Erreur mutex state lock\n");
        if(get_state(network->philos[i], network->philos[i]->pametres[STATE_2]))
        {
            safe_print(get_current_time() - network ->philos[i]->start, network ->philos[i] ,DEATH_2);
            return(0);
        }
        if(get_state(network->philos[i], network->philos[i]->pametres[STATE_1]) == OFF && network->philos[i]->cycle_counter == 0)
        {
            if(pthread_mutex_unlock(network->philos[i]->m_state))
                printf("Erreur mutex state unlock\n"); 
            return(0);
        }
        if(get_state(network->philos[i], network->philos[i]->pametres[STATE_1]) == OFF)
        {
            printf("voici k %d \n", k);
            k++;
        }
        if(k == network->pametres[P])
        {
            printf("all philosophe make cycle\n");
            if(pthread_mutex_unlock(network->philos[i]->m_state))
                printf("Erreur mutex state unlock\n"); 
            return(0);
        }
        if(pthread_mutex_unlock(network->philos[i]->m_state))
            printf("Erreur mutex state unlock\n"); 
        i++;
    }
    return(1);
}

void    *thread_monitor(void *p)
{
    t_network *network;
    int i;
    int k;
    (void)network;
    i = 1;
    network = *(t_network **)p;
    
    k = 0;
    while (i == 1)
    {
        printf("simulation of satttttt\n");
        if(i == 0 || k == 3)
        {
            assert(1 == 2);
            printf("error philo is deqth");
            assert(1 == 1);
            int j = 0;
            while (j < network->pametres[P])
            {
                change_state(network->philos[j], 0,OFF);
                j++;
            }
            return(p);
        }
        i++;
        k++;
    }
    return(p);
}
