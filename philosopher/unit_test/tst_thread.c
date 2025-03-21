/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_thread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:44:36 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/21 13:25:03 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tst_unit.h"

void *ft_thread(void *p)
{
    t_philosophe *id;
    int j;

    j = 0;
    id = (t_philosophe *)(p);
    while(j < 10)
    {
        
        assert(pthread_mutex_lock(&id->fork[id->id]) == 0);
        id->network->M0[id->id]++;
        printf("Ecriture dans l'etat par le thead id %d value: %d \n", id->id, id->network->M0[id->id]);
        assert(pthread_mutex_unlock(&id->fork[id->id]) == 0);
        // usleep(100000);
        // usleep(100000);
        j++;
    }
    
    pthread_exit(&j);
}



t_petri_network *init_network(void)
{
    t_petri_network *network;
    int	pt[2];
	char	*m0 = strdup("1 0 0 1");

	char	*m_out = strdup("1 0 0 0 3 0 0 0 3 1 0 0");
	char	*m_int = strdup("0 0 1 3 0 0 0 3 0 0 0 1");
	
	pt[0] = P;
	pt[1] = T;

	network = ft_create_petri_net(pt,m0,m_int,m_out);
	if(!network)
		return(NULL);
	assert(network->M0 && network->M_in && network->M_out && network->Mp && network->Mt && network->p && network->t);
	assert(ft_network_check(network,pt[0]));
    return(network);
    
}

void ft_plug_fork(t_petri_network *network)
{
    // int i;
    (void)network;
    // i = 0;
    
}

int tst_thread_managment(void)
{
    int	pt[3];
    int i;
    pthread_t thread_1;
    pthread_t thread_2;
    t_petri_network *network;
    pthread_mutex_t *fork;
    
	char	*m0 = strdup("1 0 0 1");
	char	*m_out = strdup("1 0 0 0 3 0 0 0 3 1 0 0");
	char	*m_int = strdup("0 0 1 3 0 0 0 3 0 0 0 1");
	
	pt[0] = P;
	pt[1] = T;
	pt[2] = N;
    i = 0;
	network = ft_create_petri_net(pt,m0,m_int,m_out);
	if(!network)
		return(0);
    
    
	assert(network->M0 && network->M_in && network->M_out && network->Mp && network->Mt && network->p && network->t);
	assert(ft_network_check(network,pt[0]));
    
    // ft_extend_network(network,3);              // verifier l'extension pour 1.
    // ft_print_network(network);
    

    /* create a mutex arr and assert that the lock and unlock fonctionnality works */
    fork = ft_create_arr_mutext(P);
    while (i < P)
    {
        printf(" voici i :%d\n", i);
        assert(fork);
        int m = pthread_mutex_lock(&fork[i]);
        printf("return lock %d\n" , m);
        assert(m == 0);
        usleep(100000);
        assert(pthread_mutex_unlock(&fork[i]) == 0);
        i++;
    }
    printf("\n");
    
    // create my first philosophe second philosophe
    t_philosophe philophe_1 = {0, fork, network};
    t_philosophe philophe_2 = {1, fork, network};

    assert(philophe_1.id == 0 && philophe_1.network->p == P);
    assert(philophe_2.id == 1 && philophe_2.network->p == P);
    

    //create thread
    pthread_create(&thread_1, NULL, ft_thread, &philophe_1);
    pthread_create(&thread_2, NULL,ft_thread, &philophe_2);
    
    
    
    pthread_join(thread_1,NULL);
    pthread_join(thread_2,NULL);
    
    ft_print_petri_arr(network->M0,P,0);
    
    TEST_SUCCES;
    return(1);
}