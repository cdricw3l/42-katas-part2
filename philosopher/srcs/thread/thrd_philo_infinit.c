/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_philo_infinit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 09:15:58 by ast               #+#    #+#             */
/*   Updated: 2025/04/20 23:09:14 by ast              ###   ########.fr       */
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
    while (get_state(philo, philo->pametres[STATE_1]) == OFF)
    {
        printf("philo %d is spleeping\n", philo->pametres[ID]);
    }
    while (get_state(philo, philo->pametres[STATE_1]) == ON)
    {
        printf("I am The philosopher number %d \n", philo->pametres[ID]);
        i++;
    }
    printf("PHILO %d WAS KILLED\n", philo->pametres[ID]);
    TEST_SUCCES;
    return(p);
}
