/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_network.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 06:06:02 by ast               #+#    #+#             */
/*   Updated: 2025/04/19 21:23:03 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "init_network.h"

void *destroy_network(t_network **network)
{
    TEST_START;
    ft_destroy_mutexs(&(*network)->forks, (*network)->n);
    ft_destroy_mutexs(&(*network)->pens, (*network)->n);
    ft_destroy_mutexs(&(*network)->m_states, (*network)->n);
    ft_destroy_philos(&(*network)->philos, (*network)->n);
    free((*network)->last_meals);
    (*network)->last_meals = NULL;
    free(*network);
    *network = NULL;
    return(NULL);
} 

static int *get_meal_board(int n)
{
    int *meal_board;
    int i;

    if(n < 0)
        return(NULL);
    i = 0;
    meal_board = malloc(sizeof(int) * n);
    if(!meal_board)
        return (NULL);
    while (i < n)
    {
        meal_board[i] = 0;
        i++;
    }
    return(meal_board);
}
static t_network   *build_network(t_mutex **forks, t_mutex **pens, t_mutex **m_states, t_philo **philos, int *params)
{
    t_network *network;

    network = malloc(sizeof(t_network) * 1);
    if(!network)
        return(NULL);
    network->last_meals = get_meal_board(params[P]);
    if(!network->last_meals)
    {
        free(network);
        return(NULL);
    }
    network->forks = forks;
    network->pens = pens;
    network->m_states = m_states;
    network->philos = philos;
    network->n = params[P];
    network->cycle = params[CYCLE];
    return(network);
}

t_network *create_network(int *params)
{
	t_mutex     **forks;
	t_mutex     **pens;
	t_mutex     **m_states;
    t_philo     **philos;
    t_network   *network;

    forks = init_mutex(params[P]);
    if(!forks)
        return(NULL);
    pens = init_mutex(params[P]);
    if(!pens)
        return(ft_destroy_mutexs(&forks, params[P]));
    m_states = init_mutex(params[P]);
    if(!m_states)
    {
        ft_destroy_mutexs(&forks, params[P]);
        return(ft_destroy_mutexs(&pens, params[P]));
    }
    philos = init_philos(params, forks, pens, m_states);
    if(!philos)
    {
        ft_destroy_mutexs(&forks, params[P]);
        ft_destroy_mutexs(&pens, params[P]);
        return(ft_destroy_mutexs(&m_states, params[P]));
    }
    network = build_network(forks, pens, m_states, philos, params);
    if(!network)
    {
        ft_destroy_mutexs(&forks, params[P]);
        ft_destroy_mutexs(&pens, params[P]);
        ft_destroy_mutexs(&m_states, params[P]);
        return(ft_destroy_philos(&philos, params[P]));
    }
    return(network);
}
