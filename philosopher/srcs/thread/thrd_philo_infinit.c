/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_philo_infinit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 09:15:58 by ast               #+#    #+#             */
/*   Updated: 2025/05/27 20:44:19 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"

void    *thread_philo_infinit(void *p)
{
    t_philo *philo;
    long long start;
    long long last_eat;
    

    philo = (t_philo *)p;
    start = philo->start;
    while (get_state(philo, 0) == OFF)
    {
        ft_temporisation(10, 0);
    }
    while (get_state(philo, 0) == ON)
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
            change_state(philo, 0, OFF);
            //printf("\x1b[31m" "PHILO %d IS DEAD, elapsed time: %lld, TTD : %d\n" "\x1b[0m", philo->pametres[ID], philo->time_data[TS_END_THINK] - philo->time_data[TS_LAST_EAT],philo->pametres[TTD]);
            return(NULL);
        }
            
        ft_temporisation(philo->pametres[TTE],0);
        put_timestamp(philo, TS_END_EAT, start);
        last_eat = philo->time_data[TS_END_EAT];
        release_forks(philo,get_current_time() - start);
        safe_print(get_current_time() - start, philo, RELEASE_FORK);
        safe_print(get_current_time() - start, philo, SLEEPING);
        ft_temporisation(philo->pametres[TTS],0);
        put_timestamp(philo, TS_END_SPLEEP, start);
    }
    display_philo_time_board(philo,1);

    change_state(philo, philo->pametres[STATE_1], OFF);
    printf("\x1b[31m" "PHILO %d WAS KILLED\n" "\x1b[0m", philo->pametres[ID]);
    return(p);
}
