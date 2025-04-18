/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_network.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 06:06:24 by ast               #+#    #+#             */
/*   Updated: 2025/04/18 20:17:25 by ast              ###   ########.fr       */
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


t_network   *create_network(int *params);
void        *destroy_network(t_network **network);

t_philo     **init_philos(int *params, mutex_t **forks, mutex_t **pens);
void        *ft_destroy_philos(t_philo ***philos, int len);

mutex_t     **init_mutex(int n);
void        *ft_destroy_mutexs(mutex_t ***mutexs, int len);

int	        init_atoi(const char *str);
#endif