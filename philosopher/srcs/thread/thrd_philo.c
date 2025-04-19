/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 09:15:58 by ast               #+#    #+#             */
/*   Updated: 2025/04/19 17:43:36 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "thread.h"

int get_state(t_philo *philo)
{
    int state;

    if(pthread_mutex_lock(philo->m_states))
            printf("Erreur mutex state lock\n");
    state = philo->state;
    if(pthread_mutex_unlock(philo->m_states))
        printf("Erreur mutex state unlock\n");
    return(state);
}

void    *thread_philo(void *p)
{
    TEST_START;
    
    t_philo *philo;
    //int i;
    //long long last;

    philo = (t_philo *)p;    
    while (get_state(philo) == OFF)
    {
        printf("philo %d is spleeping\n", philo->id);
        sleep(1);
    }
    while (get_state(philo) == ON)
    {
        printf("I am The philosopher number %d \n", philo->id);
        sleep(1);
    }
    printf("PHILO %d WAS KILLED\n", philo->id);
    TEST_SUCCES;
    return(p);
}
