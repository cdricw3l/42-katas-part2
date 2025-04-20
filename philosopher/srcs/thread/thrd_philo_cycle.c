/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_philo_cycle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 09:15:58 by ast               #+#    #+#             */
/*   Updated: 2025/04/20 12:48:00 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "thread.h"

void    *thread_philo_cycle(void *p)
{
    t_philo *philo;
    int i;
    //long long last;

    philo = (t_philo *)p;
    i = 0;
    // while (get_state(philo, 0) == OFF)
    // {
    //     printf("philo %d is OFF\n", philo->pametres[ID]);
    //     sleep(1);
    // }
    while (get_state(philo, 0) == OFF && philo->pametres[CYCLE] > i)
    {
        long long start = get_current_time();
        while (!get_forks(philo, get_current_time()))
        {
            printf("%lld Philo is thinking\n",  start);
        }
        printf("%lld Philo %d is eating\n", start,philo->pametres[ID] );
        ft_temporisation(philo->pametres[TTE], get_current_time());
        release_forks(philo, start);
        put_timestamp(philo);
        ft_temporisation(philo->pametres[TTS], get_current_time());
        i++;
    }
    change_state(philo, philo->pametres[STATE_1], OFF);
    printf("\x1b[31m" "PHILO %d WAS KILLED\n" "\x1b[0m", philo->pametres[ID]);
    return(p);
}
