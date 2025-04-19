/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_monitor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 09:14:45 by ast               #+#    #+#             */
/*   Updated: 2025/04/19 23:17:40 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "thread.h"

int kill_philos(t_network **net)
{
    int i;
    t_network *network;

    i = 0;
    network = *net;
    while (i < network->n)
    {
        change_state(network->philos[i], network->philos[i]->state_1 ,OFF);
        i++;
    }
    return(i);
}

int  start_philo(t_network **net)
{
    int i;
    t_network *network;

    i = 0;
    network = *net;
    while (i < network->n)
    {
        if(pthread_mutex_lock(network->philos[i]->m_states))
        {
            printf("Erreur mutex state lock\n");
            return(0);    
        }
        network->philos[i]->state_1 = ON;
        printf("start philo %d, state %d\n", network->philos[i]->id, network->philos[i]->state_1);
        if(pthread_mutex_unlock(network->philos[i]->m_states))
        {
            printf("Erreur mutex state unlock\n");
            return(0);
        }
        i++;
    }
    return(i);
}

int are_alive(t_network *network)
{
    int i;

    i = 0;
    while (i < network->n)
    {
        if(get_state(network->philos[i], network->philos[i]->state_1) == OFF && get_state(network->philos[i], network->philos[i]->death_state) == 1)
            return(0);
        i++;
    }
    return(1);
}

void    *thread_monitor(void *p)
{
    t_network *network;
    
    network = *(t_network **)p;
    if(!start_philo((t_network **)p))
    {
        printf("Start philo error\n");
        return(NULL);
    }
    while (are_alive(network))
    {
        if(check_timestamp(network->philos, network->n))
            printf("\033[0;32m" "everybody are alive\n" "\x1b[0m");
        sleep(1);

    }
    kill_philos((t_network **)p);
    return(p);
}
