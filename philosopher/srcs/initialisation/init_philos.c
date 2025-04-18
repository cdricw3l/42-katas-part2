/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:43:07 by ast               #+#    #+#             */
/*   Updated: 2025/04/18 21:20:26 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "init_network.h"

void *ft_destroy_philos(t_philo ***philos, int len)
{
    int i;
    t_philo **p;

    i = 0;
    p = *philos;
    while (i < len)
    {
        free(p[i]);
        p[i] = NULL;
        i++;
    }
    free(*philos);
    return(NULL);
}

static t_philo *create_philo(t_mutex **forks, t_mutex **pens, int id, int n_philo)
{
    t_philo *philo;

    philo = malloc(sizeof(t_philo) * 1);
    if(!philo)
        return(NULL);
    philo->id = id;
    philo->state = OFF;
    philo->meal_time_data = NULL;
    if(id == 0)
    {
        philo->fork_id_1 = id;
        philo->fork_id_2 = n_philo - 1;
        philo->fork_1 = forks[id];
        philo->fork_2 = forks[n_philo - 1];
    }
    else
    {
        philo->fork_id_1 = id - 1; 
        philo->fork_id_2 = id; 
        philo->fork_1 = forks[id - 1]; 
        philo->fork_2 = forks[id]; 
    }
    philo->pen = pens[id];
    return(philo);
}

t_philo **init_philos(int *params, t_mutex **forks, t_mutex **pens)
{
    int     i;
    t_philo **philos;

    i = 0;
    philos = malloc(sizeof(t_philo *) * params[P]);
    if(!philos)
        return(NULL);
    while (i < params[P])
    {
        philos[i] = create_philo(forks,pens,i, params[P]);
        if(!philos[i])
            return(ft_destroy_philos(&philos, i));
        philos[i]->tte = params[TTE];
        philos[i]->tts = params[TTS];
        philos[i]->cycle = params[CYCLE];
        i++;
    }       
    return(philos); 
}
