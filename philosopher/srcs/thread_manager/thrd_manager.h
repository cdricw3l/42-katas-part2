/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_manager.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:14:49 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/03/23 19:41:42 by cw3l             ###   ########.fr       */
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


#define alive 1
#define dead 1

typedef struct s_philosophe
{
    int             id;
    int             places_set[4];
    int             transitions_set[3];
    pthread_mutex_t **fork;
    t_petri_network *network;
    
}   t_philosophe;

t_philosophe        **ft_create_philosophe(int n, pthread_mutex_t **fork, t_petri_network *network);
void                *ft_clean_philosophe(t_philosophe **philosophes, int idx);
void                ft_get_transition_set(int id, int trs[3]);
void                ft_plug_philosophe_together(t_petri_network *network);
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