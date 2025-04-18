/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_manager.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:14:49 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/03/25 22:06:35 by cw3l             ###   ########.fr       */
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


#define ALIVE 0
#define DEAD 1

typedef struct s_tempo_data
{
    int tte;
    int tts;
    int ttd;
    int cycle;
    
} t_tempo_data;

typedef struct s_philosophe
{
    int             id;
    int             *state;
    int             places_set[4];
    int             transitions_set[3];
    t_tempo_data    tempo;
    pthread_mutex_t **fork;
    t_petri_network *network;
    
}   t_philosophe;

t_philosophe        **ft_create_philosophe(int n, pthread_mutex_t **fork, t_petri_network *network, t_tempo_data tempo);
void                *ft_clean_philosophe(t_philosophe **philosophes, int idx);
void                ft_get_transition_set(int id, int trs[3]);
void                ft_plug_philosophe_together(t_petri_network *network);
int                 ft_destroy_mutext(pthread_mutex_t ***fork, int idx);
pthread_mutex_t     **ft_create_arr_mutext(int n);
int                 ft_timer(int ms);
void                *ft_kill_philosophes_and_network(t_philosophe ***philosophes, t_petri_network **network, pthread_mutex_t ***forks ,int idx);

//display
void                ft_display_philophes(t_philosophe **philosophes);
void                ft_print_places_set(t_philosophe *philosophe);
void                ft_print_philosophe_state(t_philosophe *philosophe);
void                ft_print_transitions_set(t_philosophe *philosophe);
int                 get_fork_number(t_philosophe *philosophe, int num_fork);
int                 run_simulation(t_philosophe **philosophes, int n);
int                 ft_are_all_alive(t_philosophe *philosophe);

// fork managment

void                ft_philo_eat(t_philosophe *philosophe);
void                ft_philo_take_fork_2(t_philosophe *philosophe);
void                ft_philo_take_fork_1(t_philosophe *philosophe);
void                ft_philo_release_fork_1(t_philosophe *philosophe);
void                ft_philo_release_fork_2(t_philosophe *philosophe);

int                ft_check_state_philosophes(t_philosophe *philosophe);
void               ft_change_state_philosophes(t_philosophe *philosophe);

#endif