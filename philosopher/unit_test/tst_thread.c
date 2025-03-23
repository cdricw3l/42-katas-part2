/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_thread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:44:36 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/23 03:33:29 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tst_unit.h"
#include <sys/types.h>

void *ft_thread(void *p)
{
    t_philosophe *philo;
    philo = (t_philosophe *)(p);
    //pthread_t tid = pthread_self();
    while (1)
    {
        ft_active_transition(philo->network,philo->transitions_set[0], philo->id);
        usleep(10000);
        while (!ft_is_activable_transition(philo->network,philo->transitions_set[1],philo->id))
        {
            printf("En attente de fork pour le philosophe %d\n", philo->id);
            //ft_print_petri_arr(philo->network->M0, philo->network->p, 0);
        }
        ft_active_transition(philo->network,philo->transitions_set[1], philo->id);      
        usleep(10000);
        ft_active_transition(philo->network,philo->transitions_set[2], philo->id);
        usleep(10000);
    }
    

    return(p);
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
    t_philosophe **philosophes;
   
    t_petri_network *network;
    pthread_mutex_t **fork;
    
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
    network =  ft_extend_network(network, N);              // verifier l'extension pour 1.
    assert(ft_plug_philosophe_together(network)== 1);
    /* create a mutex arr and assert that the lock and unlock fonctionnality works */
    ft_print_network(network);
    fork = ft_create_arr_mutext(N);
    while (i < N)
    {
        //printf(" voici i :%d\n", i);
        assert(fork);
        int m = pthread_mutex_lock(fork[i]);
        //printf("return lock %d\n" , m);
        assert(m == 0);
        usleep(100000);
        assert(pthread_mutex_unlock(fork[i]) == 0);
        i++;
    }
    printf("\n");

    philosophes = ft_create_philosophe(N,fork,network);
    assert(philosophes && (*philosophes)->fork && (*philosophes)->network);


    /* display philosophe data: M0 state , transition set, id */
    ft_display_philophes(philosophes);
    
    //philospher 0 activation transition 1
    ft_active_transition(philosophes[0]->network, philosophes[0]->transitions_set[0], philosophes[0]->id);
    ft_display_philophes(philosophes);
    
    //philospher 0 activation transition 2, recuperation des fouchettes.
    ft_active_transition(philosophes[0]->network, philosophes[0]->transitions_set[1], philosophes[0]->id);
    ft_display_philophes(philosophes);
    
    //philospher 4 activation SA transition 1: Fonctionne. il sort de sont sommeil.
    ft_active_transition(philosophes[4]->network, philosophes[4]->transitions_set[0], philosophes[4]->id);
    ft_display_philophes(philosophes);
    
    //philospher 4 tente d'aceder a la fouchette : Ne Fonctionne pas tans que philosopher 1 ne rend pas les fouchette.
    ft_active_transition(philosophes[4]->network, philosophes[4]->transitions_set[1], philosophes[4]->id);
    ft_display_philophes(philosophes);
    
    //philospher 1 activation transition 3, rend les  fouchettes.
    ft_active_transition(philosophes[0]->network, philosophes[0]->transitions_set[2], philosophes[0]->id);
    ft_display_philophes(philosophes);
    
    //philospher 4 tente d'aceder a la fouchette : Fonctionne car philosopher 2 a rendu les fouchettes.
    ft_active_transition(philosophes[4]->network, philosophes[4]->transitions_set[1], philosophes[4]->id);
    //philospher 4 active Sa troisieme transition et l'etat de M0 revient a l'etat initial.
    ft_display_philophes(philosophes);
    ft_active_transition(philosophes[4]->network, philosophes[4]->transitions_set[2], philosophes[4]->id);
    ft_display_philophes(philosophes);
    

    
    pthread_t thread;
    pthread_t thread2;
    pthread_t thread3;
    pthread_t thread4;
    pthread_t thread5;
  
    
    pthread_create(&thread, NULL, ft_thread, philosophes[5]);
    sleep(1);
    pthread_create(&thread2, NULL, ft_thread, philosophes[1]);
    sleep(1);
    pthread_create(&thread3, NULL, ft_thread, philosophes[0]);
    sleep(1);
    pthread_create(&thread4, NULL, ft_thread, philosophes[4]);
    sleep(1);
    pthread_create(&thread5, NULL, ft_thread, philosophes[3]);
    
    
    ft_kill_philosophes_and_network(&philosophes, &network,fork, network->n);
    TEST_SUCCES;
    return(1);
}