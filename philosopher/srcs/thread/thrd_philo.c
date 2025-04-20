/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 19:12:38 by ast               #+#    #+#             */
/*   Updated: 2025/04/20 09:27:24 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "thread.h"

int get_state(t_philo *philo, int state_type)
{
    int state;
    
    if(state_type == 0)
    {
        if(pthread_mutex_lock(philo->m_state))
            printf("Erreur mutex state lock\n");
        state = philo->pametres[STATE_1];
        if(pthread_mutex_unlock(philo->m_state))
            printf("Erreur mutex state unlock\n"); 
    }
    else if(state_type == 1)
    {
        if(pthread_mutex_lock(philo->m_state))
            printf("Erreur mutex state lock\n");
        state = philo->pametres[STATE_2];
        if(pthread_mutex_unlock(philo->m_state))
            printf("Erreur mutex state unlock\n"); 
    }
    return(state);
}

int change_state(t_philo *philo, int state_type, int state)
{

    if(state_type == 0)
    {
        if(pthread_mutex_lock(philo->m_state))
            printf("Erreur mutex state lock\n");
        philo->pametres[STATE_1] = state;
        if(pthread_mutex_unlock(philo->m_state))
            printf("Erreur mutex state unlock\n"); 
    }
    else if(state_type == 1)
    {
        if(pthread_mutex_lock(philo->m_state))
            printf("Erreur mutex state lock\n");
        philo->pametres[STATE_2] = state;
        if(pthread_mutex_unlock(philo->m_state))
            printf("Erreur mutex state unlock\n"); 
    }
    return(state);
}