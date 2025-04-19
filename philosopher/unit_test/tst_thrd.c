/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_thrd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:49:07 by ast               #+#    #+#             */
/*   Updated: 2025/04/19 09:38:42 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "tst_unit.h"

int tst_run_thread_philo(void)
{
    TEST_START;


    t_network *network;
  
    int *params;
    int n = 5;
    
    params = malloc(sizeof(int) * n);
    if(!params)
        return(0);
        
    params[P] = n;
    params[TTD] = 500;
    params[TTE] = 200;
    params[TTS] = 200;
    params[CYCLE] = -1;
    network = create_network(params);
    if(!network)
    {
        free(params);
        return(0);
    }
    if(!philos_laucher(&network))
    {
        destroy_network(&network);
        free(params);
        return(0);
    }
    return(1);
}

int tst_run_thread_monitor(void)
{
    TEST_START;


    t_network *network;
  
    int *params;
    int n = 5;
    
    params = malloc(sizeof(int) * n);
    if(!params)
        return(0);
        
    params[P] = n;
    params[TTD] = 500;
    params[TTE] = 200;
    params[TTS] = 200;
    params[CYCLE] = -1;
    network = create_network(params);
    if(!network)
    {
        free(params);
        return(0);
    }
    if(monitor_launcher(&network))
    {
        destroy_network(&network);
        free(params);
        return(0);
    }
    return(1);
}