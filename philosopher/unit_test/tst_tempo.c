/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_tempo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 07:55:14 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/25 21:47:31 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tst_unit.h"

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

int get_fork_number(t_philosophe *philosophe, int num_fork)
{
    int id;
    int fork;
    
    id = philosophe->id;
    fork = 0;
    if(num_fork == 1)
    {
        printf("voici %d\n", philosophe->id);
        //+ (philosophe->network->p - 1 / philosophe->network->n
        fork = id + (id  * ((philosophe->network->p  / philosophe->network->n) - 1)) + ((philosophe->network->p  / philosophe->network->n) - 1);
        //fork = id + (id *  (philosophe->network->p - 1 / philosophe->network->n));
    }
    (void)id;
    return(fork);
}

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
    
	char	*m0 = strdup("1 0 0 1"); 
	char	*m_out = strdup("1 0 0 0 1 0 0 0 3 0 1 0");
	char	*m_in = strdup("0 0 1 1 0 0 0 3 0 0 0 1");
	
	pt[0] = P;
	pt[1] = T;
	pt[2] = 5;
	network = ft_create_petri_net(pt,m0,m_in,m_out);
	if(!network)
		return(0);
    
	assert(network->M0 && network->M_in && network->M_out && network->Mp && network->Mt && network->p && network->t);
	assert(ft_network_check(network,pt[0]));
    
    network =  ft_extend_network(network, pt[2]);              // verifier l'extension pour 1.
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
    philosophes[0]->state[philosophes[0]->id] = 1;
    ft_print_petri_arr(philosophes[1]->state,philosophes[1]->network->n, 0);
    
    //check the state array in philosopher 1. Philosopher 0 is death. The state is shared.
    philosophes[1]->state[philosophes[1]->id] = 0;
    ft_print_petri_arr(philosophes[1]->state,philosophes[1]->network->n, 0);
    philosophes[0]->state[philosophes[0]->id] = 0;

    printf("%d\n", get_fork_number(philosophes[0], 1));
    printf("%d\n", get_fork_number(philosophes[1], 1));
    printf("%d\n", get_fork_number(philosophes[2], 1));
    printf("%d\n", get_fork_number(philosophes[3], 1));
    printf("%d\n", get_fork_number(philosophes[4], 1));

    // pthread_t thread1;
    // pthread_t thread2;

    // pthread_create(&thread1, NULL, ft_thread_tst_2, philosophes[0]);
    // pthread_create(&thread2, NULL, ft_thread_tst_2, philosophes[1]);
    


    // pthread_join(thread1, NULL);
    // pthread_join(thread2, NULL);
    return(1);
}