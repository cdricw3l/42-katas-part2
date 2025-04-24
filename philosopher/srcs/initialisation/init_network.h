/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_network.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 06:06:24 by ast               #+#    #+#             */
/*   Updated: 2025/04/24 08:51:40 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_NETWORK_H
#define INIT_NETWORK_H

#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include <stdio.h>

#include "../../include/global.h"
#include "../thread/thread.h"

t_network       *create_network(int *params);
t_philo **init_philos(int *params, t_mutex_data *mutex_data, long long ***meal_board);

void            *ft_destroy_mutexs(t_mutex ***mutexs, int len);
t_mutex         **init_mutex(int n);
t_mutex_data    *init_mutex_struct(int n);

//utils
int	            init_atoi(const char *str);
long long       *get_time_board(int n);
long long       **get_time_multi_board(int n);
int             get_fork_number(t_philo *philo, int fork_number);
// Memory clean

void            *destroy_network(t_network **network);
void            *ft_destroy_philos(t_philo ***philos, int len);
void            *ft_destroy_mutex_struct(t_mutex_data **mutex_data, int len);
void            *ft_destroy_timeboard(long long ***time_board, int len);

#endif