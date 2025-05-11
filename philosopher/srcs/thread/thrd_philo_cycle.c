/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_philo_cycle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 09:15:58 by ast               #+#    #+#             */
/*   Updated: 2025/05/11 06:10:32 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "thread.h"

void    *thread_philo_cycle(void *p)
{
    t_philo *philo;
    int i;
    long long start;
    long long last_eat;
    
    philo = (t_philo *)p;
    i = 0;
    while (get_state(philo, 0) == OFF)
    {
        usleep(500);
    }
    start = get_current_time();
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
            change_state(philo, 0, OFF);
            //printf("\x1b[31m" "PHILO %d IS DEAD, elapsed time: %lld, TTD : %d\n" "\x1b[0m", philo->pametres[ID], philo->time_data[TS_END_THINK] - philo->time_data[TS_LAST_EAT],philo->pametres[TTD]);
            return(NULL);
        }
            
        ft_temporisation(philo->pametres[TTE],0);
        put_timestamp(philo, TS_END_EAT, start);
        last_eat = philo->time_data[TS_END_EAT];
        release_forks(philo,get_current_time() - start);
        //safe_print(get_current_time() - start, philo, RELEASE_FORK);
        safe_print(get_current_time() - start, philo, SLEEPING);
        ft_temporisation(philo->pametres[TTS],0);
        put_timestamp(philo, TS_END_SPLEEP, start);
        i++;
    }
    display_philo_time_board(philo,1);

    change_state(philo, philo->pametres[STATE_1], OFF);
    printf("\x1b[31m" "PHILO %d WAS KILLED\n" "\x1b[0m", philo->pametres[ID]);
    return(p);
}
