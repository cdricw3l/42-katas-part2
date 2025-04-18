/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_run_philosophes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 00:23:43 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/25 22:05:59 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thrd_manager.h"

void ft_change_state_philosophes(t_philosophe *philosophe)
{
   
    if(pthread_mutex_lock(philosophe->fork[philosophe->network->n]))
        printf("lock error \n");

    philosophe->state[philosophe->id] = DEAD;
    
    if(pthread_mutex_unlock(philosophe->fork[philosophe->network->n]))
        printf("--> Unlock error by\n");
    printf("Philosophe %d Die\n", philosophe->id);
}

int ft_check_state_philosophes(t_philosophe *philosophe)
{
    
    int alive;

    if(pthread_mutex_lock(philosophe->fork[philosophe->network->n]))
        printf("lock error \n");

    alive = ft_are_all_alive(philosophe);

    if(pthread_mutex_unlock(philosophe->fork[philosophe->network->n]))
        printf("--> Unlock error by\n");
    
    return(alive);
}