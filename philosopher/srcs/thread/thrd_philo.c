/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 09:15:58 by ast               #+#    #+#             */
/*   Updated: 2025/04/19 09:36:29 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "thread.h"

void    *thread_philo(void *p)
{
    TEST_START;
    
    t_philo *philo;
    int n;
    //int i;
    //long long last;

    philo = (t_philo *)p;
    n = philo->id;
    while (1)
    {
        printf("I am The philosopher number %d\n", n);
        sleep(1);
    }
    TEST_SUCCES;
    return(p);
}
