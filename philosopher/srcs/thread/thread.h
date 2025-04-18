/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 04:36:08 by ast               #+#    #+#             */
/*   Updated: 2025/04/18 06:50:47 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef THREAD_H
#define THREAD_H

#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

typedef pthread_mutex_t mutex_t;

#define P 0
#define TTD 1
#define TTE 2
#define TTS 3
#define CYCLE 3

typedef  struct  s_philo
{
    int id;
    int state;  // on - off
    int cycle;
    
    mutex_t  *pen;
    mutex_t  *fork_1;
    mutex_t  *fork_2;

    long long   tte;
    long long   tts;

    
    long long   *meal_time_data;

} t_philo;

typedef  struct  s_monitoring
{
    int n;
    
    t_philo     **philosophes;
    long long   *last_meals;

} t_monitoring;

typedef  struct  s_network
{
    mutex_t         **forks;
    mutex_t         **pens;
    t_philo    **philosophes;

} t_network;

//tempo

long long get_current_time(void);

#endif