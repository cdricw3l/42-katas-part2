/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_philo_cycle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 09:15:58 by ast               #+#    #+#             */
/*   Updated: 2025/04/19 23:17:57 by ast              ###   ########.fr       */
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
    while (get_state(philo, 0) == OFF)
    {
        printf("philo %d is spleeping\n", philo->id);
        sleep(1);
    }
    while (get_state(philo, 0) == ON && philo->cycle > i)
    {
        printf("I am The philosopher number, im eating %d ", philo->id);
        ft_temporisation(200, get_current_time());
        put_timestamp(philo);
        printf("Je rend la fork : %d,\n", philo->id);
        printf("Je rend la fork : %d,\n", philo->id);
        printf("Je vais me coucher\n");
        ft_temporisation(200, get_current_time());
        sleep(1);
        i++;
    }
    change_state(philo, philo->state_1, OFF);
    printf("\x1b[31m" "PHILO %d WAS KILLED\n" "\x1b[0m", philo->id);
    return(p);
}
