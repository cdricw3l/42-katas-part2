/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_manager.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:14:49 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/03/23 00:52:44 by cw3l             ###   ########.fr       */
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
    int             transitions_set[3];
    int             places_set[4];
    pthread_mutex_t **fork;
    t_petri_network *network;
    
}   t_philosophe;

t_philosophe        **ft_create_philosophe(int n, pthread_mutex_t **fork, t_petri_network *network);
void                *ft_clean_philosophe(t_philosophe **philosophes, int idx);
void                ft_get_transition_set(int id, int trs[3]);
int                 ft_plug_philosophe_together(t_petri_network *network);
int                 ft_destroy_mutext(pthread_mutex_t ***fork, int idx);
pthread_mutex_t     **ft_create_arr_mutext(int n);
int                 ft_timer(int ms);
void                *ft_kill_philosophes_and_network(t_philosophe ***philosophes, t_petri_network **network, pthread_mutex_t **forks ,int idx);

//display
void                ft_display_philophes(t_philosophe **philosophes);
void                ft_print_places_set(t_philosophe *philosophe);
void                ft_print_philosophe_state(t_philosophe *philosophe);
void                ft_print_transitions_set(t_philosophe *philosophe);

#endif