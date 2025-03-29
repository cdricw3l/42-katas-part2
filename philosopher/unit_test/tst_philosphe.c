/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_philosphe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:35:34 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/25 07:41:27 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tst_unit.h"

int tst_philosophes(void)
{
    int	pt[3];
    int i;
    t_petri_network *network;
    pthread_mutex_t **fork;
    t_philosophe **philosophes;
    
	pt[0] = P;
	pt[1] = T;
	pt[2] = N;
    
    i = 0;
	network = ft_extend_network(ft_create_petri_net(pt,
		"1 0 0 1", "0 0 1 1 0 0 0 3 0 0 0 1",
		"1 0 0 0 1 0 0 0 3 0 1 0"), pt[2]);
	if(!network)
		return(0);             // verifier l'extension pour 1.
    ft_plug_philosophe_together(network);
    fork = ft_create_arr_mutext(N);
    while (i < N)
    {
        assert(fork);
        int m = pthread_mutex_lock(fork[i]);
        printf("Return lock %d\n" , m);
        assert(m == 0);
        //usleep(100000);
        assert(pthread_mutex_unlock(fork[i]) == 0);
        i++;
    }
    
    t_tempo_data tempo = {800,200,200,10};

    
    philosophes = ft_create_philosophe(network->n,fork,network,tempo);

    DEBUGG;
    assert(philosophes[0]->transitions_set[0] == 0 && philosophes[0]->transitions_set[1] == 1 && philosophes[0]->transitions_set[2] == 2);
    i = 0;
    while (i < N)
    {
        assert(philosophes[i]);
        printf("voici id philo :  %d\n", philosophes[i]->id);
        printf("voici set %d and %d and %d\n", philosophes[i]->transitions_set[0], philosophes[i]->transitions_set[1], philosophes[i]->transitions_set[2]);
        i++;
    }
    
    printf("voici l'adresse du reseau %p, %p\n", philosophes, network);

    /* I destroy part by part the network dans send the structure to the kill philosophe and destroy network fonction  
        If all is safe, resend NULL pointeur to Kill philosophe and destroy network shouldn't be a problem
    */
    
    // clean fork memory.
    //ft_destroy_mutext(&fork,network->p / 4);
    // destroy the petri network.
    ft_destroy_network(&network);
    
    // kill the philosophe and network. The network that is already cleaned.
    ft_kill_philosophes_and_network(&philosophes,&network,&fork,N);
    
    // try for test to redestroy petri net.
    ft_destroy_network(&network);
    printf("voici l'adresse du reseau %p, %p\n", philosophes, network);
    
    return(1);
}