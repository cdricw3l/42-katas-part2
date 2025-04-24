/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_philo_cycle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 09:15:58 by ast               #+#    #+#             */
/*   Updated: 2025/04/24 08:39:03 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"

void    *thread_philo_cycle(void *p)
{
    t_philo *philo;
    int i;

    philo = (t_philo *)p;
    i = 0;
    while (get_state(philo, 0) == OFF)
    {
        printf("philo %d is OFF\n", philo->pametres[ID]);
    }
    while (get_state(philo, 0) == ON && philo->pametres[CYCLE] > i)
    {
        put_timestamp(philo, TS_END_THINK, get_current_time());
        while (!get_forks(philo, get_current_time()))
        {
            printf("Philo is thinking\n");
        }
        put_timestamp(philo, TS_START,get_current_time());
        put_timestamp(philo, TS_CYCLE,get_current_time());
        ft_temporisation(philo->pametres[TTE], get_current_time());
        put_timestamp(philo, TS_END_EAT, get_current_time());
        ft_temporisation(philo->pametres[TTS], get_current_time());
        put_timestamp(philo, TS_END_SPLEEP, get_current_time());
        i++;
    }
    change_state(philo, philo->pametres[STATE_1], OFF);
    printf("\x1b[31m" "PHILO %d WAS KILLED\n" "\x1b[0m", philo->pametres[ID]);
    return(p);
}
