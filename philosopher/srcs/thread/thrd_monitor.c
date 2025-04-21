/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_monitor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 09:14:45 by ast               #+#    #+#             */
/*   Updated: 2025/04/21 09:50:59 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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

int  start_first_batch(t_network **net)
{
    int i;
    t_network *network;

    i = 0;
    network = *net;
    while (i < network->pametres[P])
    {
        if(i % 2 == 0 && i != 1)
        {
            if(pthread_mutex_lock(network->philos[i]->m_state))
            {
                printf("Erreur mutex state lock\n");
                return(0);    
            }
            printf("Launch Philosophe %d\n", network->philos[i]->pametres[ID]);
            network->philos[i]->pametres[STATE_1] = ON;
            if(pthread_mutex_unlock(network->philos[i]->m_state))
            {
                printf("Erreur mutex state unlock\n");
                return(0);
            }
        }
        i++;
    }
    return(i);
}

int  start_second_batch(t_network **net)
{
    int i;
    t_network *network;

    i = 0;
    network = *net;
    while (i < network->pametres[P])
    {
        if((i % 3 == 0 && i != 0) || i == 1)
        {
            if(pthread_mutex_lock(network->philos[i]->m_state))
            {
                printf("Erreur mutex state lock\n");
                return(0);    
            }
            printf("Launch Philosophe %d\n", network->philos[i]->pametres[ID]);
            network->philos[i]->pametres[STATE_1] = ON;
            if(pthread_mutex_unlock(network->philos[i]->m_state))
            {
                printf("Erreur mutex state unlock\n");
                return(0);
            }
        }
        i++;
    }
    return(i);
}

int are_alive(t_network *network)
{
    int i;

    i = 0;
    while (i < network->pametres[P])
    {
        if(get_state(network->philos[i], network->philos[i]->pametres[STATE_1]) == OFF && get_state(network->philos[i], network->philos[i]->pametres[STATE_2]) == 1)
            return(0);
        i++;
    }
    return(1);
}

void    *thread_monitor(void *p)
{
    t_network *network;
    
    network = *(t_network **)p;
    if(!start_first_batch((t_network **)p) || !start_second_batch((t_network **)p))
    {
        printf("Start philo error\n");
        return(NULL);
    }
    while (are_alive(network))
    {
        if(check_timestamp(network->philos, network->pametres[P]))
            printf("\033[0;32m" "everybody are alive\n" "\x1b[0m");
        else
            break;
    }
    kill_philos((t_network **)p);
    return(p);
}
