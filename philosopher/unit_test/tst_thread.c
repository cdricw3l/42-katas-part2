/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_thread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:44:36 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/22 12:09:58 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tst_unit.h"
#include <sys/types.h>

void *ft_thread(void *p)
{
    t_philosophe *id;
    int j;

    j = 0;
    id = (t_philosophe *)(p);
    pthread_t tid = pthread_self();
    printf("Thread id %p\n", tid);
   
   // ft_print_petri_arr(id->network->M0, id->network->p, 0);
    // if(id->id == 1)
    // {
        //     sleep(10);
        //     ft_active_transition(id->network,0);
        // }
        // printf("philosophe dors ZzZZzZzZz\n");
        // while (!ft_is_activable_transition(id->network, 1))
        // {
            // }
            // if(id->id == 0)
            // {
    //     ft_active_transition(id->network,1);
    //     printf("Philosophe %d Mange\n", id->id);
    //     sleep(10);
    // }
    if(ft_active_transition(id->network,0, id->id) == 1)
        printf("Philosophe %d Mange\n", id->id);
    //ft_print_petri_arr(id->network->M0, id->network->p, 0);
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
	char	*m_out = strdup("1 0 0 0 1 0 0 0 3 0 1 0");
	char	*m_in = strdup("0 0 1 1 0 0 0 3 0 0 0 1");
	
	pt[0] = P;
	pt[1] = T;
	pt[2] = N;
    i = 0;
	network = ft_create_petri_net(pt,m0,m_in,m_out);
	if(!network)
		return(0);
    
    
	assert(network->M0 && network->M_in && network->M_out && network->Mp && network->Mt && network->p && network->t);
	assert(ft_network_check(network,pt[0]));
    
    ft_extend_network(network, N);              // verifier l'extension pour 1.
    
    assert(ft_plug_philosophe_together(network)== 1);
    /* create a mutex arr and assert that the lock and unlock fonctionnality works */
    ft_print_network(network);
    fork = ft_create_arr_mutext(N);
    while (i < N)
    {
        //printf(" voici i :%d\n", i);
        assert(fork);
        int m = pthread_mutex_lock(&fork[i]);
        //printf("return lock %d\n" , m);
        assert(m == 0);
        usleep(100000);
        assert(pthread_mutex_unlock(&fork[i]) == 0);
        i++;
    }
    printf("\n");

    t_philosophe **philosophes;


    // create my first philosophe second philosophe
    
    

    philosophes = ft_create_philosophe(N,fork,network);
    assert(philosophes);
    assert(philosophes[1]->transitions_set[0] == 3 && philosophes[1]->transitions_set[1] == 4 && philosophes[1]->transitions_set[2] == 5);
    printf("voici set %d and %d and %d\n", philosophes[1]->transitions_set[0], philosophes[1]->transitions_set[1], philosophes[1]->transitions_set[2]);

    // ft_print_petri_arr(network->M0,network->p,0);
    // ft_active_transition(network,5);
    // ft_print_petri_arr(network->M0,network->p,0);
    // ft_active_transition(network,1);
    // ft_print_petri_arr(network->M0,network->p,0);
    // ft_active_transition(network,2);
    // ft_print_petri_arr(network->M0,network->p,0);

    //create thread

    pthread_create(&thread_1, NULL, ft_thread, &philosophes[0]);
    pthread_create(&thread_2, NULL,ft_thread, &philosophes[1]);
    
    
    
    pthread_join(thread_1,NULL);
    pthread_join(thread_2,NULL);
    
    
    TEST_SUCCES;
    return(1);
}