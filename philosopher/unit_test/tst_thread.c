/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_thread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:44:36 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/20 18:02:24 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tst_unit.h"

void *ft_thread(void *p)
{
    t_petri_network *id;
    int j;

    j = 0;
    id = (t_petri_network *)(p);
    printf("je suis le thread. Resception des data %d\n",id->p);
    ft_active_transition(id, 0);
    ft_active_transition(id, 1);
    ft_active_transition(id, 2);
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

int tst_thread_managment(void)
{

    TEST_START;
    pthread_t thread_1;
    //pthread_t thread_2;
    
    t_petri_network *network;
    int	pt[2];
	char	*m0 = strdup("1 0 0 1");

	char	*m_out = strdup("1 0 0 0 3 0 0 0 3 1 0 0");
	char	*m_int = strdup("0 0 1 3 0 0 0 3 0 0 0 1");
	
	pt[0] = P;
	pt[1] = T;

	network = ft_create_petri_net(pt,m0,m_int,m_out);
	if(!network)
		return(0);
	assert(network->M0 && network->M_in && network->M_out && network->Mp && network->Mt && network->p && network->t);
	assert(ft_network_check(network,pt[0]));
    TEST_SUCCES;
    printf("voici le nombre de place: %d\n", network->p);
    
    pthread_create(&thread_1, NULL, ft_thread, network);
    //pthread_create(&thread_2, NULL,ft_thread, &j);

    pthread_join(thread_1,NULL);
    //pthread_join(thread_2,NULL);
    //pthread_create(&thread_1, NULL,ft_thread, &j);
    TEST_SUCCES;
    return(1);
}