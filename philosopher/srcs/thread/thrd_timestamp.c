/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_timestamp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:52:01 by ast               #+#    #+#             */
/*   Updated: 2025/04/25 23:34:48 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "thread.h"

int put_timestamp(t_philo *philo, int type, long long start)
{
    
    if(type < TS_CYCLE || type > TS_END_SPLEEP)
        return(-1);
    if(pthread_mutex_lock(philo->pen))
    {
        printf("Erreur mutex state lock\n");
        return(0);
    }
    if(type == TS_CYCLE)
        philo->time_data[TS_CYCLE]++;
    else
        philo->time_data[type] = get_current_time() - start;
    if(pthread_mutex_unlock(philo->pen))
    {
        printf("Erreur mutex state lock\n");
        return(0);
    }
    return(1);
}

int check_timestamp(t_philo **philo, int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        if(philo[i]->time_data[TS_END_THINK] - philo[i]->time_data[TS_LAST_EAT] > philo[i]->pametres[TTD] && i != 1)
        {
            printf("fonction will ending %lld and %d\n", philo[i]->time_data[TS_END_THINK] - philo[i]->time_data[TS_LAST_EAT], philo[i]->pametres[TTD]);
            philo[i]->pametres[STATE_1] = 0;
            display_philo_time_board(philo[i], 1);
            return(0);
        }
    }
    return(1);
}
// long long get_timestamp(t_philo *philo)
// {

//     long long timestamp;
//     int id;

//     id = philo->pametres[ID];
//     if(pthread_mutex_lock(philo->pen))
//     {
//         printf("Erreur mutex state lock\n");
//         return(0);
//     }
//     timestamp = philo->meal_time_data[id];
//     if(pthread_mutex_lock(philo->pen))
//     {
//         printf("Erreur mutex state lock\n");
//         return(0);
//     }
//     return(timestamp);
// }

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