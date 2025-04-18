/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 04:36:08 by ast               #+#    #+#             */
/*   Updated: 2025/04/18 19:39:30 by ast              ###   ########.fr       */
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

#define ON 1
#define OFF 0

typedef  struct  s_philo
{
    int     id;
    int     tte;
    int     tts;
    int     state;  // on - off
    int     cycle;
    int     *meal_time_data;
    
    mutex_t  *pen;
    mutex_t  *fork_1;
    mutex_t  *fork_2;

} t_philo;


typedef  struct  s_network
{
    int     n;
    mutex_t **pens;
    mutex_t **forks;
    t_philo **philos;
    int     *last_meals;

} t_network;

//tempo

long long get_current_time(void);

#endif