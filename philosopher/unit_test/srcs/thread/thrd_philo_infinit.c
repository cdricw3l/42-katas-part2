/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_philo_infinit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 09:15:58 by ast               #+#    #+#             */
/*   Updated: 2025/05/18 22:42:53 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"

void    *thread_philo_infinit(void *p)
{
    t_philo *philo;
    long long start;
    long long last_eat;
    
    philo = (t_philo *)p;
    while (get_state(philo, 0) == OFF)
	{
		ft_temporisation(500);
	}

    start = get_current_time();
    while (get_state(philo, 0) == ON)
    {
        put_timestamp(philo, TS_CYCLE, start);
        put_timestamp(philo, TS_START, start);
        philo->time_data[TS_LAST_EAT] = last_eat;
        while (!get_forks(philo))
        {
            safe_print(get_current_time() - start, philo, THINKING);
        }
        safe_print(get_current_time() - start, philo, TAKEN_FORK);
        safe_print(get_current_time() - start, philo, EATING);
        put_timestamp(philo, TS_END_THINK, start);
        if(philo->time_data[TS_END_THINK] - philo->time_data[TS_LAST_EAT] > philo->pametres[TTD])
        {
            printf("philo %d is die\n", philo->pametres[ID]);
            change_state(philo, 0, OFF);
            return(NULL);
        }
        ft_temporisation(philo->pametres[TTE]);
        put_timestamp(philo, TS_END_EAT, start);
        last_eat = philo->time_data[TS_END_EAT];
        release_forks(philo,get_current_time() - start);
        safe_print(get_current_time() - start, philo, RELEASE_FORK);
        safe_print(get_current_time() - start, philo, SLEEPING);
        ft_temporisation(philo->pametres[TTS]);
        put_timestamp(philo, TS_END_SPLEEP, start);
    }
    //display_philo_time_board(philo,1);

    change_state(philo, philo->pametres[STATE_1], OFF);
    printf("\x1b[31m" "PHILO %d WAS KILLED\n" "\x1b[0m", philo->pametres[ID]);
    return(p);
}
