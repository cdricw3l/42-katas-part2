/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_kill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:19:43 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/05/18 21:33:43 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tst_unit.h"

int tst_kill(void)
{
    t_network *network;
    int *params;
    int n = 5;
    
    params = malloc(sizeof(int) * n);
    if(!params)
        return(0);
        
    params[P] = n;
    params[TTD] = 710;
    params[TTE] = 200;
    params[TTS] = 200;
    params[CYCLE] = 10;
    network = create_network(params);
    
    int i = 0;
    while (i < n)
    {
        change_state(network->philos[i], 0 ,ON);
        assert(network->philos[i]->pametres[STATE_1] == 1);
        i++;
    }
    printf("voici cycle philo %d et cycle network %d\n", network->philos[3]->pametres[CYCLE], network->pametres[CYCLE] - 1);
    assert(network->philos[3]->pametres[CYCLE] < network->pametres[CYCLE] - 1);
    change_state(network->philos[3], 0, OFF);
    assert(network->philos[3]->pametres[STATE_1] == 0);
    assert(!are_alive(network));
    return(1);
}