/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_network.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 06:06:02 by ast               #+#    #+#             */
/*   Updated: 2025/04/20 09:16:05 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "init_network.h"

void init_params_monitor(int *monitor_param, int *params)
{
    monitor_param[P] = params[P];
    monitor_param[TTD] = params[TTD];
    monitor_param[TTE] = params[TTE];
    monitor_param[TTS] = params[TTS];
    monitor_param[CYCLE] = params[CYCLE];
}

static t_network   *build_network(t_mutex_data *mutex_data, t_philo **philos, int *params, long long **meal_board)
{
    t_network *network;

    network = malloc(sizeof(t_network) * 1);
    if(!network)
        return(NULL);
    network->last_meals = *meal_board;
    if(!network->last_meals)
    {
        free(network);
        return(NULL);
    }
    init_params_monitor(network->pametres,params);
    network->mutex_data = mutex_data;
    network->philos = philos;
    return(network);
}



t_network *create_network(int *params)
{
    t_philo         **philos;
    t_network       *network;
	t_mutex_data    *mutex_data;
	long long       *meal_board;

    meal_board = get_meal_board(params[P]);
    if(!meal_board)
        return(NULL);
    mutex_data = init_mutex_struct(params[P]);
    if(!mutex_data)
        return(NULL);
    philos = init_philos(params, mutex_data, &meal_board);
    if(!philos)
        return(ft_destroy_mutex_struct(&mutex_data, params[P]));
    network = build_network(mutex_data, philos, params, &meal_board);
    if(!network)
    {
        ft_destroy_mutex_struct(&mutex_data, params[P]);
        return(ft_destroy_philos(&philos, params[P]));
    }
    return(network);
}
