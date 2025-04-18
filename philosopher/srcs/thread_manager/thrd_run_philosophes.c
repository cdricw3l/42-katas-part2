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

/* 
    // if(pthread_mutex_lock(philo->fork[philo->network->n]))
        //     printf("Err mutex lock %d\n", philo->network->n);
        
        // ft_active_transition(philo->network,philo->transitions_set[0], philo->id);
        
        // if(pthread_mutex_unlock(philo->fork[philo->network->n]))
        //     printf("Error mutext unlok\n");
        
        // if(pthread_mutex_lock(philo->fork[philo->network->n]))
        //     printf("Err mutex lock %d\n", philo->network->n);

        // is =  ft_active_transition(philo->network,philo->transitions_set[1], philo->id);

        // if(pthread_mutex_unlock(philo->fork[philo->network->n]))
        //     printf("Error mutext unlok\n");

        // while (!is)
        // {
        //     if(pthread_mutex_lock(philo->fork[philo->network->n]))
        //         printf("Error mutext lok %d\n", philo->network->n);
            
        //     is =  ft_active_transition(philo->network,philo->transitions_set[1], philo->id);

        //     if(pthread_mutex_unlock(philo->fork[philo->network->n]))
        //         printf("Error mutext lok\n");

        //     sleep(1);
        // }

        // if(!pthread_mutex_lock(philo->fork[get_fork_number(philo,1)]))
        //     printf("philosopher %d prend la fouchette %d\n", philo->id, get_fork_number(philo,1));
        
        // if(!pthread_mutex_lock(philo->fork[get_fork_number(philo,2)]))
        //     printf("philosopher %d prend la fouchette %d\n",philo->id, get_fork_number(philo,2) );

        // if(pthread_mutex_lock(philo->fork[philo->network->n]))
        //     printf("Error mutext lock %d\n", philo->network->n);
                
        // ft_active_transition(philo->network,philo->transitions_set[1], philo->id);   

        // if(pthread_mutex_unlock(philo->fork[philo->network->n]))
        //     printf("Error mutext unlock\n");

        // printf("Philosophe %d eating\n", philo->id);

        // sleep(1);        

        // if(pthread_mutex_unlock(philo->fork[get_fork_number(philo,1)]) == 0)
        //     printf("philosopher %d rend la fouchette %d\n", philo->id, get_fork_number(philo,1));

        // if(!pthread_mutex_unlock(philo->fork[get_fork_number(philo,2)]))
        //     printf("philosopher %d rend la fouchette %d\n",philo->id, get_fork_number(philo,2) );

        // if(pthread_mutex_lock(philo->fork[philo->network->n]))
        //     printf("Error mutext lock %d\n", philo->network->n);

        // ft_active_transition(philo->network,philo->transitions_set[2], philo->id);

        // if(pthread_mutex_unlock(philo->fork[philo->network->n]))
        //     printf("Error mutext unlok %d\n", philo->network->n);
        
        // printf("philosopher sleep %d\n",philo->id );
        // sleep(1);      
        
        // if(pthread_mutex_lock(philo->fork[philo->network->n]))
        //     printf("Error mutext lock %d\n", philo->network->n);

*/



long long get_elapsed_time(long long start_time)
{
    return (get_current_time() - start_time);
}

void *ft_thread_tst(void *p)
{
    int i;
    t_philosophe *philo;

    philo = (t_philosophe *)(p);
    i = 0;
    int alive = ft_check_state_philosophes(philo);
    long long start= get_current_time();
    while (alive != 0)
    {
        
        long long start2= get_current_time();
        alive = ft_check_state_philosophes(philo);

        
        ft_philo_take_fork_1(philo);
        ft_philo_take_fork_2(philo);
        
        if(get_elapsed_time(start2) > philo->tempo.ttd)
        {
            printf("Le temps ecoule est trop long\n");
            ft_change_state_philosophes(philo);
        }    
        printf("%lld ms ecoule pour le philo %d avant de manger\n", get_elapsed_time(start), philo->id);
        
        ft_philo_eat(philo);
        
        ft_philo_release_fork_1(philo);
        ft_philo_release_fork_2(philo);
        
        printf("Philosopher %d sleep for %d\n",philo->id ,philo->tempo.tts);
        ft_temporisation(philo->tempo.tts, get_current_time());
        printf("Philosopher %d thinking\n",philo->id);
        i++;
    }
    
    printf("un philo est mort\n");
    return(p);
}

int ft_thread_laucher(t_philosophe **philosophes, int n, pthread_t threads[200])
{
    int i;

    i = 0;
    while (i < n)
    {
        if(i % 2 == 0 && i != 1)
        {
            if(pthread_create(&threads[i],NULL, ft_thread_tst, philosophes[i]))
                return(0);
            else 
                printf("lauch %d\n", philosophes[i]->id);
        }
        i++;
    }
    i = 0;
    while (i < n)
    {
        if((i % 3 == 0 && i != 0) || i == 1)
        {
            if(pthread_create(&threads[i],NULL,ft_thread_tst, philosophes[i]))
                return(0);
            else 
                printf("lauch %d\n", philosophes[i]->id);
        }
        i++;
    }
    return(1);
}

int ft_thread_joiner(pthread_t *threads, int n)
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

    
    
    if(!ft_thread_laucher(philosophes, n, threads))
    {
        printf("Error thread launcher\n");
        return(0);
    }
    if(!ft_thread_joiner(threads, n))
    {
        printf("Erreur thread joiner\n");
        return(0);
    }
    return(1);
}







