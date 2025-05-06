/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_monitor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 09:14:45 by ast               #+#    #+#             */
/*   Updated: 2025/04/30 12:47:33 by ast              ###   ########.fr       */
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
            ft_temporisation(500,0);
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
        if(get_state(network->philos[i], network->philos[i]->pametres[STATE_1]) == OFF)
            return(0);
        i++;
    }
    return(1);
}

void    *thread_monitor(void *p)
{
    t_network *network;
    int i;
    (void)network;
    i = 1;
    network = *(t_network **)p;
    if(!start_first_batch((t_network **)p) || !start_second_batch((t_network **)p))
    {
        printf("Start philo error\n");
        return(NULL);
    }
    while (i == 1)
    {
        i = are_alive(network);
        if(i == 0)
        {
            int j = 0;
            while (j < network->pametres[P])
            {
                change_state(network->philos[j], 0,OFF);
                printf("shutdown philo %d\n", j);
                j++;
            }
            return(p);
        }
    }
    return(p);
}
