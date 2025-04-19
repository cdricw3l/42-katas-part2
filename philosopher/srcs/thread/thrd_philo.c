/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 09:15:58 by ast               #+#    #+#             */
/*   Updated: 2025/04/19 14:31:33 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "thread.h"

void    *thread_philo(void *p)
{
    TEST_START;
    
    t_philo *philo;
    //int i;
    //long long last;

    philo = (t_philo *)p;
    while (philo->state == OFF)
    {
        printf("philo %d is spleeping\n", philo->id);
        sleep(1);
    }
    
    while (philo->state == 1)
    {
        printf("I am The philosopher number %d \n", philo->id);
        sleep(1);
    }
    TEST_SUCCES;
    return(p);
}
