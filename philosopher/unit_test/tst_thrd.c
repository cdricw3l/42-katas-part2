/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_thrd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:49:07 by ast               #+#    #+#             */
/*   Updated: 2025/04/27 18:56:44 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "tst_unit.h"

int tst_run_thread_simulation(void)
{
    TEST_START;

    t_network *network;
    pthread_t monitiror;
    pthread_t threads[200];
    int *params;
    int n = 5;
    
    params = malloc(sizeof(int) * n);
    if(!params)
        return(0);
        
    params[P] = n;
    params[TTD] = 510;
    params[TTE] = 200;
    params[TTS] = 200;
    params[CYCLE] = 10;
    network = create_network(params);
    if(!network)
    {
        free(params);
        return(0);
    }
    if(!philos_laucher(&network, threads))
    {
        printf("Error thread philo launcher\n");
        return(0);
    }
    if(!monitor_launcher(&network, &monitiror))
    {
        printf("Error thread monitor launcher\n");
        return(0);
    }
    if(!monitor_joiner(&monitiror))
    {
        printf("Error thread monitor joiner\n");
        return(0);
    }
    if(!philos_joiner(&network, threads))
    {
        printf("Error thread philo joiner\n");
        return(0);
    }
    destroy_network(&network);
    free(params);
    return(1);
}

int tst_run_thread_philo(void)
{
    TEST_START;

    t_network *network;
    pthread_t threads[200];
  
    int *params;
    int n = 5;
    
    params = malloc(sizeof(int) * n);
    if(!params)
        return(0);
        
    params[P] = n;
    params[TTD] = 500;
    params[TTE] = 200;
    params[TTS] = 200;
    params[CYCLE] = 3;
    network = create_network(params);
    if(!network)
    {
        free(params);
        return(0);
    }

    int i;

    i = 0;
    while (i < params[P])
    {
        change_state(network->philos[i], 0, 1);
        i++;
    }
    
    if(!philos_laucher(&network,threads))
    {
        destroy_network(&network);
        free(params);
        return(0);
    }
    
    if(!philos_joiner(&network, threads))
    {
        printf("Error thread philo joiner\n");
        return(0);
    }
    destroy_network(&network);
    free(params);
    return(1);
}

int tst_run_thread_monitor(void)
{
    TEST_START;


    t_network *network;
    pthread_t monitor;
    int *params;
    int n = 5;
    
    params = malloc(sizeof(int) * n);
    if(!params)
        return(0);
        
    params[P] = n;
    params[TTD] = 500;
    params[TTE] = 200;
    params[TTS] = 200;
    params[CYCLE] = 10;
    network = create_network(params);
    if(!network)
    {
        free(params);
        return(0);
    }
    if(monitor_launcher(&network, &monitor))
    {
        destroy_network(&network);
        free(params);
        return(0);
    }
    destroy_network(&network);
    free(params);
    return(1);
}