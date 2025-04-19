/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 04:36:08 by ast               #+#    #+#             */
/*   Updated: 2025/04/19 20:26:20 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef THREAD_H
#define THREAD_H

#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>

#define DEBUGG printf("DEBUGG\n");
#define PRINT_INT(msg) printf("\x1b[31m" "DEBBUG  INT " "%d\n", msg);
#define PSTR(msg) printf("\x1b[31m" "DEBBUG  str >>> " "%s\n", msg);
#define PPTR(msg) printf("\x1b[31m" "DEBBUG  de pointeur: >>> "  "%p\n" "\x1b[0m", msg);
#define DEBUGG printf("DEBUGG\n");
#define TEST_START printf("\033[0;33m" "\nInitiating function test: %s\n" "\x1b[0m", __func__);
#define TEST_SUCCES printf("\033[0;32m" "\nFunction: %s executed successfully.\n" "\x1b[0m", __func__);

typedef pthread_mutex_t t_mutex;

#define P 0
#define TTD 1
#define TTE 2
#define TTS 3
#define CYCLE 4

#define ON 1
#define OFF 0

typedef  struct  s_philo
{
    int     id;
    int     tte;
    int     tts;
    int     state_1;  // on - off
    int     death_state;  // on - off
    int     cycle;
    int     *meal_time_data;
    int     fork_id_1;
    int     fork_id_2;
    
    t_mutex  *pen;
    t_mutex  *fork_1;
    t_mutex  *fork_2;
    t_mutex  *m_states;

} t_philo;


typedef  struct  s_network
{
    int     n;
    int     cycle;
    t_mutex **pens;
    t_mutex **m_states;
    t_mutex **forks;
    t_philo **philos;
    int     *last_meals;

} t_network;

//tempo

long long get_current_time(void);
int run_simulation(t_network **network);


void    *thread_monitor(void *p);

int     start_philo(t_network **net);
int     kill_philos(t_network **net);

int     monitor_launcher(t_network **network, pthread_t *monitiror);
int     monitor_joiner(pthread_t *monitiror);

void    *thread_philo(void *p);
void    *thread_philo_cycle(void *p);
void    *thread_philo_infinit(void *p);

int     get_state(t_philo *philo, int state_type);
int     change_state(t_philo *philo, int state_type, int state);
int     philos_laucher(t_network **net, pthread_t threads[200]);
int     philos_joiner(t_network **net, pthread_t threads[200]);

int     run_philo(pthread_t threads[200], t_network **net);
#endif