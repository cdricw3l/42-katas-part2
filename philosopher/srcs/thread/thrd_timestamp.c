/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_timestamp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:52:01 by ast               #+#    #+#             */
/*   Updated: 2025/04/20 11:45:18 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "thread.h"

int put_timestamp(t_philo *philo)
{
    //long long current_time;

    //current_time = get_current_time();
    if(pthread_mutex_lock(philo->pen))
    {
        printf("Erreur mutex state lock\n");
        return(0);
    }
    philo->meal_time_data[philo->pametres[ID]] = get_current_time();
    if(pthread_mutex_unlock(philo->pen))
    {
        printf("Erreur mutex state lock\n");
        return(0);
    }
    return(1);
}

int check_timestamp(t_philo **philo, int n)
{
    long long current_time;
    long long last_philo_eat;
    int i;

    i= 0;
    current_time = get_current_time();
    while (i < n)
    {
        if(pthread_mutex_lock(philo[i]->pen))
        {
            printf("Erreur mutex state lock\n");
            return(0);
        }
        last_philo_eat = philo[i]->meal_time_data[philo[i]->pametres[ID]];
        printf("voici le resqulta du check en ms : % lld, %d\n", current_time - last_philo_eat, philo[i]->pametres[TTD]+5);
        if(current_time - last_philo_eat > philo[i]->pametres[TTD] + 5)
        {
            printf("TIME SIMULATION ERREUR\n");
            if(pthread_mutex_unlock(philo[i]->pen))
                printf("Erreur mutex state lock\n");
            return(0);
        }
        if(pthread_mutex_unlock(philo[i]->pen))
        {
            printf("Erreur mutex state lock\n");
            return(0);
        }
        i++;
    }
    return(1);
}
long long get_timestamp(t_philo *philo)
{

    long long timestamp;
    int id;

    id = philo->pametres[ID];
    if(pthread_mutex_lock(philo->pen))
    {
        printf("Erreur mutex state lock\n");
        return(0);
    }
    timestamp = philo->meal_time_data[id];
    if(pthread_mutex_lock(philo->pen))
    {
        printf("Erreur mutex state lock\n");
        return(0);
    }
    return(timestamp);
}

long long get_current_time(void)
{
    struct timeval time;

    if (gettimeofday(&time, NULL) == -1)
        write(2, "gettimeofday() error\n", 22);
    return ((long long)time.tv_sec * 1000 + time.tv_usec / 1000);
}

void ft_temporisation(int ms, long long start)
{
    
	while ((get_current_time() - start) < ms)
        usleep(500);

}