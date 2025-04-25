/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_timestamp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:21:23 by ast               #+#    #+#             */
/*   Updated: 2025/04/25 18:21:11 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tst_unit.h"

int tst_timestamp(void)
{

    long long *time_board;
    t_philo *philo;
    t_mutex *pen;
    int i;
    long long start;
    long long last_eat;

    
    philo = malloc(sizeof(t_philo) * 1);
    pen = malloc(sizeof(t_mutex) * 1);
    if(!philo || !pen)
        return(1);
    pthread_mutex_init(pen, NULL);
    time_board = get_time_board(TS_SIZE_ARR);
    philo->time_data = time_board;
    philo->pametres[P] = 5;
    philo->pametres[ID] = 0;
    philo->pametres[TTE] = 300;
    philo->pametres[TTS] = 300;
    philo->pametres[TTD] = 800;
    philo->pen = pen;
    assert(time_board);
    
    i = 0;
    start = get_current_time();
    last_eat = 0;
    while (i < 10 && philo->pametres[STATE_1])
    {
        put_timestamp(philo, TS_CYCLE,start);
        put_timestamp(philo, TS_START, start);

        philo->time_data[TS_LAST_EAT] = last_eat;
        ft_temporisation(philo->pametres[TTE], get_current_time());
        put_timestamp(philo, TS_END_THINK, start);
        if(philo->time_data[TS_END_THINK] - philo->time_data[TS_LAST_EAT] > philo->pametres[TTD] && i != 1)
        {
            printf("fonction will ending %lld and %d\n", philo->time_data[TS_END_THINK] - philo->time_data[TS_LAST_EAT], philo->pametres[TTD]);
            philo->pametres[STATE_1] = 0;
            display_philo_time_board(philo, 1);
            return(1);
        }
        printf("\033[0;32m" "Time increase befort eating %lld\n" "\x1b[0m", philo->time_data[TS_END_THINK] - philo->time_data[TS_LAST_EAT]);
        ft_temporisation(philo->pametres[TTE], get_current_time());
        put_timestamp(philo, TS_END_EAT, start);
        last_eat = philo->time_data[TS_END_EAT];
        ft_temporisation(philo->pametres[TTS], get_current_time());
        put_timestamp(philo, TS_END_SPLEEP, start);
        display_philo_time_board(philo, 1);
        i++;
    }
    
    free(time_board);
    return(1);
}