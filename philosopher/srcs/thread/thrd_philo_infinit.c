/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_philo_infinit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 09:15:58 by ast               #+#    #+#             */
/*   Updated: 2025/04/19 20:53:28 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "thread.h"

void    *thread_philo_infinit(void *p)
{
    TEST_START;
    
    t_philo *philo;
    int i;
    //long long last;

    philo = (t_philo *)p;    
    while (get_state(philo, philo->state_1) == OFF)
    {
        printf("philo %d is spleeping\n", philo->id);
        sleep(1);
    }
    while (get_state(philo, philo->state_1) == ON)
    {
        printf("I am The philosopher number %d \n", philo->id);
        sleep(1);
        i++;
    }
    printf("PHILO %d WAS KILLED\n", philo->id);
    TEST_SUCCES;
    return(p);
}
