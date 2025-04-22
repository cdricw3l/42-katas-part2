/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:43:07 by ast               #+#    #+#             */
/*   Updated: 2025/04/21 15:00:44 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"

#define MODE_INTERVAL   0
#define MODE_TIME_ST    1

char *get_column_name(int i)
{
    if(i == TS_CYCLE)
        return("Cycle: ");
    if (i == TS_THINK)
        return("End Think: ");
    if (i == TS_START)
        return("Start: ");
    if (i == TS_EAT)
        return("End Eat: ");
    if (i == TS_SPLEEP)
        return("End sleep: ");
    return("");
}

void display_philo_time_board(t_philo *philo, int mode)
{
    TEST_START;
    int i;
    long long **time_board;

    i = 0;
    time_board = philo->time_data;
    if(!time_board)
        return ;
    printf("Philosopher\t %d\n\n", philo->pametres[ID]);
    while (i < philo->pametres[P])
    {
        if(i == 0)
            printf("%s\t\t %lld\n", get_column_name(i) ,time_board[i][philo->pametres[ID]]);
        else
        {
            if(mode == MODE_INTERVAL)
                printf("%s\t\t %lld\n", get_column_name(i) ,time_board[i][philo->pametres[ID]] - time_board[TS_START][philo->pametres[ID]]);
            else
                printf("%s\t\t %lld\n", get_column_name(i) ,time_board[i][philo->pametres[ID]]);
        }
        printf("\n");
        i++;
    }
    TEST_SUCCES;
}

void        display_all_philo_time_board(t_philo **philo, int mode)
{
    int i;

    i = 0;
    if(!philo || mode < 0 || mode > 1)
        return;
    while (i < philo[0]->pametres[P])
    {
        display_philo_time_board(philo[i], mode);
        i++;
    }
}
