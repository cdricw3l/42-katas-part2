/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 04:36:08 by ast               #+#    #+#             */
/*   Updated: 2025/04/18 21:27:20 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef THREAD_H
#define THREAD_H

#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

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
    int     state;  // on - off
    int     cycle;
    int     *meal_time_data;
    int     fork_id_1;
    int     fork_id_2;
    
    t_mutex  *pen;
    t_mutex  *fork_1;
    t_mutex  *fork_2;

} t_philo;


typedef  struct  s_network
{
    int     n;
    t_mutex **pens;
    t_mutex **forks;
    t_philo **philos;
    int     *last_meals;

} t_network;

//tempo

long long get_current_time(void);

#endif