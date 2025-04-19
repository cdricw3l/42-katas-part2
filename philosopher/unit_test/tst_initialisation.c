/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_initialisation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:40:45 by cw3l              #+#    #+#             */
/*   Updated: 2025/04/19 18:25:29 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "tst_unit.h"

int tst_ft_init_arr_arg(void)
{
    TEST_START;
    int  *arr_args;
    
    char *philosopher = strdup("+3");
    char *time_to_spleep = strdup("1000");
    char *time_to_eat = strdup("1000");
    char *time_to_die = strdup("1000");
    char *cycle = strdup("100");

    char **argv= malloc(sizeof(char *) * 5);
    assert(argv);
    
    argv[0] = philosopher;
    argv[1] = time_to_spleep;
    argv[2] = time_to_eat;
    argv[3] = time_to_die;
    argv[4] = cycle;
    
    arr_args = ft_init_and_check_argument(argv,5);
    assert(arr_args);
    assert(arr_args[0] == 3 && arr_args[1] == 1000 &&
        arr_args[2] == 1000 && arr_args[3] == 1000 && arr_args[4] == 100);
    
    free(arr_args);
    free(time_to_spleep);
    
    time_to_spleep = strdup("-1000");
    argv[1] = time_to_spleep;
    arr_args = ft_init_and_check_argument(argv,5);
    assert(!arr_args);
    
    free(arr_args);
    free(time_to_spleep);
    
    time_to_spleep = strdup("");
    argv[1] = time_to_spleep;
    arr_args = ft_init_and_check_argument(argv,5);
    assert(!arr_args);
    
    free(arr_args);
    free(time_to_die);
    free(time_to_eat);
    free(cycle);
    free(time_to_spleep);
    
    free(argv[0]);
    free(argv);
    TEST_SUCCES;

    return(1);
}

int tst_init_fork_and_pen(void)
{
    TEST_START;
    
    t_mutex **forks;
    int     n;
    int     i;
    
    n = 5;
    i = 0;
    forks = init_mutex(0);
    assert(!forks);
    forks = init_mutex(n);
    assert(forks);

    while (i < n)
    {
        assert(!pthread_mutex_lock(forks[i]));
        assert(!pthread_mutex_unlock(forks[i]));
        i++;
    }

    ft_destroy_mutexs(&forks, n);
    TEST_SUCCES;
    return(1);
}

int tst_init_philos(void)
{
    TEST_START;

    t_philo **philos;
    t_mutex **forks;
    t_mutex **pens;
    t_mutex **m_states;
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
    params[CYCLE] = -1;
    
    pens = init_mutex(params[P]);
    if(!pens)
    {
        free(params);
        return(0);
    }
    forks = init_mutex(params[P]);
    if(!forks)
    {
        ft_destroy_mutexs(&pens, params[P]);
        free(params);
        return(0);
    }
    m_states = init_mutex(params[P]);
    if(!m_states)
    {
        ft_destroy_mutexs(&pens, params[P]);
        ft_destroy_mutexs(&forks, params[P]);
        free(params);
        return(0);
    }
    philos = init_philos(params, forks, pens,m_states);
    if(!philos)
    {
        ft_destroy_mutexs(&forks, params[P]);
        ft_destroy_mutexs(&pens, params[P]);
        free(params);
        return(0);
    }
    i = 0;
    assert(params[P] == 5);
    while (i < params[P])
    {
        assert(!philos[i]->meal_time_data);
        assert(philos[i]->tte == params[TTE]);
        assert(philos[i]->tts == params[TTS]);
        assert(philos[i]->cycle == -1);
        assert(philos[i]->id  == i);
        assert(philos[i]->fork_1);
        assert(philos[i]->fork_2);
        assert(philos[i]->m_states);
        assert(philos[i]->pen);
        if(i == 0)
        {
            assert(philos[i]->fork_id_1 == i);
            assert(philos[i]->fork_id_2 == params[P] - 1);
        }
        else
        {
            assert(philos[i]->fork_id_1 == i - 1);
            assert(philos[i]->fork_id_2 == i);
        }
        printf("voici %d\n",i);
        i++;
    }
    ft_destroy_philos(&philos,params[P]);
    ft_destroy_mutexs(&forks,params[P]);
    ft_destroy_mutexs(&pens,params[P]);
    ft_destroy_mutexs(&m_states,params[P]);
    free(params);
    TEST_SUCCES;
    return (1);
}

int tst_init_network(void)
{
    TEST_START;


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
    params[CYCLE] = -1;
    network = create_network(params);
    if(!network)
    {
        free(params);
        return(0);
    }
    i = 0;
    while (i < params[P])
    {
        printf("voici i %d\n", i);
        assert(network->last_meals[i] == 0);
        assert(network->philos[i]);
        assert(network->forks[i]);
        assert(network->pens[i]);
        assert(network->m_states[i]);
        i++;
    }
    free(params);
    destroy_network(&network);
    TEST_SUCCES;

    return (1);
}