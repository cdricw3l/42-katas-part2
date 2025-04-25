/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:43:07 by ast               #+#    #+#             */
/*   Updated: 2025/04/24 08:56:53 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_network.h"

void init_params_philo(t_philo **phil, int *params, int id)
{
    t_philo *philo;
    
    philo = *phil;
    philo->pametres[P] = params[P];
    philo->pametres[TTD] = params[TTD];
    philo->pametres[TTE] = params[TTE];
    philo->pametres[TTS] = params[TTS];
    philo->pametres[CYCLE] = params[CYCLE];
    philo->pametres[ID] = id;
    philo->pametres[STATE_1] = OFF;
    philo->pametres[STATE_2] = -1;
}

static t_philo *create_philo(t_mutex_data *mutex_data, long long ***time_board, int id, int *params)
{
    t_philo *philo;

    philo = malloc(sizeof(t_philo) * 1);
    if(!philo)
        return(NULL);
    init_params_philo(&philo, params, id);
    philo->time_data = *time_board[id];
    philo->fork_1 = mutex_data->forks[get_fork_number(philo, 1)];
    philo->fork_2 = mutex_data->forks[get_fork_number(philo, 2)];
    philo->pen = mutex_data->pens[id];
    philo->m_state = mutex_data->m_states[id];
    return(philo);
}

t_philo **init_philos(int *params, t_mutex_data *mutex_data, long long ***meal_board)
{
    int         i;
    t_philo     **philos;

    i = 0;
    philos = malloc(sizeof(t_philo *) * params[P]);
    if(!philos || !meal_board)
        return(NULL);
    while (i < params[P])
    {
        philos[i] = create_philo(mutex_data, meal_board ,i, params);
        if(!philos[i])
            return(ft_destroy_philos(&philos, i));
        i++;
    }       
    return(philos); 
}
