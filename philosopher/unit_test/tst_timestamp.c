/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_timestamp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:21:23 by ast               #+#    #+#             */
/*   Updated: 2025/04/30 12:12:16 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "tst_unit.h"

int _timestamp(void)
{
    TEST_START;
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
    philo->pametres[STATE_1] = 1;
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
        usleep(500000);

        put_timestamp(philo, TS_END_THINK, start);
        
        printf("\033[0;32m" "Time increase befort eating %lld\n" "\x1b[0m", philo->time_data[TS_END_THINK] - philo->time_data[TS_LAST_EAT]);
        usleep(500000);

        put_timestamp(philo, TS_END_EAT, start);
        last_eat = philo->time_data[TS_END_EAT];
        usleep(500000);

        put_timestamp(philo, TS_END_SPLEEP, start);
        display_philo_time_board(philo, 1);
        i++;
    }
    
    free(time_board);
    TEST_SUCCES;
    return(1);
}

int tst_timestamp(void)
{
    //_timestamp();

    char file_name[] = "hello.txt";
    int fd = open(file_name, O_WRONLY | O_CREAT, 0777 |O_APPEND);
    
    if(fd == -1)
        printf("errerur\n");
    
    int j = 0;
    while (j < 10)
    {
        write(fd,"hello\n",6);
        j++;
    }
    


    return(1);

}