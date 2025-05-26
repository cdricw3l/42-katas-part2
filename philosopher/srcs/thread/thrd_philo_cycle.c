/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_philo_cycle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 09:15:58 by ast               #+#    #+#             */
/*   Updated: 2025/05/26 09:00:12 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"

void decrease_counter(t_philo *philo)
{
    if(pthread_mutex_lock(philo->m_counter) == -1)
    {
        printf("mutex counter error\n");
        return ;
    }
    philo->cycle_counter--;
    if(pthread_mutex_unlock(philo->m_counter) == -1)
    {
        printf("mutex counter error\n");
    }
}

int get_cycle_counter(t_philo *philo)
{
    int c;
    
    if(pthread_mutex_lock(philo->m_counter) == -1)
    {
        printf("mutex counter error\n");
        return (-1);
    }
    c = philo->cycle_counter;
    if(pthread_mutex_unlock(philo->m_counter) == -1)
    {
        printf("mutex counter error\n");
        return (c) ;
    }
    return (c);
}

void    *thread_philo_cycle(void *p)
{
    t_philo *philo;
    int i;
    long long start;
    long long last_eat;
    
    philo = (t_philo *)p;
    i = 0;
    start = philo->start;
    while (get_state(philo, 0) == OFF)
    {
        ft_temporisation(10, 0);
    }
    while (get_state(philo, 0) == ON && philo->pametres[CYCLE] > i)
    {
        
        put_timestamp(philo, TS_CYCLE, start);
        put_timestamp(philo, TS_START, start);
        philo->time_data[TS_LAST_EAT] = last_eat;

        while (!get_forks(philo, get_current_time() - start))
        {
            safe_print(get_current_time() - start, philo, THINKING);
        }
        safe_print(get_current_time() - start, philo, TAKEN_FORK);
        safe_print(get_current_time() - start, philo, EATING);
        put_timestamp(philo, TS_END_THINK, start);
        
        if(philo->time_data[TS_END_THINK] - philo->time_data[TS_LAST_EAT] > philo->pametres[TTD])
        {
            printf("\x1b[31m" "PHILO %d IS DEAD, elapsed time: %lld, TTD : %d, counter %d \n" "\x1b[0m", philo->pametres[ID], philo->time_data[TS_END_THINK] - philo->time_data[TS_LAST_EAT],philo->pametres[TTD], get_cycle_counter(philo));
            safe_print(philo->start, philo,DEATH);
            change_state(philo, philo->pametres[STATE_2], OFF);
            return(NULL);
        }
            
        assert(philo->pametres[TTE] == 80);
        ft_temporisation(philo->pametres[TTE],0);

        put_timestamp(philo, TS_END_EAT, start);
        last_eat = philo->time_data[TS_END_EAT];
        release_forks(philo,get_current_time() - start);
        //safe_print(get_current_time() - start, philo, RELEASE_FORK);
        if(i < philo->pametres[CYCLE] - 1)
        {
            safe_print(get_current_time() - start, philo, SLEEPING);
            ft_temporisation(philo->pametres[TTS],0);
            put_timestamp(philo, TS_END_SPLEEP, start);
        }

        decrease_counter(philo);
        i++;
    }
    display_philo_time_board(philo,1);

    change_state(philo, philo->pametres[STATE_1], OFF);
    safe_print((get_current_time() - start), philo, DEATH);
    //printf("\x1b[31m" "PHILO %d WAS KILLED at cycle %d\n" "\x1b[0m", philo->pametres[ID], philo->cycle_counter);
    return(p);
}
