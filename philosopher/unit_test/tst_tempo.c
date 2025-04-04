/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_tempo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 07:55:14 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/25 22:06:15 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tst_unit.h"


void *ft_thread_tst_2(void *p)
{
    t_philosophe *philo;
    philo = (t_philosophe *)(p);
    //pthread_t tid = pthread_self();
    while (1 && ft_are_all_alive(philo))
    {
        printf("philo %d thinking\n", philo->id);
        ft_active_transition(philo->network, philo->transitions_set[0], philo->id);
        while (ft_active_transition(philo
        ->network, philo->transitions_set[1], philo->id) == -1 && ft_are_all_alive(philo))
        {
            usleep(50);
        }
        if(ft_are_all_alive(philo))
        {
            pthread_mutex_lock(philo->fork[3]);
            printf("philo take the fork 1\n");
            printf("philo %d eatting\n", philo->id);
            ft_temporisation(500,0,1);
            pthread_mutex_unlock(philo->fork[3]);
        }
        if(ft_are_all_alive(philo))
        {
            printf("philo %d splipping\n", philo->id);
            ft_active_transition(philo->network, philo->transitions_set[2], philo->id);
            ft_temporisation(500,0,1);
        }
        
    }
    return(p);
}

int tst_tempo(void)
{
    int	pt[3];
    t_philosophe **philosophes;
    t_petri_network *network;
    pthread_mutex_t **fork;
    t_tempo_data tempo;
    
	pt[0] = P;
	pt[1] = T;
	pt[2] = 5;

	network = ft_extend_network(ft_create_petri_net(pt,
		"1 0 0 1", "0 0 1 1 0 0 0 3 0 0 0 1",
		"1 0 0 0 1 0 0 0 3 0 1 0"), pt[2]);
	if(!network)
		return(0);
    assert(network->M0 && network->M_in && network->M_out && network->Mp && network->Mt && network->p && network->t);
    assert(ft_network_check(network,pt[0] * pt[2]));
    
    ft_plug_philosophe_together(network);

    /* create a mutex arr and assert that the lock and unlock fonctionnality works */
    ft_print_network(network);
    
    
    fork = ft_create_arr_mutext(pt[2]);

    tempo.ttd = 800;
    tempo.tte = 200;
    tempo.tts = 200;

    assert(pt[2] == 5);
    philosophes = ft_create_philosophe(pt[2],fork,network, tempo);
    
    ft_print_petri_arr(philosophes[0]->state,philosophes[0]->network->n, 0);
    

    // change the state of the philosopher 0 from alive to death.
    // philosophes[0]->state[philosophes[0]->id] = 1;
    // ft_print_petri_arr(philosophes[1]->state,philosophes[1]->network->n, 0);
    
    // //check the state array in philosopher 1. Philosopher 0 is death. The state is shared.
    // philosophes[1]->state[philosophes[1]->id] = 0;
    // ft_print_petri_arr(philosophes[1]->state,philosophes[1]->network->n, 0);
    // philosophes[0]->state[philosophes[0]->id] = 0;


    /* 
        Check the mutex lock. Any philosopher lock his fork and the fork of the philosopher p - 1, 
        except for the philophe 0 who take as second fork, the fork of the last philo.

        Google sheet or excel are very usefull for build formula.
    */
    
    assert(get_fork_number(philosophes[0], 1) == 0);
    assert(get_fork_number(philosophes[1], 1) == 1);
    assert(get_fork_number(philosophes[2], 1) == 2);
    assert(get_fork_number(philosophes[3], 1) == 3);
    assert(get_fork_number(philosophes[4], 1) == 4);
    
    assert(get_fork_number(philosophes[0], 2) == get_fork_number(philosophes[4], 1));
    assert(get_fork_number(philosophes[1], 2) == get_fork_number(philosophes[0], 1));
    assert(get_fork_number(philosophes[2], 2) == get_fork_number(philosophes[1], 1));
    assert(get_fork_number(philosophes[3], 2) == get_fork_number(philosophes[2], 1));
    assert(get_fork_number(philosophes[4], 2) == get_fork_number(philosophes[3], 1));

    int time;

    assert(ft_are_all_alive(philosophes[1]));

    time = 0;

    while (1 && ft_are_all_alive(philosophes[0]))
    {
        if(time == 10)
        {
            philosophes[1]->state[1] = DEAD;
        }
        printf("nous somme tous vivant\n");
        time++;
        sleep(1);
    }
    printf("Un philosoque est mort RIP\n");
    
    ft_kill_philosophes_and_network(&philosophes, &network,&fork,network->n);
    return(1);
}