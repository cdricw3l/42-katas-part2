/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 11:55:46 by ast               #+#    #+#             */
/*   Updated: 2025/04/25 23:33:33 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "thread.h"

int get_fork_number(t_philo *philo, int fork_number)
{
    int id;
    int n_philo;

    id = philo->pametres[ID];
    n_philo = philo->pametres[P];
    if(id == 0)
    {
        if(fork_number == 1)
            return(id);
        if(fork_number == 2)
            return(n_philo - 1);
        
    }
    else if(id > 0)
    {
        if(fork_number == 1)
            return(id - 1); 
        if(fork_number == 2)
            return(id);  
    }
    
    return(-1);
}

int release_forks(t_philo *philo, long long timestamps)
{
    int err;
    //int id;
    //int fork_1;
    //int fork_2;
    
    (void)timestamps;
    //fork_1 = get_fork_number(philo,1);
    //fork_2 = get_fork_number(philo,2);
    err = 0;
    //id = philo->pametres[ID];
    if(pthread_mutex_unlock(philo->fork_1))
    {
        //printf("%lld Philosopher %d error unlock fork %d\n", timestamps, id, fork_1);
        err += 1;
    }
    else
        //printf("%lld Philosopher %d has release fork %d\n",timestamps ,philo->pametres[ID], fork_1);
    if(pthread_mutex_unlock(philo->fork_2))
    {
        //printf("%lld Philosopher %d error unlock fork %d\n", timestamps, id, fork_2);
        err += 1;
    }
    else
        //printf("%lld Philosopher %d has release fork %d\n",timestamps ,philo->pametres[ID], fork_2);
    if(err)
        return(0);
    return (1);
}




int get_forks(t_philo *philo, long long timestamps)
{

    int fork_1;
    int fork_2;
    

    fork_1 = get_fork_number(philo,1);
    fork_2 = get_fork_number(philo,2);
    (void)timestamps;
    if(pthread_mutex_lock(philo->fork_1))
        return(0);
    printf("%lld Philosopher %d has taken fork %d\n",timestamps, philo->pametres[ID], fork_1);
    if(pthread_mutex_lock(philo->fork_2))
    {
        if(pthread_mutex_unlock(philo->fork_1))
            printf("%lld Philosopher %d error unlock fork %d\n",timestamps, philo->pametres[ID], fork_1);
        else
            printf("%lld Philosopher %d has release fork %d\n",timestamps ,philo->pametres[ID], fork_1);
        return(0);
    }
    printf("%lld Philosopher %d has taken fork %d\n",timestamps ,philo->pametres[ID], fork_2);
    return (1);
}
