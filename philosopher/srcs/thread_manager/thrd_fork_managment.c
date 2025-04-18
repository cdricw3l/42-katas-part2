/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:14:22 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/25 22:06:02 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thrd_manager.h"

void ft_philo_eat(t_philosophe *philosophe)
{
    printf("Philosopher %d eat for %d ms\n",philosophe->id ,philosophe->tempo.tte);
        ft_temporisation(philosophe->tempo.tte,get_current_time());
}


void ft_philo_take_fork_1(t_philosophe *philosophe)
{
    int fork_id;

    fork_id = get_fork_number(philosophe, 1);
    if(pthread_mutex_lock(philosophe->fork[fork_id]))
            printf("lock error \n");
    printf("Philosopher %d take fork %d\n",philosophe->id ,fork_id);
}

void ft_philo_take_fork_2(t_philosophe *philosophe)
{
    int fork_id;

    fork_id = get_fork_number(philosophe, 2);
    if(pthread_mutex_lock(philosophe->fork[fork_id]))
            printf("lock error \n");
    printf("Philosopher %d take fork %d\n",philosophe->id ,fork_id);
}
void ft_philo_release_fork_1(t_philosophe *philosophe)
{
    int fork_id;

    fork_id = get_fork_number(philosophe, 1);
    if(pthread_mutex_unlock(philosophe->fork[fork_id]))
            printf("lock error \n");
    printf("Philosopher %d release fork %d\n",philosophe->id ,fork_id);
}

void ft_philo_release_fork_2(t_philosophe *philosophe)
{
    int fork_id;

    fork_id = get_fork_number(philosophe, 2);
    if(pthread_mutex_unlock(philosophe->fork[fork_id]))
            printf("lock error \n");
    printf("Philosopher %d release fork %d\n",philosophe->id ,fork_id);

}