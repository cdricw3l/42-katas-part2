/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_network.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 06:06:02 by ast               #+#    #+#             */
/*   Updated: 2025/04/24 08:57:05 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_network.h"

void init_params_monitor(int *monitor_param, int *params)
{
    monitor_param[P] = params[P];
    monitor_param[TTD] = params[TTD];
    monitor_param[TTE] = params[TTE];
    monitor_param[TTS] = params[TTS];
    monitor_param[CYCLE] = params[CYCLE];
}

static t_network   *build_network(t_mutex_data *mutex_data, t_philo **philos, int *params, long long ***time_board)
{
    t_network *network;

    network = malloc(sizeof(t_network) * 1);
    if(!network)
        return(NULL);
    network->time_board = *time_board;
    if(!network->time_board)
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
	long long       **time_board;

    time_board = get_time_multi_board(TS_SIZE_ARR);
    if(!time_board)
        return(NULL);
    mutex_data = init_mutex_struct(params[P]);
    if(!mutex_data)
        return(NULL);
    philos = init_philos(params, mutex_data, &time_board);
    if(!philos)
        return(ft_destroy_mutex_struct(&mutex_data, params[P]));
    network = build_network(mutex_data, philos, params, &time_board);
    if(!network)
    {
        ft_destroy_mutex_struct(&mutex_data, params[P]);
        return(ft_destroy_philos(&philos, params[P]));
    }
    return(network);
}
