/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_monitor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 09:14:45 by ast               #+#    #+#             */
/*   Updated: 2025/04/19 09:17:08 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "thread.h"

void    *thread_monitor(void *p)
{
    TEST_START;
    
    t_network *network;
    int n;
    int i;
    long long last;

    network = (t_network *)p;
    n = network->n;
    while (1)
    {
        i = 0;
        while (i < n)
        {
            last = get_current_time();
            printf("last meal for philo do %d: %lld. State :%d\n",network->philos[i]->id, last, network->philos[i]->state);
            i++;
        }
        sleep(1);
    }
    TEST_SUCCES;
    return(p);
}
