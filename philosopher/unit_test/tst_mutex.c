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

#include "tst_unit.h"

int tst_mutex(void)
{
    int	pt[3];
    t_philosophe **philosophes;
    t_petri_network *network;
    pthread_mutex_t **fork;
    t_tempo_data tempo;
    

	
	pt[0] = P;
	pt[1] = T;
	pt[2] = N;

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
    philosophes[0]->state[philosophes[0]->id] = 1;
    ft_print_petri_arr(philosophes[1]->state,philosophes[1]->network->n, 0);
    
    //check the state array in philosopher 1. Philosopher 0 is death. The state is shared.
    philosophes[1]->state[philosophes[1]->id] = 0;
    ft_print_petri_arr(philosophes[1]->state,philosophes[1]->network->n, 0);
    philosophes[0]->state[philosophes[0]->id] = 0;


    /* 
        Check the mutex lock. Any philosopher lock his fork and the fork of the philosopher p - 1, 
        except for the philophe 0 who take as second fork, the fork of the last philo.

        Google sheet or excel are very usefull for build formula.
    */
    
    assert(get_fork_number(philosophes[0], 2) == 4);
    assert(get_fork_number(philosophes[1], 2) == 1);
    assert(get_fork_number(philosophes[2], 2) == 2);
    assert(get_fork_number(philosophes[3], 2) == 3);
    assert(get_fork_number(philosophes[4], 2) == 4);
    
    assert(get_fork_number(philosophes[0], 1) == get_fork_number(philosophes[1], 1));
    assert(get_fork_number(philosophes[1], 1) == get_fork_number(philosophes[0], 1));
    assert(get_fork_number(philosophes[2], 1) == get_fork_number(philosophes[1], 2));
    assert(get_fork_number(philosophes[3], 1) == get_fork_number(philosophes[2], 2));
    assert(get_fork_number(philosophes[4], 1) == get_fork_number(philosophes[3], 2));

    // pthread_t thread1;
    // pthread_t thread2;

    // pthread_create(&thread1, NULL, ft_thread_tst_2, philosophes[0]);
    // pthread_create(&thread2, NULL, ft_thread_tst_2, philosophes[1]);
    


    // pthread_join(thread1, NULL);
    // pthread_join(thread2, NULL);
    assert(network->n == 5);
    ft_kill_philosophes_and_network(&philosophes, &network, &fork,network->n);
    return(1);
}