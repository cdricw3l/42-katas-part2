/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_run_philosophes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 00:23:43 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/23 22:06:24 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thrd_manager.h"

void *ft_thread(void *p)
{
    int	start;
    t_philosophe *philo;
    struct timeval	s;
    struct timeval	end;

    gettimeofday(&s, NULL);
    
    philo = (t_philosophe *)(p);
    philo->state = ALIVE;
    //pthread_t tid = pthread_self();
    start = get_current_time();

    while (1 && philo->state != DEAD)
    {
        ft_active_transition(philo->network,philo->transitions_set[0], philo->id);
        while (!ft_is_activable_transition(philo->network,philo->transitions_set[1],philo->id) && philo->state != DEAD)
        {
            if(get_current_time() - start > philo->tempo.ttd)
            {
                philo->state = DEAD;
                ft_temporisation(1000,1,1);
                gettimeofday(&end, NULL);
                printf("\x1b[31m" "Le philosophe est Mort au bout de %f \n" "\x1b[0m",time_diff(&s, &end) );
                return(NULL);
            }
            //ft_print_petri_arr(philo->network->M0, philo->network->p, 0);
        }
        
        printf("Philosophe %d eating\n", philo->id);
        ft_active_transition(philo->network,philo->transitions_set[1], philo->id);      
        ft_temporisation(1000, philo->id,1);
        
        printf("Philosophe %d sleeping\n", philo->id);
        ft_active_transition(philo->network,philo->transitions_set[2], philo->id);
        ft_temporisation(1000, philo->id,0);
    }
    
    return(p);
}

int run_simulation(t_philosophe **philosophes, int n)
{
    pthread_t threads[n];

    pthread_create(&threads[0],NULL,ft_thread, philosophes[0]);
    pthread_join(threads[0], NULL);
    
    return(1);
}







