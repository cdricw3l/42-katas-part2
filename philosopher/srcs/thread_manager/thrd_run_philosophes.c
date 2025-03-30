/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_run_philosophes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 00:23:43 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/25 22:05:59 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thrd_manager.h"

int ft_are_all_alive(t_philosophe *philosophe)
{
    int i;

    i = 0;
    while (i < philosophe->network->n)
    {
        if(philosophe->state[i] == 1)
            return(0);
        i++;
    }
    return(i);
}



void *ft_thread(void *p)
{
    TEST_START;

    t_philosophe *philo;
    (void)philo;
    philo = (t_philosophe *)(p);
    
    //pthread_t tid = pthread_self();
    
    while (1)
    {
        printf("hello world from philo %d\n", philo->id);
        sleep(1);
    }
    TEST_SUCCES;
    return(p);
}

int ft_thread_laucher(t_philosophe **philosophes, int n, pthread_t threads[200])
{
    
    int i;

    i = 0;
    assert(n == 5);

    while (i < n)
    {
        if(i % 2 == 0 && i != 1)
        {
            philosophes[i]->state[i] = ALIVE;
            if(pthread_create(&threads[i],NULL,ft_thread, philosophes[i]))
            {
                printf("Erreur launch thread %d\n", i);
                return(0);
            }
        }
        printf("launch thread %d\n", i);
        i++;
    }
    i = 0;
    while (i < n)
    {
        if(i % 3 == 0 || i == 1)
        {
            philosophes[i]->state[i] = ALIVE;
            if(pthread_create(&threads[i],NULL,ft_thread, philosophes[i]))
                return(0);
        }
        i++;
    }
    return(1);
}

int ft_thread_joiner(pthread_t threads[200], int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        if(pthread_join(threads[i], NULL))
            return(0);
        i++;
    }
    return (1);
}

int run_simulation(t_philosophe **philosophes, int n)
{
    pthread_t threads[200];

    if(n > 200)
    {
        printf("To much philosophe. Max value: 200");
        return(0);
    }
    if(!ft_thread_laucher(philosophes, n, threads))
        return(0);
    if(!ft_thread_joiner(threads, n))
        return(0);
    return(1);
}







