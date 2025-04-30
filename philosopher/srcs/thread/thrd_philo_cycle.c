/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_philo_cycle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 09:15:58 by ast               #+#    #+#             */
/*   Updated: 2025/04/27 18:12:14 by ast              ###   ########.fr       */
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
    start = get_current_time();
    last_eat = 0;
    while (get_state(philo, 0) == OFF)
    {
        printf("philo %d is OFF\n", philo->pametres[ID]);
    }
    while (get_state(philo, 0) == ON && philo->pametres[CYCLE] > i)
    {
        if(get_state(philo,0) == OFF)
        {
            printf("phillo is off\n");
        }
        if(i == 3 && philo->pametres[ID] == 1)
        {
            change_state(philo,0, OFF);
            printf("philo %d is off\n", philo->pametres[ID]);
        }
        put_timestamp(philo, TS_CYCLE,start);
        put_timestamp(philo, TS_START, start);
        philo->time_data[TS_LAST_EAT] = last_eat;
        while (!get_forks(philo, get_current_time() - start))
        {
            printf("Philo is thinking\n");
        }
        put_timestamp(philo, TS_END_THINK, start);
        if(philo->time_data[TS_END_THINK] - philo->time_data[TS_LAST_EAT] > philo->pametres[TTD] && i != 1)
        {
            printf("fonction will ending %lld and %d for philo %d\n", philo->time_data[TS_END_THINK] - philo->time_data[TS_LAST_EAT], philo->pametres[TTD], philo->pametres[ID]);
            display_philo_time_board(philo, philo->pametres[P]);
            philo->pametres[STATE_1] = 0;
            return(NULL);
        }
        ft_temporisation(philo->pametres[TTE], get_current_time());
        release_forks(philo,get_current_time() - start);
        put_timestamp(philo, TS_END_EAT, start);
        last_eat = philo->time_data[TS_END_EAT];
        ft_temporisation(philo->pametres[TTS], get_current_time());
        put_timestamp(philo, TS_END_SPLEEP, start);
        display_philo_time_board(philo, 1);

        i++;
    }
    change_state(philo, philo->pametres[STATE_1], OFF);
    printf("\x1b[31m" "PHILO %d WAS KILLED\n" "\x1b[0m", philo->pametres[ID]);
    return(p);
}
