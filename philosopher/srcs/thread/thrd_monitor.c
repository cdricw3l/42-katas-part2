/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_monitor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 09:14:45 by ast               #+#    #+#             */
/*   Updated: 2025/04/19 17:44:52 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "thread.h"

void kill_philos(t_network **net)
{
    int i;
    t_network *network;

    i = 0;
    network = *net;
    while (i < network->n)
    {
        if(pthread_mutex_lock(network->philos[i]->m_states))
            printf("Erreur mutex state lock\n");
        network->philos[i]->state = OFF;
        if(pthread_mutex_unlock(network->philos[i]->m_states))
            printf("Erreur mutex state unlock\n");
        i++;
    }
}

void  start_philo(t_network **net)
{
    int i;
    t_network *network;

    i = 0;
    network = *net;
    while (i < network->n)
    {
        if(pthread_mutex_lock(network->philos[i]->m_states))
            printf("Erreur mutex state lock\n");
        network->philos[i]->state = ON;
        if(pthread_mutex_unlock(network->philos[i]->m_states))
            printf("Erreur mutex state unlock\n");
        i++;
    }
}

void    *thread_monitor(void *p)
{
    TEST_START;
    
    t_network *network;
    int i;

    i = 0;
    network = (t_network *)p;
    (void)network;
    while (i < 20)
    {
        printf("cycle %d\n\n", i);
        if(i == 10)
        {
            printf("start philo\n");
            start_philo((t_network **)p);
        }
        sleep(1);
        i++;
    }
    kill_philos((t_network **)p);
    
    TEST_SUCCES;
    return(p);
}
