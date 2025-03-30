/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_thread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:44:36 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/25 07:55:59 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tst_unit.h"
#include <sys/types.h>

void *ft_thread_tst(void *p)
{
    int i;
    int is;
    t_philosophe *philo;
    philo = (t_philosophe *)(p);
    i = 0;
    while (i < 10)
    {
        
        if(pthread_mutex_lock(philo->fork[philo->network->n]))
            printf("Err mutex lock %d\n", philo->network->n);
        
        ft_active_transition(philo->network,philo->transitions_set[0], philo->id);
        
        if(pthread_mutex_unlock(philo->fork[philo->network->n]))
            printf("Error mutext unlok\n");
        
        if(pthread_mutex_lock(philo->fork[philo->network->n]))
            printf("Err mutex lock %d\n", philo->network->n);

        is =  ft_active_transition(philo->network,philo->transitions_set[1], philo->id);

        if(pthread_mutex_unlock(philo->fork[philo->network->n]))
            printf("Error mutext unlok\n");

        while (!is)
        {
            if(pthread_mutex_lock(philo->fork[philo->network->n]))
                printf("Error mutext lok %d\n", philo->network->n);
            
            is =  ft_active_transition(philo->network,philo->transitions_set[1], philo->id);

            if(pthread_mutex_unlock(philo->fork[philo->network->n]))
                printf("Error mutext lok\n");

            sleep(1);
        }

        if(!pthread_mutex_lock(philo->fork[get_fork_number(philo,1)]))
            printf("philosopher %d prend la fouchette %d\n", philo->id, get_fork_number(philo,1));
        
        if(!pthread_mutex_lock(philo->fork[get_fork_number(philo,2)]))
            printf("philosopher %d prend la fouchette %d\n",philo->id, get_fork_number(philo,2) );

        if(pthread_mutex_lock(philo->fork[philo->network->n]))
            printf("Error mutext lock %d\n", philo->network->n);
                
        ft_active_transition(philo->network,philo->transitions_set[1], philo->id);   

        if(pthread_mutex_unlock(philo->fork[philo->network->n]))
            printf("Error mutext unlock\n");

        printf("Philosophe %d eating\n", philo->id);

        sleep(1);        

        if(pthread_mutex_unlock(philo->fork[get_fork_number(philo,1)]) == 0)
            printf("philosopher %d rend la fouchette %d\n", philo->id, get_fork_number(philo,1));

        if(!pthread_mutex_unlock(philo->fork[get_fork_number(philo,2)]))
            printf("philosopher %d rend la fouchette %d\n",philo->id, get_fork_number(philo,2) );

        if(pthread_mutex_lock(philo->fork[philo->network->n]))
            printf("Error mutext lock %d\n", philo->network->n);

        ft_active_transition(philo->network,philo->transitions_set[2], philo->id);

        if(pthread_mutex_unlock(philo->fork[philo->network->n]))
            printf("Error mutext unlok %d\n", philo->network->n);
        
        printf("philosopher sleep %d\n",philo->id );
        sleep(1);      
        
        if(pthread_mutex_lock(philo->fork[philo->network->n]))
            printf("Error mutext lock %d\n", philo->network->n);
        i++;
     
    }
    

    return(p);
}



t_petri_network *init_network(void)
{
    t_petri_network *network;
    int	pt[3];
	char	*m0 = strdup("1 0 0 1");
	char	*m_out = strdup("1 0 0 0 3 0 0 0 3 1 0 0");
	char	*m_int = strdup("0 0 1 3 0 0 0 3 0 0 0 1");
	
	pt[0] = P;
	pt[1] = T;
	pt[1] = N;

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
	
	pt[0] = P;
	pt[1] = T;
	pt[2] = N;

    i = 0;
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
    (void)i;
    
    fork = ft_create_arr_mutext(pt[2] + 1);
    // while (i < pt[2])
    // {
    //     //printf(" voici i :%d\n", i);
    //     assert(fork);
    //     int m = pthread_mutex_lock(fork[i]);
    //     //printf("return lock %d\n" , m);
    //     assert(m == 0);
    //     usleep(100000);
    //     assert(pthread_mutex_unlock(fork[i]) == 0);
    //     i++;
    // }
    printf("\n");

    t_tempo_data tempo;

    tempo.ttd = 800;
    tempo.tte = 200;
    tempo.tts = 200;

    assert(pt[2] == N);
    philosophes = ft_create_philosophe(pt[2],fork,network, tempo);
    assert(philosophes && (*philosophes)->fork && (*philosophes)->network);

    printf("voici network %d\n", network->n);
    assert(philosophes[0]->network->n == N);
    /* display philosophe data: M0 state , transition set, id */
    ft_display_philophes(philosophes);
    
    // //philospher 0 activation transition 1
    // ft_active_transition(philosophes[0]->network, philosophes[0]->transitions_set[0], philosophes[0]->id);
    // ft_display_philophes(philosophes);
    
    // //philospher 0 activation transition 2, recuperation des fouchettes.
    // ft_active_transition(philosophes[0]->network, philosophes[0]->transitions_set[1], philosophes[0]->id);
    // ft_display_philophes(philosophes);
    
    // //philospher 4 activation SA transition 1: Fonctionne. il sort de sont sommeil.
    // ft_active_transition(philosophes[4]->network, philosophes[4]->transitions_set[0], philosophes[4]->id);
    // ft_display_philophes(philosophes);
    
    // //philospher 4 tente d'aceder a la fouchette : Ne Fonctionne pas tans que philosopher 1 ne rend pas les fouchette.
    // ft_active_transition(philosophes[4]->network, philosophes[4]->transitions_set[1], philosophes[4]->id);
    // ft_display_philophes(philosophes);
    
    // //philospher 1 activation transition 3, rend les  fouchettes.
    // ft_active_transition(philosophes[0]->network, philosophes[0]->transitions_set[2], philosophes[0]->id);
    // ft_display_philophes(philosophes);
    
    // //philospher 4 tente d'aceder a la fouchette : Fonctionne car philosopher 2 a rendu les fouchettes.
    // ft_active_transition(philosophes[4]->network, philosophes[4]->transitions_set[1], philosophes[4]->id);
    // //philospher 4 active Sa troisieme transition et l'etat de M0 revient a l'etat initial.
    // ft_display_philophes(philosophes);
    // ft_active_transition(philosophes[4]->network, philosophes[4]->transitions_set[2], philosophes[4]->id);
    // ft_display_philophes(philosophes);
    

    run_simulation(philosophes, N);
    
    
    ft_kill_philosophes_and_network(&philosophes, &network,&fork, network->n);
    TEST_SUCCES;
    return(1);
}