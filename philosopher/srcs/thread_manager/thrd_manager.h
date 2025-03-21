/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_manager.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:14:49 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/03/21 12:33:57 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include "../petri_network/network/ptri_network.h"
#include "../../include/global.h"

typedef pthread_mutex_t mutex;

typedef struct s_thread_data
{
    int ttd;
    int tte;
    int tts;
    
} s_thread_data;


typedef struct s_philosophe
{
    int             id;
    pthread_mutex_t *fork;
    t_petri_network *network;
    
}   t_philosophe;

int                 ft_destroy_mutext(mutex fork[N], int idx);
pthread_mutex_t     *ft_create_arr_mutext(int n);

#endif