/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_network.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 06:06:24 by ast               #+#    #+#             */
/*   Updated: 2025/04/18 21:05:50 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef INIT_NETWORK_H
#define INIT_NETWORK_H

#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include <stdio.h>

#include "../thread/thread.h"


#define MIN_P    2      /*minimum number of philosophe*/
#define MAX_P    200      /*minimum number of philosophe*/
#define MIN_TTD  60   /*minimum time to die*/
#define MIN_TTE  60   /*minimum time to eat*/
#define MIN_TTS  60   /*minimum time to spleep*/
#define CYCLE_NB    100    /* number of cycle */

#define DEBUGG printf("DEBUGG\n");
#define PRINT_INT(msg) printf("\x1b[31m" "DEBBUG  INT " "%d\n", msg);
#define PSTR(msg) printf("\x1b[31m" "DEBBUG  str >>> " "%s\n", msg);
#define PPTR(msg) printf("\x1b[31m" "DEBBUG  de pointeur: >>> "  "%p\n" "\x1b[0m", msg);
#define DEBUGG printf("DEBUGG\n");
#define TEST_START printf("\033[0;33m" "\nInitiating function test: %s\n" "\x1b[0m", __func__);
#define TEST_SUCCES printf("\033[0;32m" "\nFunction: %s executed successfully.\n" "\x1b[0m", __func__);


t_network   *create_network(int *params);
void        *destroy_network(t_network **network);

t_philo     **init_philos(int *params, t_mutex **forks, t_mutex **pens);
void        *ft_destroy_philos(t_philo ***philos, int len);

t_mutex     **init_mutex(int n);
void        *ft_destroy_mutexs(t_mutex ***mutexs, int len);

int	        init_atoi(const char *str);
#endif