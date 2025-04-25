/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_initialisation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:40:45 by cw3l              #+#    #+#             */
/*   Updated: 2025/04/25 22:13:28 by ast              ###   ########.fr       */
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
    int				arr_args[6];
    t_philo         **philo;
    t_mutex_data    *mutex_data;
    long long       **meal;

    arr_args[P] = 5;
    arr_args[TTD] = 800;
    arr_args[TTE] = 300;
    arr_args[TTS] = 300;
    arr_args[CYCLE] = 300;

    mutex_data = malloc(sizeof(t_mutex_data));
    if(!mutex_data)
        return(0);
    mutex_data->forks = init_mutex(arr_args[P]);
    mutex_data->pens = init_mutex(arr_args[P]);
    mutex_data->m_states = init_mutex(arr_args[P]);
    meal = get_time_multi_board(arr_args[P]);
    if(!mutex_data->forks || !mutex_data->m_states || !mutex_data->pens)
    {
        free(mutex_data);
        return(1);
    }
    philo = init_philos(arr_args,mutex_data,&meal);
    if(!philo)
        return(1);
    ft_destroy_mutex_struct(&mutex_data, arr_args[P]);
    ft_destroy_philos(&philo, arr_args[P]);
    ft_destroy_timeboard(&meal,arr_args[P]);
    return (1);
}

int tst_init_network(void)
{
    TEST_START;


    t_network   *network;
    int		    arr_args[6];
    int         i;

    arr_args[P] = 5;
    arr_args[TTD] = 800;
    arr_args[TTE] = 300;
    arr_args[TTS] = 300;
    arr_args[CYCLE] = 300;
    

    
    network = create_network(arr_args);
    if(!network)
        return(0);
    i = 0;
    while (i < arr_args[P])
    {
        printf("voici i %d\n", i);
        assert(network->time_board[i] == 0);
        assert(network->philos[i]);
        assert(network->mutex_data->forks[i]);
        assert(network->mutex_data->pens[i]);
        assert(network->mutex_data->m_states[i]);
        i++;
    }
    destroy_network(&network);
    TEST_SUCCES;
    return (1);
}