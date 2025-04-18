/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_network.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 06:06:02 by ast               #+#    #+#             */
/*   Updated: 2025/04/18 14:38:42 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "init_network.h"

void *destroy_network(t_network **network)
{
    
}
t_network   *build_network(mutex_t **forks, mutex_t **pens, t_philo **philos, int n)
{
    t_network *network;

    network = malloc(sizeof(t_network) * 1);
    if(!network)
        return(NULL);
    network->last_meals = get_meal_board(n);
    if(!network->last_meals)
    {
        free(network);
        return(NULL);
    }
    network->forks = forks;
    network->pens = pens;
    network->philos = philos;
    network->n = n;
    return(network);
}

t_network *create_network(int *params)
{
	mutex_t     **forks;
	mutex_t     **pens;
    t_philo     **philos;
    t_network   *network;

    forks = init_mutex(params[P]);
    if(!forks)
        return(NULL);
    pens = init_mutex(params[P]);
    if(!pens)
        return(ft_destroy_mutexs(&forks, params[P]));
    philos = init_philos(params, forks, pens);
    if(!philos)
    {
        ft_destroy_mutexs(&forks, params[P]);
        return(ft_destroy_mutexs(&pens, params[P]));
    }
    network = build_network(forks, pens, philos, params[P]);
    if(!network)
    {
        ft_destroy_mutexs(&forks, params[P]);
        ft_destroy_mutexs(&pens, params[P]);
        return(ft_destroy_philos(&philos, params[P]));
    }
    return(network);
}
