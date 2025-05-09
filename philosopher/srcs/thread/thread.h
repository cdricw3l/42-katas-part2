/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 04:36:08 by ast               #+#    #+#             */
/*   Updated: 2025/05/09 13:56:36 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
#define THREAD_H

#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>

#include "../initialisation/init_network.h"

#define TS_SIZE_ARR 6

#define TS_CYCLE        0
#define TS_START        1
#define TS_LAST_EAT     2
#define TS_END_THINK    3
#define TS_END_EAT      4
#define TS_END_SPLEEP   5

#define TAKEN_FORK      0
#define EATING          1
#define RELEASE_FORK    3
#define SLEEPING        2
#define THINKING        3


long long   get_current_time(void);
int         run_simulation(t_network **network);

void        *thread_monitor(void *p);

int         start_philo(t_network **net);
int         kill_philos(t_network **net);

int         monitor_launcher(t_network **network, pthread_t *monitiror);
int         monitor_joiner(pthread_t *monitiror);

void        *thread_philo(void *p);
void        *thread_philo_cycle(void *p);
void        *thread_philo_infinit(void *p);

int         get_state(t_philo *philo, int state_type);
int         change_state(t_philo *philo, int state_type, int state);
int         philos_laucher(t_network **net, pthread_t threads[200]);
int         philos_joiner(t_network **net, pthread_t threads[200]);

int         run_philo(pthread_t threads[200], t_network **net);

// tempo

void        ft_temporisation(int ms, long long start);
int         put_timestamp(t_philo *philo, int type, long long start);
long long   get_timestamp(t_philo *philo, int time);
int         check_timestamp(t_philo **philo, int n);


// fork

int         get_forks(t_philo *philo, long long timestamps);
//int         get_fork_number(t_philo *philo, int fork_number);

int         release_forks(t_philo *philo, long long timestamps);

void        display_philo_time_board(t_philo *philo, int mode);
void        display_all_philo_time_board(t_philo **philo, int mode);

int        safe_print(long long timestamp,t_philo *philo, int action);

#endif