/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 19:12:38 by ast               #+#    #+#             */
/*   Updated: 2025/04/19 20:25:42 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "thread.h"

int get_state(t_philo *philo, int state_type)
{
    int state;
    
    if(state_type == 0)
    {
        if(pthread_mutex_lock(philo->m_states))
            printf("Erreur mutex state lock\n");
        state = philo->state_1;
        if(pthread_mutex_unlock(philo->m_states))
            printf("Erreur mutex state unlock\n"); 
    }
    else if(state_type == 1)
    {
        if(pthread_mutex_lock(philo->m_states))
            printf("Erreur mutex state lock\n");
        state = philo->death_state;
        if(pthread_mutex_unlock(philo->m_states))
            printf("Erreur mutex state unlock\n"); 
    }
    return(state);
}

int change_state(t_philo *philo, int state_type, int state)
{

    if(state_type == 0)
    {
        if(pthread_mutex_lock(philo->m_states))
            printf("Erreur mutex state lock\n");
        philo->state_1 = state;
        if(pthread_mutex_unlock(philo->m_states))
            printf("Erreur mutex state unlock\n"); 
    }
    else if(state_type == 1)
    {
        if(pthread_mutex_lock(philo->m_states))
            printf("Erreur mutex state lock\n");
        philo->death_state = state;
        if(pthread_mutex_unlock(philo->m_states))
            printf("Erreur mutex state unlock\n"); 
    }
    return(state);
}