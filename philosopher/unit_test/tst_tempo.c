/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_tempo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:52:51 by ast               #+#    #+#             */
/*   Updated: 2025/04/20 09:28:34 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "tst_unit.h"

int tst_tempo(void)
{
    t_network *network;
  
    int *params;
    int n = 5;
    int i;
    
    params = malloc(sizeof(int) * n);
    if(!params)
        return(0);
        
    params[P] = n;
    params[TTD] = 500;
    params[TTE] = 200;
    params[TTS] = 200;
    params[CYCLE] = 10;
    
    network = create_network(params);
    assert(network->last_meals);
    assert(network->pametres[P] == 5);
    i = 0;
    while (i < network->pametres[P])
    {
        printf("voici l'adresse du meal board general %p\n", network->last_meals);
        //network->philos[i]->meal_time_data[i] = get_current_time();
        put_timestamp(network->philos[i]);
        i++;
    }

    ft_temporisation(800, get_current_time());
    long long curent = get_current_time();
    i = 0;
    while (i < network->pametres[P])
    {
        printf(" philo : %lld\n",  curent - network->philos[i]->meal_time_data[i]);
        i++;
    }
    if(check_timestamp(network->philos,network->pametres[P]))
        printf("Tout c'est derouler comme prevu\n");
    destroy_network(&network);
    free(params);
    return(1);
}