/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_timestamp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:21:23 by ast               #+#    #+#             */
/*   Updated: 2025/04/21 14:53:36 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tst_unit.h"

int tst_timestamp(void)
{

    long long **time_board;
    t_philo *philo;
    t_mutex *pen;
    
    philo = malloc(sizeof(t_philo) * 1);
    pen = malloc(sizeof(t_mutex) * 1);
    if(!philo || !pen)
        return(1);
    pthread_mutex_init(pen, NULL);
    time_board = get_time_board(5);
    philo->time_data = time_board;
    philo->pametres[P] = 5;
    philo->pametres[ID] = 0;
    philo->pametres[TTE] = 300;
    philo->pametres[TTS] = 300;
    philo->pen = pen;
    assert(time_board);
    put_timestamp(philo, TS_CYCLE);
    put_timestamp(philo, TS_START);
    ft_temporisation(philo->pametres[TTE], get_current_time());
    put_timestamp(philo, TS_THINK);
    ft_temporisation(philo->pametres[TTE], get_current_time());
    put_timestamp(philo, TS_EAT);
    ft_temporisation(philo->pametres[TTS], get_current_time());
    put_timestamp(philo, TS_SPLEEP);
    display_philo_time_board(philo, 0);

    ft_destroy_timeboard(&time_board, 5);
    return(1);
}