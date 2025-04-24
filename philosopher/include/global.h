/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:38:02 by cw3l              #+#    #+#             */
/*   Updated: 2025/04/24 08:45:49 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
#define GLOBAL_H

#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>



#define DEBUGG printf("DEBUGG\n");
#define PRINT_INT(msg) printf("\x1b[31m" "DEBBUG  INT " "%d\n", msg);
#define PSTR(msg) printf("\x1b[31m" "DEBBUG  str >>> " "%s\n", msg);
#define PPTR(msg) printf("\x1b[31m" "DEBBUG  de pointeur: >>> "  "%p\n" "\x1b[0m", msg);
#define DEBUGG printf("DEBUGG\n");
#define TEST_START printf("\033[0;33m" "\nInitiating function test: %s\n" "\x1b[0m", __func__);
#define TEST_SUCCES printf("\033[0;32m" "\nFunction: %s executed successfully.\n" "\x1b[0m", __func__);


#define ON 1
#define OFF 0

#define MIN_P    2      /*minimum number of philosophe*/
#define MAX_P    200      /*minimum number of philosophe*/
#define MIN_TTD  60   /*minimum time to die*/
#define MIN_TTE  60   /*minimum time to eat*/
#define MIN_TTS  60   /*minimum time to spleep*/
#define CYCLE_NB    100    /* number of cycle */

#define P 0
#define TTD 1
#define TTE 2
#define TTS 3
#define CYCLE 4
#define ID 5
#define STATE_1 6
#define STATE_2 7

#define ON 1
#define OFF 0

typedef pthread_mutex_t t_mutex;

typedef  struct  s_mutex_data
{
    t_mutex **pens;
    t_mutex **m_states;
    t_mutex **forks;
    
} t_mutex_data;


typedef  struct  s_philo
{

    int             pametres[8];
    
    t_mutex         *fork_1;
    t_mutex         *fork_2;
    t_mutex         *pen;
    t_mutex         *m_state;
    long long       *time_data;

} t_philo;


typedef  struct  s_network
{
    int             pametres[8];
    long long       **time_board;
    t_mutex_data    *mutex_data;
    t_philo         **philos;

} t_network;



int	*ft_init_and_check_argument(char **argv, int len);

#endif