/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 11:55:46 by ast               #+#    #+#             */
/*   Updated: 2025/04/20 12:44:05 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "thread.h"

int release_forks(t_philo *philo, long long timestamps)
{
    int err;
    int id;

    err = 0;
    id = philo->pametres[ID];
    if(pthread_mutex_unlock(philo->fork_1))
    {
        printf("%lld Philosopher %d error unlock fork 1\n", timestamps, id);
        err += 1;
    }
    else
        printf("%lld Philosopher %d has release fork 1\n",timestamps ,philo->pametres[ID]);
    if(pthread_mutex_unlock(philo->fork_2))
    {
        printf("%lld Philosopher %d error unlock fork 2\n", timestamps, id);
        err += 1;
    }
    else
        printf("%lld Philosopher %d has release fork 1\n",timestamps ,philo->pametres[ID]);
    if(err)
        return(0);
    return (1);
}

int get_forks(t_philo *philo, long long timestamps)
{
    if(pthread_mutex_lock(philo->fork_1))
        return(0);
    printf("%lld Philosopher %d has taken fork 1\n",timestamps, philo->pametres[ID]);
    if(pthread_mutex_lock(philo->fork_2))
    {
        if(pthread_mutex_unlock(philo->fork_1))
            printf("%lld Philosopher %d error unlock fork 1\n",timestamps, philo->pametres[ID]);
        else
            printf("%lld Philosopher %d has release fork 1\n",timestamps ,philo->pametres[ID]);
        return(0);
    }
    printf("%lld Philosopher %d has taken fork 2\n",timestamps ,philo->pametres[ID]);
    return (1);
}
